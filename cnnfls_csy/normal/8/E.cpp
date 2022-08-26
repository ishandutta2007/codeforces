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
long long n,m,i,j,dp[55][2][2],x,y,ans[55];
long long dfs(long long l,long long r,long long lim1,long long lim2)
{
	if (l>r) return 1;
	if (dp[l][lim1][lim2]!=-1) return dp[l][lim1][lim2];
	dp[l][lim1][lim2]=0;
	int i,j;
	fz0k(i,2) fz0k(j,2)
	{
		if (l==r&&i!=j) continue;
		if (ans[l]>-1&&ans[l]!=i) continue;
		if (ans[r]>-1&&ans[r]!=j) continue;
		if (i>j&&!lim1) continue;
		if (i>1-j&&!lim2) continue;
		dp[l][lim1][lim2]+=dfs(l+1,r-1,lim1||i<j,lim2||i<1-j);
	}
	return dp[l][lim1][lim2];
}
int main()
{
	cin>>n>>m;
	memset(dp,-1,sizeof(dp)); 
	memset(ans,-1,sizeof(ans)); 
//	cerr<<dfs(1,n,0,0)<<endl;
	if (dfs(1,n,0,0)<=m)
	{
		puts("-1");
		return 0;
	}
	x=1;y=1;
	for (i=1;i<=n;i++)
	{
		ans[i]=0;
		if (i==1) continue;
		memset(dp,-1,sizeof(dp));
		long long t=dfs(1,n,0,0);
		if (t<=m)
		{
			m-=t;
			ans[i]=1;
		}
	}
	fz1(i,n) cout<<ans[i];
	return 0;
}