#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
long long n,i,m,k,p[1000005],l,ans;
int main()
{
	cin>>n>>m>>k;
	l=1;
	for(i=1;i<=m;i++)
	{
		scanf("%I64d",&p[i]);
		if((p[l]-(l-1)-1)/k!=(p[i]-(l-1)-1)/k)
		{
			l=i;
			ans++;
		}
	}
	cout<<ans+1;
}