#include<bits/stdc++.h>
using namespace std;
const int N=1005,E=262144;
const int M=998244353;
const int V=499122177;
int i,n,m,a[505],t;
long long dp[505];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		for(i=1;(1<<i)<=n;++i)
			a[i]=(1<<i-1);
		a[i]=n-(1<<i-1)+1;
		int e=i;
		long long s=1;
		for(i=1;i<=e;++i)
			s=s*(a[i]+1)%m;
		cout<<((s-1)%m+m)%m<<endl;
	}
}