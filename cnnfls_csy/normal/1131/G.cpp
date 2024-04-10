#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
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
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
int n,m,i,j,q,fa[10000005],fr[10000005],to[10000005],a[10000005],stk[10000005],tp,tot;
long long c[10000005],dp[10000005],stv[10000005];
vector<int> sa[250005],sc[250005];
int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
int main()
{
	scanf("%d%d",&n,&m);
	fzin
	{
		int x,y;
		scanf("%d",&x); 
		fz1(j,x)
		{
			scanf("%d",&y);
			sa[i].push_back(y);
		}
		while (x--)
		{
			scanf("%d",&y);
			sc[i].push_back(y);
		}
	}
	scanf("%d",&m);
	fzim
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int mem=tot;
		ff(sa[x],it)
		{
			a[++tot]=*it;
		}
		tot=mem;
		ff(sc[x],it)
		{
			c[++tot]=1ll*(*it)*y;
		}
	}
	m=tot;
	fzim fa[i]=i;
	fzjm
	{
		for (i=fnd(j);i>0&&i>j-a[j];i--)
		{
			i=fnd(i);
			fa[fnd(j)]=i; 
		}
		fr[j]=fnd(j);
	}
	fzim fa[i]=i;
	fd1(j,m)
	{
		for (i=fnd(j);i<=m&&i<j+a[j];i++)
		{
			i=fnd(i);
			fa[fnd(j)]=i; 
		}
		to[j]=fnd(j);
	}
	fz1(i,m)
	{
		while (tp>0&&stk[tp]<i) tp--;
		while (tp>0&&stk[tp]<=to[i]&&stv[tp]>=dp[i-1]+c[i]) tp--;
		if (tp==0||stv[tp]>dp[i-1]+c[i]) {tp++;stk[tp]=to[i];stv[tp]=dp[i-1]+c[i];}
		if (tp>0) dp[i]=stv[tp]; else dp[i]=1ll<<60;
		dp[i]=min(dp[i],dp[fr[i]-1]+c[i]);
	}
	printf("%I64d\n",dp[m]);
	return 0;
}