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
#define sqr(x) ((x)*(x))
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
long long n,m,k,i,j,f[100005],g[100005],ans1,ans2,ansid;
struct ii
{
	long long x,y,id;
}a[100005];
bool cmp1(ii x,ii y)
{
	if (x.y==y.y) return x.x<y.x;
	return x.y>y.y;
}
bool cmp2(ii x,ii y)
{
	return x.x>y.x;
}
bool cmp3(ii x,ii y)
{
	return x.y>y.y;
}
priority_queue<long long> pq;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	fz1(i,n)
	{
		scanf("%I64d%I64d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	fz1(i,n)
	{
		f[i]=f[i-1];
		pq.push(-a[i].x);
		f[i]+=a[i].x;
		if (pq.size()>k)
		{
			f[i]+=pq.top();
			pq.pop();
		}
	}
	while (!pq.empty()) pq.pop();
	fd1(i,n)
	{
		g[i]=g[i+1];
		pq.push(-a[i].y);
		g[i]+=a[i].y;
		if (pq.size()>m-k)
		{
			g[i]+=pq.top();
			pq.pop();
		}
	}
	ans1=-1;
	fz1(i,n) if (i>=k&&n-i>=m-k)
	{
		if (f[i]>ans1||(f[i]==ans1&&g[i]>ans2))
		{
			ans1=f[i];
			ans2=g[i];
			ansid=i;
		}
	}
	sort(a+1,a+ansid+1,cmp2);
	fz1(i,k) printf("%I64d ",a[i].id);
	sort(a+ansid+1,a+n+1,cmp3);
	fz(i,ansid+1,ansid+m-k) printf("%I64d ",a[i].id);
	return 0;
}