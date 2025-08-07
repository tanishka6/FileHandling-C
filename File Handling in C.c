#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fptr;//file pointer
	char data[100];
	//1.create the file
	fptr=fopen("myfile.txt","w");//create/opens file in write mode
	if (fptr==NULL)
	{
	printf("Error creating file!\n");
	return 1;
	}
	printf("File created successfully.\n");
	
	//2.write to the file
	printf("Enter data to write to the file:");
	fgets(data, sizeof(data), stdin);//takes input
	fputs(data, fptr);//write to file
	fclose(fptr);//close file after writing
	printf("Data written successfully.\n");
	
	//3.append to the file
	fptr=fopen("myfile.txt", "a");//opens file for appending
	if(fptr==NULL)
	{
		printf("Error opening file for appending:\n");
		return 1;
	}
	printf("Enter data to append to the file:\n");
	fgets(data, sizeof(data), stdin);//take input again
	fputs(data, fptr);//append to file
	fclose(fptr);//close file after appending
	printf("Data appended successfully.\n");
	
	//4.Read the file
	fptr= fopen("myfile.txt", "r");//opens file for reading
	if(fptr==NULL)
	{
		printf("Error opening file for reading:\n");
		return 1;
	}
	printf("Final content of the file:\n");
	while(fgets(data, sizeof(data),fptr)!=NULL)
	{
		printf("%s",data);//print each line from file
	}
	fclose(fptr);//final close
	
	return 0;
}
