#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,lc[5000000],rc[5000000],sum[5000000],A,B,tot,rt;
long long cost[5000000];
void add(int &k,int l,int r,int p)
{
	if(!k)k=++tot;
	++sum[k];
	if(l==r)return ;
	if(p<=(l+r>>1))add(lc[k],l,l+r>>1,p);
	else add(rc[k],(l+r>>1)+1,r,p);
}
void solve(int k,int l,int r)
{
	if(l==r)
	{
		cost[k]=1ll*B*sum[k];
		return ;
	}
	if(!lc[k])cost[k]+=A;
	else solve(lc[k],l,l+r>>1),cost[k]+=cost[lc[k]];
	if(!rc[k])cost[k]+=A;
	else solve(rc[k],(l+r>>1)+1,r),cost[k]+=cost[rc[k]];
	cost[k]=min(cost[k],1ll*B*sum[k]*(r-l+1));
}
int main()
{
	scanf("%d %d %d %d",&n,&m,&A,&B);
	int x;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&x);
		add(rt,1,1<<n,x);
	}
	solve(1,1,1<<n);
	printf("%I64d",cost[1]);
	return 0;
}