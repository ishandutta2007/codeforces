#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x)(x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,i,j,k,dis[185][185],cst[185],dp[185][185],ans[185];
vector<long long> bi[185];
void dfs1(long long x,long long fa)
{
	ff(bi[x],it)
	{
		if (*it==fa) continue;
		dfs1(*it,x);
	}
	fz1(i,n)
	{
		dp[x][i]=cst[dis[i][x]];
		ff(bi[x],it)
		{
			if (*it==fa) continue;
			dp[x][i]+=min(dp[*it][i],dp[*it][ans[*it]]+m);
		}
		if (!ans[x]||dp[x][i]<dp[x][ans[x]]) ans[x]=i;
	}
}
void dfs2(long long x,long long fa)
{
	ff(bi[x],it)
	{
		if (*it==fa) continue;
		if (dp[*it][ans[x]]<m+dp[*it][ans[*it]])
		{
			dp[*it][ans[*it]]=dp[*it][ans[x]]-m;
			ans[*it]=ans[x];
		}
		dfs2(*it,x);
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	fz1(i,n-1)
	{
		scanf("%lld",&cst[i]);
	}
	memset(dis,15,sizeof(dis));
	fz1(i,n) dis[i][i]=0;
	fz1(i,n-1)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
		dis[x][y]=dis[y][x]=1;
	}
	fz1(k,n)fz1(i,n)fz1(j,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]); 
	dfs1(1,0);
	dfs2(1,0);
	printf("%lld\n",dp[1][ans[1]]+m);
	fz1(i,n) printf("%lld ",ans[i]);
	return 0;
}