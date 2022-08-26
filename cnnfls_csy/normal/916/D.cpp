#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,now,rt[100005],rt2[100005],mcnt,x;
map<string,int> mp;
string op,st;
char ss[25];
struct segtree
{
	int cnt;
	struct seg
	{
		int l,r,lch,rch,sum;
	}tr[12000005];
	void build(int x,int l,int r)
	{
		cnt=3;
		tr[1]={l,r,2,3,0};
		tr[2]={l,(l+r)/2,0,0,0};
		tr[3]={(l+r)/2+1,r,0,0,0};
	}
	void update(int x,int y,int z)
	{
		if (tr[x].l>y||tr[x].r<y) return;
		if (tr[x].l==tr[x].r)
		{
			tr[x].sum=z;
			return;
		}
		if (!(tr[x].l>y||(tr[x].l+tr[x].r)/2<y))
		{
			tr[++cnt]=tr[tr[x].lch];
			tr[cnt].l=tr[x].l;
			tr[cnt].r=(tr[x].l+tr[x].r)/2;
			tr[x].lch=cnt;
			update(tr[x].lch,y,z);
		}
		if (!((tr[x].l+tr[x].r)/2+1>y||tr[x].r<y))
		{
			tr[++cnt]=tr[tr[x].rch];
			tr[cnt].l=(tr[x].l+tr[x].r)/2+1;
			tr[cnt].r=tr[x].r;
			tr[x].rch=cnt;
			update(tr[x].rch,y,z);
		}
		tr[x].sum=tr[tr[x].lch].sum+tr[tr[x].rch].sum;
	}
	int query(int x,int y)
	{
		if (tr[x].r<y||tr[x].l>y) return 0;
		if (tr[x].l>=y&&tr[x].r<=y) return tr[x].sum;
		int ans=0;
		if (tr[x].lch) ans+=query(tr[x].lch,y);
		if (tr[x].rch) ans+=query(tr[x].rch,y);
		return ans;
	}
}tr1;
struct segtree2 
{
	int cnt;
	struct seg
	{
		int l,r,lch,rch,sum;
	}tr[12000005];
	void build(int x,int l,int r)
	{
		cnt=3;
		tr[1]={l,r,2,3,0};
		tr[2]={l,(l+r)/2,0,0,0};
		tr[3]={(l+r)/2+1,r,0,0,0};
	}
	void update(int x,int y,int z)
	{
		if (tr[x].l>y||tr[x].r<y) return;
		if (tr[x].l==tr[x].r)
		{
			tr[x].sum+=z;
			return;
		}
		if (!(tr[x].l>y||(tr[x].l+tr[x].r)/2<y))
		{
			tr[++cnt]=tr[tr[x].lch];
			tr[cnt].l=tr[x].l;
			tr[cnt].r=(tr[x].l+tr[x].r)/2;
			tr[x].lch=cnt;
			update(tr[x].lch,y,z);
		}
		if (!((tr[x].l+tr[x].r)/2+1>y||tr[x].r<y))
		{
			tr[++cnt]=tr[tr[x].rch];
			tr[cnt].l=(tr[x].l+tr[x].r)/2+1;
			tr[cnt].r=tr[x].r;
			tr[x].rch=cnt;
			update(tr[x].rch,y,z);
		}
		tr[x].sum=tr[tr[x].lch].sum+tr[tr[x].rch].sum;
	}
	int query(int x,int y)
	{
		if (tr[x].l>=y) return 0;
		if (tr[x].r<y) return tr[x].sum;
		int ans=0;
		if (tr[x].lch) ans+=query(tr[x].lch,y);
		if (tr[x].rch) ans+=query(tr[x].rch,y);
		return ans;
	}
}tr2;
int main()
{
	scanf("%d",&n);
	rt[0]=rt2[0]=1;
	tr1.build(0,1,1<<30);
	tr2.build(0,1,1<<30);
	for (i=1;i<=n;i++)
	{
		scanf("%s ",ss);
		op=ss;
		rt[i]=++tr1.cnt;
		tr1.tr[rt[i]]=tr1.tr[rt[i-1]];
		rt2[i]=++tr2.cnt;
		tr2.tr[rt2[i]]=tr2.tr[rt2[i-1]];
		if (op=="set")
		{
			scanf("%s %d",ss,&x);
			st=ss;
			if (!mp.count(st)) mp[st]=++mcnt;
			int ans=tr1.query(rt[i],mp[st]);
			if (ans) tr2.update(rt2[i],ans,-1);
			tr1.update(rt[i],mp[st],x);
			tr2.update(rt2[i],x,1);
		}
		if (op=="remove")
		{
			scanf("%s",ss);
			st=ss;
			if (!mp.count(st)) mp[st]=++mcnt;
			int ans=tr1.query(rt[i],mp[st]);
			if (ans) tr2.update(rt2[i],ans,-1);
			tr1.update(rt[i],mp[st],0);
		}
		if (op=="query")
		{
			scanf("%s",ss);
			st=ss;
			if (!mp.count(st)) mp[st]=++mcnt;
			int ans=tr1.query(rt[i],mp[st]);
			if (!ans)
			{
				puts("-1");
			}
			else
			{
				printf("%d\n",tr2.query(rt2[i],ans));
			}
			fflush(stdout);
		}
		if (op=="undo")
		{
			scanf("%d",&x);
			rt[i]=++tr1.cnt;
			tr1.tr[rt[i]]=tr1.tr[rt[i-1-x]];
			rt2[i]=++tr2.cnt;
			tr2.tr[rt2[i]]=tr2.tr[rt2[i-1-x]];
		}
	}
	return 0;
}