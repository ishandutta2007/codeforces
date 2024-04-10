#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int startk[2002];
	int endk[2002];
	str="."+str+",";
	fill(startk,startk+2002,0);
	fill(endk,endk+2002,0);
	for(int i=1;i<=str.size()-2;i++)
	{
		for(int j=0;;j++)
		{
			startk[i-j]++;
			endk[i+j]++;
			if(str[i-j-1]!=str[i+j+1])
			{
				break;
			}
		}
	}
	for(int k=1;k<=str.size()-3;k++)
	{
		if(str[k]!=str[k+1])
		{
			continue;
		}
		for(int l=0;;l++)
		{
			startk[k-l]++;
			endk[k+1+l]++;
			if(str[k-l-1]!=str[k+l+2])
			{
				break;
			}
		}
	}
	long long sum=0;
	for(int m=1;m<=str.size()-2;m++)
	{
		for(int n=m+1;n<=str.size()-2;n++)
		{
			sum+=endk[m]*startk[n];
		}
	}
	printf("%I64d\n",sum);
}