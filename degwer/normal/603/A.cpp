#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	string s;
	cin >> s;
	int d00 = 0, d01 = 0, d02 = 0;
	int d10 = 0, d11 = 0, d12 = 0;
	for (int i = 0; i < num; i++)
	{
		if (s[i] == '0')
		{
			d02 = max(d02, max(d12 + 1, d01 + 1));
			d01 = max(d01, max(d11 + 1, d00 + 1));
			d00 = max(d00, d10 + 1);
		}
		else
		{
			d12 = max(d12, max(d02 + 1, d11 + 1));
			d11 = max(d11, max(d01 + 1, d10 + 1));
			d10 = max(d10, d00 + 1);
		}
	}
	printf("%d\n", max(max(max(d00, d01), d02), max(max(d10, d11), d12)));
}