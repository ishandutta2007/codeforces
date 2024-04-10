#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	string s;
	cin >> s;
	int pt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			pt = i + 1;
			break;
		}
	}
	int end = s.size() - 1;
	bool fl = false;
	for (int i = pt; i < s.size(); i++)
	{
		if (s[i] >= '5')
		{
			for (int j = i; j >= pt; j--)
			{
				if (gen == 0)break;
				if (s[j] >= '5')s[j] = '0', gen--;
				else break;
				if (s[j - 1] != '.')
				{
					s[j - 1]++;
					end = j - 1;
				}
				else
				{
					fl = true;
				}
			}
			break;
		}
	}
	if (fl)
	{
		bool fff = false;
		s[pt - 2]++;
		for (int i = pt - 2; i >= 0; i--)
		{
			if (s[i] == '9' + 1)
			{
				s[i] = '0';
				if (i != 0)s[i - 1]++;
				else fff = true;
			}
		}
		if (fff)printf("1");
		for (int i = 0; i < pt - 1; i++)printf("%c", s[i]);
		printf("\n");
	}
	else
	{
		for (int i = 0; i <= pt; i++)printf("%c", s[i]);
		for (int i = pt + 1; i <= end; i++)printf("%c", s[i]);
		printf("\n");
	}
}