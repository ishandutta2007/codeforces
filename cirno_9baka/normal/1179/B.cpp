#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=998244353;
const int N=1000005;
int n,m,q,i,j;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=n/2;i++)
		for(j=1;j<=m;j++)
		{
			printf("%d %d\n",i,j);
			printf("%d %d\n",n-i+1,m-j+1);
		}
	if(n%2==1)
	{
		for(i=1;i<=m/2;i++)
		{
			printf("%d %d\n",n/2+1,i);
			printf("%d %d\n",n/2+1,m-i+1);
		}
		if(m%2==1)
			printf("%d %d",n/2+1,m/2+1);
	}
}