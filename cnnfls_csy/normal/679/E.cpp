#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);i<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);i>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long n,m,i,j,num[100005],x,y,op,z;
struct seg
{
	struct nd
	{
		long long l,r,mn,d,sme,add;
		void update(long long x)
		{
			mn-=x;
			add+=x;
			if (!sme) return;
			sme+=x;
			d=1;
			while (d<sme) d*=42ll;
			mn=d-sme;
		}
	}tr[400005];
	void pushup(int x)
	{
		tr[x].mn=min(tr[x*2].mn,tr[x*2+1].mn);
		if (tr[x*2].sme&&tr[x*2].sme==tr[x*2+1].sme) tr[x].sme=tr[x*2].sme; else tr[x].sme=0;
	}
	void pushdo(int x)
	{
		if (tr[x].sme)
		{
			tr[x*2].sme=tr[x*2+1].sme=tr[x].sme;
			tr[x*2].d=tr[x*2+1].d=tr[x].d;
			tr[x].add=0;
		}
		tr[x*2].update(tr[x].add);
		tr[x*2+1].update(tr[x].add);
		tr[x].add=0;
	}
	void dfs(int x)
	{
		if (tr[x].mn>=0) return;
		if (tr[x].sme)
		{
			while (tr[x].d<tr[x].sme) tr[x].d*=42ll;
			tr[x].mn=tr[x].d-tr[x].sme;
			return;
		}
		pushdo(x);
		dfs(x*2);dfs(x*2+1);
		pushup(x);
	}
	long long query(int x,int y)
	{
		if (tr[x].l>y||tr[x].r<y) return 0;
		if (tr[x].l==tr[x].r) return tr[x].sme;
		pushdo(x);
		return query(x*2,y)+query(x*2+1,y);
	}
	void build(int x,int l,int r)
	{
		tr[x].l=l;
		tr[x].r=r;
		if (l==r)
		{
			tr[x].sme=num[l];
			tr[x].d=1;
			while (tr[x].d<tr[x].sme) tr[x].d*=42ll;
			tr[x].mn=tr[x].d-tr[x].sme;
		}
		else
		{
			build(x*2,l,(l+r)/2);
			build(x*2+1,(l+r)/2+1,r);
			pushup(x);
		}
	}
	void update1(int x,int l,int r,int c)
	{
		if (tr[x].l>r||tr[x].r<l) return;
		if (tr[x].l>=l&&tr[x].r<=r) {tr[x].update(c);return;}
		pushdo(x);
		update1(x*2,l,r,c);
		update1(x*2+1,l,r,c);
		pushup(x);
	}
	void update2(int x,int l,int r,int c)
	{
		if (tr[x].l>r||tr[x].r<l) return;
		if (tr[x].l>=l&&tr[x].r<=r)
		{
			tr[x].sme=c;
			tr[x].d=1;
			while (tr[x].d<tr[x].sme) tr[x].d*=42ll;
			tr[x].mn=tr[x].d-tr[x].sme;
			return;
		}
		pushdo(x);
		update2(x*2,l,r,c);
		update2(x*2+1,l,r,c);
		pushup(x);
	}
}tr;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	fz1(i,n)
	{
		scanf("%I64d",&num[i]);
	}
	tr.build(1,1,n);
	fz1(i,m)
	{
		scanf("%I64d",&op);
		if (op==1)
		{
			scanf("%I64d",&x);
			printf("%I64d\n",tr.query(1,x));
		}
		if (op==2)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			tr.update2(1,x,y,z);
		}
		if (op==3)
		{
			scanf("%I64d%I64d%I64d",&x,&y,&z);
			tr.update1(1,x,y,z);
			tr.dfs(1);
			while (tr.tr[1].mn==0)
			{
				tr.update1(1,x,y,z);
				tr.dfs(1);
			}
		}
	}
	return 0;
}