#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int now = 0;
	int cnt = 0;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (str[i] == '(')now--;
		else now++;
		if (str[i] == '#')break;
		if (now < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	now = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')now++;
		else now--;
		if (str[i] == '#')cnt++;
		if (now < 0)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 0; i < cnt - 1; i++)printf("1\n");
	printf("%d\n", now + 1);
}