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
struct splay_tree
{
	struct ii
	{
		int l,r,s,sz,mx,ss,fa;
	}tr[100005];
	int cnt,rt;
	void pushup(int x)
	{
		tr[0].mx=-1<<30;
		tr[x].sz=tr[tr[x].l].sz+tr[tr[x].r].sz+1;
		tr[x].mx=max(tr[x].ss,max(tr[tr[x].l].mx,tr[tr[x].r].mx));
	}
	void rot(int x,int &k)
	{
		int y=tr[x].fa;
		int z=tr[y].fa;
		if (y==k) k=x; else if (tr[z].l==y) tr[z].l=x; else tr[z].r=x;
		if (tr[y].l==x)
		{
			tr[y].l=tr[x].r;
			tr[tr[y].l].fa=y;
			tr[x].r=y;
		}
		else
		{
			tr[y].r=tr[x].l;
			tr[tr[y].r].fa=y;
			tr[x].l=y;
		}
		tr[x].fa=z;
		tr[y].fa=x;
		pushup(x);pushup(y);
	}
	void splay(int x,int &k)
	{
		while (k!=x)
		{
			int y=tr[x].fa;
			int z=tr[y].fa;
			if (y==k)
			{
				rot(x,k);
				return;
			}
			if ((tr[y].l==x)==(tr[z].l==y))
			{
				rot(y,k);
			}
			else
			{
				rot(x,k);
			}
			rot(x,k);
		}
	}
	int nwnd(int x,int id,int fa)
	{
		tr[++cnt]=(ii){0,0,id,1,x,x,fa};
		return cnt;
	}
	int ins(int x,int &k,int a,int b,int fa,int id)
	{
		if (x==0)
		{
			return nwnd(a,id,fa);
		}
		if (a<tr[tr[x].r].mx||b<tr[tr[x].r].sz||a<tr[x].ss)
		{
			tr[x].r=ins(tr[x].r,rt,a,b,x,id);
			pushup(x);
			return x;
		}
		else
		{
			tr[x].l=ins(tr[x].l,rt,a,b-tr[tr[x].r].sz-1,x,id);
			pushup(x);
			return x;
		}
	}
	void print(int x)
	{
		if (!x) return;
		print(tr[x].l);
		if (tr[x].s) printf("%d ",tr[x].s);
		print(tr[x].r);
	}
}tr;
int n,m,i,j,x,y,rt;
int main()
{
	scanf("%d",&n);
	tr.cnt=0;rt=1;
	tr.nwnd(1<<30,0,0);
	tr.nwnd(-1,0,1);
	tr.tr[1].r=2;
	for (i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		tr.ins(rt,rt,x,y,0,i);
		tr.splay(tr.cnt,rt);
	}
	tr.print(rt);
	return 0;
}