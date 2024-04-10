#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	char pt='a'-1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>pt+1)
		{
			printf("NO\n");
			return 0;
		}
		pt=max(pt,s[i]);
	}
	printf("YES\n");
}