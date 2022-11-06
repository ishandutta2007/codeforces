#include <iostream>
#include <cstdio>
#include <string>
using namespace std; 
int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}; 
int main()
{
	string str; 
	bool f = false; 
	int lst = 1000000000; 
	for (int i = 0; i < 15; i++)
	{
		printf("%d\n", arr[i]);
		fflush(stdout); 
		cin >> str; 
		if (str == "yes")
		{
			if (f)
			{
				printf("composite\n");
				fflush(stdout); 
				return 0; 
			}
			f = true; 
			lst = arr[i]; 
		}
	}
	if (lst < 10)
	{
		printf("%d\n", lst * lst);
		fflush(stdout); 
		cin >> str; 
		printf("%s\n", str == "yes" ? "composite" : "prime");
	}
	else
		printf("prime\n");
	fflush(stdout); 
	return 0; 
}