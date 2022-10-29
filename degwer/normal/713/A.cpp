#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dat[1048576];
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		char c;
		scanf(" %c", &c);
		string s;
		cin >> s;
		int t = 0;
		for (int i = 0; i < s.size(); i++)
		{
			t *= 2;
			t += (s[i] - '0') % 2;
		}
		if (c == '+')dat[t]++;
		if (c == '-')dat[t]--;
		if (c == '?')printf("%d\n", dat[t]);
	}
}