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
long long n,m,i,j,rt[100005],cnt=1;
vector<int> all;
long long ans;
struct treap
{
	long long rnd,zhi,ls,rs,sz;
}tr[1000005];
void getsum(long long x)
{
	tr[x].sz=tr[tr[x].ls].sz+tr[tr[x].rs].sz+1;
}
void split(long long t,long long &x,long long &y,long long zhi)
{
	if (!t)
	{
		x=0;
		y=0;
		return;
	}
	if (zhi<=tr[t].zhi)
	{
		split(tr[t].ls,x,tr[t].ls,zhi);
		y=t;
	}
	else
	{
		split(tr[t].rs,tr[t].rs,y,zhi);
		x=t;
	}
	getsum(t);
}
void make(long long x,long long y,long long &z)
{
	if (!x||!y)
	{
		z=0;
		if (x) z=x;
		if (y) z=y;
		return;
	}
	if (tr[x].rnd>tr[y].rnd)
	{
		make(tr[x].rs,y,tr[x].rs);
		z=x;
	}
	else
	{
		make(x,tr[y].ls,tr[y].ls);
		z=y;
	}
	getsum(z);
}
void insert(long long &k,long long zhi)
{
	long long x,y,z;
	split(k,x,y,zhi);
	tr[cnt].zhi=zhi;
	tr[cnt].rnd=rand();
	z=cnt;
	cnt++;
	getsum(z);
	make(x,z,k);
	make(k,y,k);
}
void query(long long &k,long long x,long long y)
{
	long long t1,t2,t3,t4,t5;
	split(k,t1,t2,x-y);
	split(t2,t3,t4,x+y+1);
	ans+=tr[t3].sz;
	make(t1,t3,t5);
	make(t5,t4,k);
}
struct ii
{
	int x,r,q;
}a[100005];
bool cmp(ii x,ii y)
{
	return x.r>y.r;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].r,&a[i].q);
		all.push_back(a[i].q);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	sort(a+1,a+n+1,cmp);
	for (i=1;i<=n;i++)
	{
		a[i].q=lower_bound(all.begin(),all.end(),a[i].q)-all.begin();
		int t=a[i].q;
		while (t>=0&&abs(all[a[i].q]-all[t])<=m)
		{
			query(rt[t],a[i].x,a[i].r);
			t--;
		}
		t=a[i].q+1;
		while (t<all.size()&&abs(all[a[i].q]-all[t])<=m)
		{
			query(rt[t],a[i].x,a[i].r);
			t++;
		}
		insert(rt[a[i].q],a[i].x);
	}
	cout<<ans<<endl;
	return 0;
}