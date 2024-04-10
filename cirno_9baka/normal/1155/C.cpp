#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i,ans,m;
ll x[500005],g,p[500005];
ll gcd(ll a,ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%I64d",&x[i]);
	g=x[2]-x[1];
	for(i=3;i<=n;i++)
		g=gcd(g,x[i]-x[i-1]);
	for(i=1;i<=m;i++)
	{
		scanf("%I64d",&p[i]);
		if(g%p[i]==0)
		{
			printf("YES\n%I64d %d",x[1],i);
			return 0;
		}
	}
	printf("NO");
}