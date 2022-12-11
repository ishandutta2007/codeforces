#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const long long inf=0x3f3f3f3f3f3f3f3f;
int n,K,nxt[100010],ans;
long long w[100010],g[100010],pre[100010],suf[100010];
int st[100010],tp;
vector<int>E[100010];
long long mip[400040],mxsuf[400040],mis[400040],ad[400040];
inline void pushdown(int k)
{
	ad[k<<1]+=ad[k],ad[k<<1|1]+=ad[k];
	mxsuf[k<<1]+=ad[k],mxsuf[k<<1|1]+=ad[k];
	mis[k<<1]+=ad[k],mis[k<<1|1]+=ad[k];
	ad[k]=0;
}
long long getmis(int k,int l,int r,long long w)
{
	if(l==r)return mip[k]+w;
	if(ad[k])pushdown(k);
	if(w>=mxsuf[k<<1])return min(mip[k<<1]+w,getmis(k<<1|1,(l+r>>1)+1,r,w));
	else return min(getmis(k<<1,l,l+r>>1,w),mis[k]);
}
void pushup(int k,int l,int r)
{
	mxsuf[k]=max(mxsuf[k<<1],mxsuf[k<<1|1]);
	mis[k]=getmis(k<<1|1,(l+r>>1)+1,r,mxsuf[k<<1]);
}
void build(int k,int l,int r)
{
	if(l==r)return mip[k]=-suf[l],mxsuf[k]=suf[l],void();
	build(k<<1,l,l+r>>1);
	build(k<<1|1,(l+r>>1)+1,r);
	pushup(k,l,r);mip[k]=min(mip[k<<1],mip[k<<1|1]);
}
void add(int k,int l,int r,int ll,int rr,long long w)
{
	if(l>rr||r<ll)return ;
	if(l>=ll&&r<=rr)return ad[k]+=w,mxsuf[k]+=w,mis[k]+=w,void();
	if(ad[k])pushdown(k);
	add(k<<1,l,l+r>>1,ll,rr,w);
	add(k<<1|1,(l+r>>1)+1,r,ll,rr,w);
	pushup(k,l,r);
}
int query(int k,int l,int r,long long w)
{
	if(l==r)return l;
	if(ad[k])pushdown(k);
	if(mip[k<<1|1]+w<=K)return query(k<<1|1,(l+r>>1)+1,r,w);
	return query(k<<1,l,l+r>>1,w);
}
int getans(int k,int l,int r,long long w)
{
	if(l==r)return mip[k]+w<=K?l:0;
	if(ad[k])pushdown(k);
	if(w>=mxsuf[k<<1])return max(mip[k<<1]+w<=K?query(k<<1,l,l+r>>1,w):0,getans(k<<1|1,(l+r>>1)+1,r,w));
	else
	{
		if(mis[k]<=K)return getans(k<<1|1,(l+r>>1)+1,r,mxsuf[k<<1]);
		else return getans(k<<1,l,l+r>>1,w);
	}
}
void print()
{
	for(int i=1;i<=5;++i)printf("%lld %lld %lld %lld\n",mip[i],mxsuf[i],mis[i],ad[i]);
}
void dfs(int v)
{
	st[++tp]=v;
	add(1,1,n,1,v-1,-inf);
	add(1,1,n,nxt[v]-1,n,pre[v-1]-pre[nxt[v]-1]);
	int l=1,r=tp,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(pre[v-1]-pre[st[mid]-1]>K)l=mid+1;
		else r=mid;
	}
	add(1,1,n,st[l-1],n,inf);
//	printf("%d:\n",v),print();
	ans=max(ans,getans(1,1,n,-inf)-v+1);
	add(1,1,n,st[l-1],n,-inf);
	add(1,1,n,1,v-1,inf);
	for(auto u:E[v])dfs(u);
	add(1,1,n,nxt[v]-1,n,pre[nxt[v]-1]-pre[v-1]);
	--tp;
}
int main()
{
	scanf("%d %d",&n,&K);
	for(int i=1;i<n;++i)scanf("%lld",&w[i]);w[n]=inf;
	for(int i=1;i<=n;++i)scanf("%lld",&g[i]);
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]+g[i]-w[i],suf[i]=suf[i-1]-w[i-1]+g[i];
	st[0]=n+1;
	for(int i=n;i;--i)
	{
		while(tp&&pre[st[tp]-1]>=pre[i-1])--tp;
		nxt[i]=st[tp];st[++tp]=i;
		E[nxt[i]].push_back(i);
	}
//	for(int i=1;i<=n;++i)printf("%d ",nxt[i]);printf("\n");
	build(1,1,n);
//	print();
	st[tp=1]=n+1;
	for(auto u:E[n+1])dfs(u);
	printf("%d",ans);
	return 0;
}