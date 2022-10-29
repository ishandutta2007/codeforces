#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n;
	string t, s;
	cin >> n >> t >> s;
	if (s[0] == 'w')
	{
		if (n == 5 || n == 6)printf("53\n");
		else printf("52\n");
	}
	else
	{
		if (n <= 29)printf("12\n");
		else if (n <= 30)printf("11\n");
		else printf("7\n");
	}
}