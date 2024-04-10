#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int p=1000000007;
	string str,str2;
	cin>>str;
	cin>>str2;
	int zen[5002];
	int kon[5002];
	fill(zen,zen+5002,0);
	int sum=0;
	for(int i=1;i<=str.size();i++)
	{
		fill(kon,kon+5002,0);
		int rui=0;
		for(int j=1;j<=str2.size();j++)
		{
			if(str2[j-1]==str[i-1])
			{
				kon[j]=rui+1;
			}
			rui+=zen[j];
			rui%=p;
		}
		for(int k=0;k<=str2.size()+1;k++)
		{
			zen[k]=kon[k];
			sum+=kon[k];
			sum%=p;
		}
	}
	printf("%d\n",sum);
}