#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	printf("+");
	for(int i = 0; i < 24; i++)
		printf("-");
	printf("+\n");
	printf("|");
	for(int i = 0; i < 11; i++)
	{
		if(i == 0)
			if(n > 0)
				printf("O.");
			else
				printf("#.");
		else
		{
			if(n > 4 + (i - 1) * 3)
				printf("O");
			else
				printf("#");
			printf(".");
		}
	}
	printf("|D|)\n|");
	for(int i = 0; i < 11; i++)
	{
		if(i == 0)
			if(n > 1)
				printf("O");
			else
				printf("#");
	 	else
	 	{
	 		if(n > 4 + (i - 1) * 3 + 1)
	 			printf("O");
	 		else
	 			printf("#");
	 	}
	 	printf(".");
	}
	printf("|.|\n|");
  if(n > 2)
  	printf("O");
  else
  	printf("#");
 	for(int i = 0; i < 23; i++)
 		printf(".");
 	printf("|\n|");
 	for(int i = 0; i < 11; i++)
 	{
 		if(i == 0)
 		{
 			if(n > 3)
 				printf("O");
 			else
 				printf("#");
 		}
 		else
 		{
 			if(n > 4 + (i - 1) * 3 + 2)
 				printf("O");
 			else
 				printf("#");
 		}
 		printf(".");
 	}
 	printf("|.|)\n+------------------------+");
	return 0;
}