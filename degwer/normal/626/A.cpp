#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int c = 0;
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j++)
		{
			int a = 0, b = 0;
			for (int k = i; k <= j; k++)
			{
				if (s[k] == 'U')a++;
				if (s[k] == 'D')a--;
				if (s[k] == 'R')b++;
				if (s[k] == 'L')b--;
			}
			if (a == 0 && b == 0)c++;
		}
	}
	printf("%d\n", c);
}