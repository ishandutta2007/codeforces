#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cassert>
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
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
struct ii
{
	long long l,r,sum,suf;
}tr[4000005];
void pushup(int x)
{
	tr[x].sum=tr[x*2].sum+tr[x*2+1].sum;
	tr[x].suf=max(tr[x*2+1].suf,tr[x*2].suf+tr[x*2+1].sum);
}
void build(long long x,long long l,long long r)
{
	tr[x].l=l;
	tr[x].r=r;
	if (l==r)
	{
		tr[x].sum=tr[x].suf=-1;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void update(long long x,long long y,long long c)
{
	if (tr[x].l>y||tr[x].r<y) return;
	if (tr[x].l==tr[x].r)
	{
		tr[x].sum+=c;
		tr[x].suf+=c;
		return;
	}
	update(x*2,y,c);
	update(x*2+1,y,c);
	pushup(x);
}
pair<long long,long long> query(long long x,long long r)
{
	if (tr[x].r<=r)
	{
		return make_pair(tr[x].sum,tr[x].suf);
	}
	long long mid=(tr[x].l+tr[x].r)/2;
	if (mid>=r)
	{
		return query(x*2,r);
	}
	else
	{
		pair<long long,long long> t1=query(x*2,r);
		pair<long long,long long> t2=query(x*2+1,r);
		pair<long long,long long> t3;
		t3.first=t1.first+t2.first;
		t3.second=max(t2.second,t1.second+t2.first);
		return t3;
	}
}
long long n,m,i,j,t[1000005],d[1000005],x,y;
char op;
int main()
{
	scanf("%I64d",&n);
	build(1,1,1000000);
	fz1(i,n)
	{
		scanf(" %c",&op);
		if (op=='+')
		{
			scanf("%I64d%I64d",&t[i],&d[i]);
			update(1,t[i],d[i]);
		}
		else if (op=='-')
		{
			scanf("%I64d",&x);
			update(1,t[x],-d[x]);
		}
		else if (op=='?')
		{
			scanf("%I64d",&x);
			printf("%I64d\n",query(1,x).second+1);
		}
	}
	return 0;
}