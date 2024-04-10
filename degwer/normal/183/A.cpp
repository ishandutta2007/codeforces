#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	int num;
	scanf("%d",&num);
	ll mx=1,my=1;
	for(int i=0;i<num;i++)
	{
		string str;
		cin>>str;
		if(str=="UR"||str=="DL")
		{
			mx++;
		}
		if(str=="UL"||str=="DR")
		{
			my++;
		}
		if(str=="ULDR")
		{
			mx++;
			my++;
		}
	}
	printf("%I64d\n",mx*my);
}