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
#define fd0k(i,n) for ((i)=(int)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define T_ long long
using namespace std;
int n,m,i,j,a[200005],aa[200005],lt[800005],rt[800005],sum[800005],rev[800005],fi[200005],ed[200005],x,y,ti;
string op;
vector<int> bi[200005];
void pushup(int x)
{
	sum[x]=sum[x*2]+sum[x*2+1];
}
void pushdo(int x)
{
	if (rev[x])
	{
		sum[x*2]=(rt[x*2]-lt[x*2]+1)-sum[x*2];
		sum[x*2+1]=(rt[x*2+1]-lt[x*2+1]+1)-sum[x*2+1];
		rev[x*2]^=1;
		rev[x*2+1]^=1;
		rev[x]=0;
	}
}
void build(int x,int l,int r)
{
	lt[x]=l;
	rt[x]=r;
	rev[x]=sum[x]=0;
	if (l==r)
	{
		sum[x]=aa[l];
		return;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2+1,r);
	pushup(x);
}
void update(int x,int l,int r)
{
	if (lt[x]>r||rt[x]<l) return;
	if (lt[x]>=l&&rt[x]<=r)
	{
		sum[x]=(rt[x]-lt[x]+1)-sum[x];
		rev[x]^=1;
		return;
	}
	pushdo(x);
	update(x*2,l,r);
	update(x*2+1,l,r);
	pushup(x);
}
int query(int x,int l,int r)
{
	if (lt[x]>r||rt[x]<l) return 0;
	if (lt[x]>=l&&rt[x]<=r) return sum[x];
	pushdo(x);
	return query(x*2,l,r)+query(x*2+1,l,r);
}
void dfs(int x,int fa)
{
	fi[x]=++ti;
	ff(bi[x],it)
	{
		if (*it==fa) continue;
		dfs(*it,x);
	}
	ed[x]=ti;
}
int main()
{
	scanf("%d",&n);
	fz(i,2,n)
	{
		scanf("%d",&x);
		bi[x].push_back(i);
	}
	fz1(i,n) scanf("%d",&a[i]);
	dfs(1,0);
	fz1(i,n) aa[fi[i]]=a[i];
	build(1,1,n);
	scanf("%d",&m);
	while (m--)
	{
		rdst(op,5);
		if (op=="pow")
		{
			scanf("%d",&x);
			update(1,fi[x],ed[x]);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(1,fi[x],ed[x]));
		}
	}
	return 0;
}