#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num, len;
	scanf("%d%d", &num, &len);
	string d[100];
	for (int i = 0; i < num; i++)
	{
		cin >> d[i];
	}
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		bool fl = true;
		for (int j = 0; j < num - 1; j++)
		{
			if (d[j][i] > d[j + 1][i])
			{
				bool f = false;
				for (int k = 0; k <= i - 1; k++)
				{
					if (d[j][k] < d[j + 1][k])f = true;
				}
				if (!f)
				{
					fl = false;
				}
			}
		}
		if (!fl)
		{
			ret++;
			for (int j = 0; j < num; j++)d[j][i] = 'a';
		}
	}
	printf("%d\n", ret);
}