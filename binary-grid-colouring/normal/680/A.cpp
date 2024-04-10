#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	int x,a[101]={0};
	int sum=0;
	int maxn=0;
	for(int i=0;i<5;i++)
	{
		cin>>x;
		sum+=x;
		a[x]++;
		if(a[x]>1)  // 
		maxn=max(maxn,x*min(a[x],3)); 
	}
	cout<<sum-maxn;
	return 0;
}