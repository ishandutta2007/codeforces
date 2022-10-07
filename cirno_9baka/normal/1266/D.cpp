#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=600005,M=998244353;
int n,m,i,j,u,v,p[N],q[N],k1,k2,k;
long long a[300005],d;
struct str{
	int u,v;
	long long d;
}e[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d %lld",&u,&v,&d);
		a[u]+=d;
		a[v]-=d;
	}
	for(i=1;i<=n;++i)
		if(a[i]>0)
			p[++k1]=i;
		else
			q[++k2]=i;
	for(i=1,j=1;i<=k1&&j<=k2;)
		if(a[p[i]]>-a[q[j]])
		{
			a[p[i]]+=a[q[j]];
			if(a[q[j]]) 
				e[++k]=(str){p[i],q[j],-a[q[j]]};
			++j;
		}
		else
		{
			a[q[j]]+=a[p[i]];
			if(a[p[i]])
				e[++k]=(str){p[i],q[j],a[p[i]]};
			++i;
		}
	printf("%d\n",k);
	for(i=1;i<=k;++i)
		printf("%d %d %lld\n",e[i].u,e[i].v,e[i].d);
}