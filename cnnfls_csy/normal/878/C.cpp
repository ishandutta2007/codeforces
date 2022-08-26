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
int n,m,i,j;
struct ii
{
	int mx[15],mi[15],sz;
	bool operator < (const ii &x) const
	{
		int i;
		for (i=1;i<=m;i++)
		{
			if (mx[i]>x.mi[i]) return 0;
		}
		return 1;
	}
	bool operator > (const ii &x) const
	{
		int i;
		for (i=1;i<=m;i++)
		{
			if (mi[i]<x.mx[i]) return 0;
		}
		return 1;
	}
};
set<ii> s;
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n)
	{
		ii t;
		fz1(j,m)
		{
			scanf("%d",&t.mx[j]);
			t.mi[j]=t.mx[j];
		}
		t.sz=1;
		set<ii>::iterator lb=s.lower_bound(t),ub=s.upper_bound(t);
//		if (i==2) cerr<<(++lb==s.begin())<<endl;
//		cerr<<s.size()<<endl;
		for (set<ii>::iterator it=lb;it!=ub;it++)
		{
			t.sz+=it->sz;
			fz1(j,m)
			{
				t.mi[j]=min(t.mi[j],it->mi[j]);
				t.mx[j]=max(t.mx[j],it->mx[j]); 
			}
		}
		s.erase(lb,ub);
		s.insert(t);
//		ff(s,it) cerr<<it->sz<<' ';cerr<<endl;
		printf("%d\n",s.rbegin()->sz);
	}
	return 0;
}