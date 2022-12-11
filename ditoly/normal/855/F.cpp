#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
#define MN 100000
unsigned int a[MN+5],b[MN+5],p;
int f(int x){return ~((x-1)>>31);}
int main()
{
	int n,t,l,r,k,i;long long ans=0;
	for(scanf("%d",&n);n--;)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(t==1)
		{
			scanf("%d",&k);p=k>0?k-1:-k-1;
			if(k>0)for(i=l;i<r;++i)a[i]=(a[i]-1<p?a[i]-1:p)+1;
			else for(i=l;i<r;++i)b[i]=(b[i]-1<p?b[i]-1:p)+1;
		}
		else{for(ans=0,i=l;i<r;++i)ans+=(a[i]+b[i])&f(a[i])&f(b[i]);printf("%I64d\n",ans);} 
	}
}