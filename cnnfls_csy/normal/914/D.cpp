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
int n,m,i,j,a[500005],op,l,r,x,y,t;
struct seg
{
	struct ii
	{
		int l,r,s;
	}tr[2000005];
	void build(int x,int l,int r)
	{
		tr[x].l=l;
		tr[x].r=r;
		if (l==r) {tr[x].s=tr[x].s=a[l];return;}
		build(x*2,l,(l+r)/2);
		build(x*2+1,(l+r)/2+1,r);
		pushup(x);
	}
	void pushup(int x)
	{
		tr[x].s=__gcd(tr[x*2].s,tr[x*2+1].s);
	}
	void update(int x,int y,int c)
	{
		if (tr[x].l>y||tr[x].r<y) return;
		if (tr[x].l==tr[x].r) {tr[x].s=c;return;}
		update(x*2,y,c);update(x*2+1,y,c);
		pushup(x);
	}
	int query(int x,int l,int r)
	{
		if (tr[x].l>r||tr[x].r<l) return 0;
		if (tr[x].l>=l&&tr[x].r<=r)
		{
			return tr[x].s;
		}
		return __gcd(query(x*2,l,r),query(x*2+1,l,r));
	}
	bool query2(int x,int l,int y)
	{
		if (tr[x].r<l) return 1;
		if (tr[x].l==tr[x].r)
		{
			if (tr[x].s%y==0)
			{
				t=max(t,tr[x].r);
				return 1;
			}
			return 0;
		}
		if (tr[x].l>=l)
		{
			if (tr[x*2].s%y==0)
			{
				t=max(t,tr[x*2].r);
				return query2(x*2+1,l,y);
			}
			return query2(x*2,l,y);
		}
		if (query2(x*2,l,y)) return query2(x*2+1,l,y); return 0;
	}
}tr;
int main()
{
	scanf("%d",&n);
	fz1(i,n)
	{
		scanf("%d",&a[i]);
	}
	tr.build(1,1,n);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d",&op);
		if (op==1)
		{
			scanf("%d%d%d",&l,&r,&x);
			t=l-1;
			tr.query2(1,l,x);//cerr<<endl;
//			cerr<<t<<endl;
			if (t+2>r||tr.query(1,t+2,r)%x==0)
			{
				puts("YES");
			}
			else puts("NO");
		}
		else
		{
			scanf("%d%d",&x,&y);
			tr.update(1,x,y);
		}
	}
	return 0;
}