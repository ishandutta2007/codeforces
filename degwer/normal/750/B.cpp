#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main()
{
	int num;
	scanf("%d",&num);
	int now=0;
	for(int i=0;i<num;i++)
	{
		int n;
		string s;
		cin>>n>>s;
		if((now==0&&s[0]!='S')||(now==20000&&s[0]!='N'))
		{
			printf("NO\n");
			return 0;
		}
		if(s[0]=='N')now-=n;
		if(s[0]=='S')now+=n;
		if(now<0||now>20000)
		{
			printf("NO\n");
			return 0;
		}
	}
	if(now!=0)printf("NO\n");
	else printf("YES\n");
}