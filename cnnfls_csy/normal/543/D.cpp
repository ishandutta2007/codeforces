#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
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
long long n,m,i,j,dp1[200005][2],dp2[200005][2],x,y,mod=1e9+7;
vector<long long> bi[200005],pre[200005][2],suf[200005][2];
void merge(long long &x,long long &y,long long xx,long long yy)
{
	long long f1=y,f0=x;
	x=y=0;
	(x+=f0*xx)%=mod;
	(y+=f0*yy)%=mod;
	(y+=f1*xx)%=mod;
	(y+=f1*yy)%=mod;
}
void dfs1(long long x)
{
	dp1[x][0]=1;dp1[x][1]=0;
	ff(bi[x],it)
	{
		dfs1(*it);
		merge(dp1[x][0],dp1[x][1],dp1[*it][0],dp1[*it][1]);
		pre[x][0].push_back(dp1[x][0]);
		pre[x][1].push_back(dp1[x][1]);
	}
	dp1[x][0]=1;dp1[x][1]=0;
	for (vector<long long>::reverse_iterator it=bi[x].rbegin();it!=bi[x].rend();it++)
	{
		merge(dp1[x][0],dp1[x][1],dp1[*it][0],dp1[*it][1]);
		suf[x][0].push_back(dp1[x][0]);
		suf[x][1].push_back(dp1[x][1]);
	}
	reverse(suf[x][0].begin(),suf[x][0].end());
	reverse(suf[x][1].begin(),suf[x][1].end());
	(dp1[x][1]+=dp1[x][0])%=mod;
}
void dfs2(long long x)
{
	int i;
	for (i=0;i<bi[x].size();i++)
	{
		int y=bi[x][i];
		dp2[y][0]=dp2[x][0];
		dp2[y][1]=dp2[x][1];
		if (i>0) merge(dp2[y][0],dp2[y][1],pre[x][0][i-1],pre[x][1][i-1]);
		if (i<bi[x].size()-1) merge(dp2[y][0],dp2[y][1],suf[x][0][i+1],suf[x][1][i+1]);
		(dp2[y][1]+=dp2[y][0])%=mod;
	}
	for (i=0;i<bi[x].size();i++)
	{
		dfs2(bi[x][i]);
	}
}
int main()
{
	scanf("%I64d",&n);
	fz(i,2,n)
	{
		scanf("%I64d",&x);
		bi[x].push_back(i);
	}
	dfs1(1);
	dp2[1][0]=1;
	dfs2(1);
	fz1(i,n)
	{
		printf("%I64d ",dp1[i][1]*(dp2[i][0]+dp2[i][1])%mod);
	}
	return 0;
}