#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
const int N=100005,E=262144;
int n,m,i,j,t,k,s[500005],p[500005],ans[500005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	p[1]=1;
	for(i=1;i<=n;++i)
		for(j=i*2;j<=n;j+=i)
			p[j]=max(p[j],i);
	for(i=1;i<=n;++i)
		++s[p[i]];
	for(i=1;i<=n;++i)
		s[i]+=s[i-1];
	for(i=0;i<n;++i)
		for(j=s[i]+1;j<=s[i+1];++j)
			ans[j]=i+1;
	for(i=2;i<=n;++i)
		printf("%d ",ans[i]);
}