#include<bits/stdc++.h>
using namespace std;
const int N=150005,E=1000000;
int n,m,u,v,i,a[N],siz[N],vis[N];
vector<int> g[N];
long long ans=0;
void getsiz(int i,int fa)
{
	siz[i]=1;
	for(auto it:g[i])
		if(it!=fa&&!vis[it])
		{
			getsiz(it,i);
			siz[i]+=siz[it];
		}
}
int mn,mnn;
void getw(int i,int fa,int sz)
{
	int mx=0;
	for(auto it:g[i])
		if(it!=fa&&!vis[it])
		{
			getw(it,i,sz);
			mx=max(mx,siz[it]);
		}
	mx=max(mx,sz-siz[i]);
	if(mx<mn)
	{
		mn=mx;
		mnn=i;
	}
}
int wei(int i)
{
	mn=1<<30;
	getsiz(i,0);
	getw(i,0,siz[i]);
	return mnn;
}
struct str{
	long long k,b;
	long long cal(long long x)
	{
		return x*k+b;
	}
}tree[4000005];
vector<str> A[N],B[N];
void dfs2(int rr,int rt,int i,int fa,int dd,long long d,long long s1,long long s2)
{
	bool fl=true;
	for(auto it:g[i])
		if(it!=fa&&!vis[it])
		{
			fl=false;
			break;
		}
	if(fl)
	{
		A[rr].push_back({d-rt,s2});
		B[rr].push_back({dd+1,s1});
	}
	ans=max(ans,s2+d);
	for(auto it:g[i])
		if(it!=fa&&!vis[it])
			dfs2(rr,rt,it,i,dd+1,d+a[it],s1+a[it]+d,s2+1ll*a[it]*(dd+1));
}
void modify(int i,int l,int r,str x)
{
	int mid=l+r>>1;
	if(x.cal(mid)>tree[i].cal(mid))
		swap(x,tree[i]);
	long long xl=x.cal(l),tl=tree[i].cal(l);
	if(xl<=tl&&x.cal(r)<=tree[i].cal(r))
		return;
	if(xl>tl)
		modify(i<<1,l,mid,x);
	else
		modify(i<<1|1,mid+1,r,x);
}
long long Query(int i,int l,int r,int x)
{
	long long ans=0;
	while(l<r)
	{
		int mid=l+r>>1;
		if(tree[i].k==0&&tree[i].b==0)
			break;
		ans=max(ans,tree[i].cal(x));
		if(mid>=x)
			r=mid,i<<=1;
		else
			l=mid+1,i=i<<1|1;
	}
	return ans;
}
void Clear(int i,int l,int r)
{
	if(tree[i].k||tree[i].b)
		tree[i].k=tree[i].b=0;
	else
		return;
	if(l==r)
		return;
	int mid=l+r>>1;
	Clear(i<<1,l,mid);
	Clear(i<<1|1,mid+1,r);
}
void dfs(int i)
{
	for(auto it:g[i])
		if(!vis[it])
		{
			A[it].clear(),B[it].clear();
			dfs2(it,a[i],it,i,1,a[i]+a[it],a[i]*2+a[it],a[it]);
			for(auto ii:B[it])
				ans=max(ans,Query(1,0,E,ii.k)+ii.b);
			for(auto ii:A[it])
				modify(1,0,E,ii);
		}
	reverse(g[i].begin(),g[i].end());
	Clear(1,0,E);
	for(auto ii:g[i])
		if(!vis[ii])
		{
			for(auto it:B[ii])
				ans=max(ans,Query(1,0,E,it.k)+it.b);
			for(auto it:A[ii])
				modify(1,0,E,it);
		}
	Clear(1,0,E);
	vis[i]=1;
	for(auto it:g[i])
		if(!vis[it])
			dfs(wei(it));
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	dfs(wei(1));
	cout<<ans;
}