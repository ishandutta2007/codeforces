#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
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
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
long long n,m,i,j,mx=1e5,a[100005],b[100005],px[800005],py[800005],lc[800005],rc[800005],dp[100005],x,y,cnt,rt[100005];
vector<long long> bi[100005];
void update(long long &x,long long tl,long long tr,long long k,long long b)
{
	if (!x)
	{
		x=++cnt;
		px[x]=k;
		py[x]=b;
		return;
	}
	long long mid=(tl+tr)/2;
	if (px[x]*tl+py[x]>k*tl+b)
	{
		swap(px[x],k);
		swap(py[x],b);
	}
	if (tl==tr) return;
	if (px[x]*mid+py[x]>k*mid+b)
	{
		swap(px[x],k);
		swap(py[x],b);
		update(lc[x],tl,(tl+tr)/2,k,b);
	}
	else if (px[x]*tr+py[x]>k*tr+b)
	{
		update(rc[x],(tl+tr)/2+1,tr,k,b);
	}
}
long long query(long long x,long long tl,long long tr,long long k)
{
	if (x==0||tl>k||tr<k) return 1ll<<60;
	if (tl==tr) return px[x]*k+py[x];
	return min(px[x]*k+py[x],min(query(lc[x],tl,(tl+tr)/2,k),query(rc[x],(tl+tr)/2+1,tr,k)));
}
long long merge(long long x,long long y,long long tl,long long tr)
{
	if (!x||!y) return x+y;
	lc[x]=merge(lc[x],lc[y],tl,(tl+tr)/2);
	rc[x]=merge(rc[x],rc[y],(tl+tr)/2+1,tr);
	update(x,tl,tr,px[y],py[y]);
	return x;
}
void dfs(long long x,long long fa)
{
	ff(bi[x],it)
	{
		if (*it==fa) continue;
		dfs(*it,x);
		rt[x]=merge(rt[x],rt[*it],-mx,mx);
	}
	if (!rt[x]) dp[x]=0; else dp[x]=query(rt[x],-mx,mx,a[x]);
	update(rt[x],-mx,mx,b[x],dp[x]);
}
int main()
{
	scanf("%I64d",&n);
	fz1(i,n)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
	}
	fz1(i,n)
	{
		int x;
		scanf("%d",&x);
		b[i]=x;
	}
	fz1(i,n-1)
	{
		scanf("%I64d",&x);
		scanf("%I64d",&y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs(1,0);
	fz1(i,n)
	{
		printf("%I64d ",dp[i]);
	}
	return 0;
}