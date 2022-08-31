#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
int n,m,i,j,x,y,l,r,mid,ans,a[200005],cnt,dp[200005],sz[200005],sz2[200005],mx;
vector<int> bi[200005];
void dfs2(int x,int fa,int all1,int all2)
{
	int mx1=0,mx2=0;
	dp[x]=(a[x]>=mid);
	ff(bi[x],it) if (*it!=fa)
	{
		dfs2(*it,x,all1,all2);
		if (sz[*it]==sz2[*it])
		{
			dp[x]+=dp[*it];
			continue;
		}
		if (dp[*it]>mx2)
		{
			mx2=dp[*it];
		}
		if (mx2>mx1)
		{
			swap(mx2,mx1);
		}
	}
	if (a[x]<mid)
	{
		dp[x]=0;
		return;
	}
	dp[x]+=mx1;
	mx=max(mx,dp[x]+mx2);
	if (all1-sz[x]==all2-sz2[x])
	{
		mx=max(mx,dp[x]+mx2+all1-sz[x]);
	}
}
void dfs1(int x,int fa)
{
	sz[x]=1;sz2[x]=(a[x]>=mid);
	ff(bi[x],it) if (*it!=fa)
	{
		dfs1(*it,x);
		sz[x]+=sz[*it];
		sz2[x]+=sz2[*it];
	}
}
bool check(int x)
{
	int i;
	mx=0;
	dfs1(1,0);
	dfs2(1,0,sz[1],sz2[1]);
	return mx>=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n)
	{
		scanf("%d",&a[i]);
	}
	fz1(i,n-1)
	{
		scanf("%d%d",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	l=1;r=1000001;ans=0;
	while (l<r)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else r=mid;
	}
	cout<<ans<<endl;
	return 0;
}