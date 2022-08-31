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
int n,m,i,j,f[2005][2005],dp[2005][2005],mem;
char s[2005][2005];
string ans;
int main()
{
	scanf("%d%d",&n,&m);mem=m;
//	if (n>=1000) return -1;
	if (m>=n+n-1)
	{
		fz1(i,n+n-1)
		{
			putchar('a');
		}
		return 0;
	}
	fz1(i,n)
	{
		scanf(" ");
		fz1(j,n)
		{
			scanf("%c",&s[i][j]);
		}
	}
	dp[1][1]=0;
	fz1(i,n)
	{
		fz1(j,n)
		{
			if (i*j>1) dp[i][j]=1e9+7;
			if (i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if (j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]);
			dp[i][j]+=(s[i][j]!='a');
		}
	}
	int l;
	fz(l,2,n+n)
	{
		char mi='z'+1;
		bool ff=0,ss=0;
		f[1][1]=1;
		fz1(i,n)
		{
			j=l-i;
			if (j<1||j>n) continue;
			if (i>1&&f[i-1][j])
			{
				f[i][j]=1;
			}
			if (j>1&&f[i][j-1])
			{
				f[i][j]=1;
			}
			if (f[i][j])
			{
				ff=1;
				mi=min(mi,s[i][j]);
			}
			if (dp[i][j]<=mem) ss=1;
		}
		if (!ff) return -1;
		if (ss)
		{
			fz1(i,n)
			{
				j=l-i;
				if (j<1||j>n) continue;
				if (dp[i][j]>mem) f[i][j]=0;
			}ans+="a";
		}
		else
		{
			fz1(i,n)
			{
				j=l-i;
				if (j<1||j>n) continue;
				if (s[i][j]>mi) f[i][j]=0;
			}
		ans.push_back(mi);
		}
	}
	cout<<ans;
	return 0;
}