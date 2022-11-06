#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
char str[100005]; 
int main()
{
	// freopen("A.in", "r", stdin); 
	scanf("%s", str); 
	int n = strlen(str); 
	for (int i = 0; i < n; i++)
	{
		if (str[i] != 'a')
		{
			for (int j = i; j < n; j++)
			{
				if (str[j] == 'a')
					break; 
				str[j]--; 
			}
			printf("%s\n", str);
			return 0; 
		}
	}
	str[n - 1] = 'z'; 
	printf("%s\n", str);
	return 0; 
}