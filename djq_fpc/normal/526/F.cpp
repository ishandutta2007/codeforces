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
//#define int long long
using namespace std;
int n,m,i,j,a[300005],mi[1200005],c[1200005],tg[1200005],lt[1200005],rt[1200005],x,y;
long long ans;
vector<int> f,g;
void pushup(int x)
{
	mi[x]=min(mi[x*2],mi[x*2+1]);
	c[x]=0;
	if (mi[x*2]==mi[x]) c[x]+=c[x*2];
	if (mi[x*2+1]==mi[x]) c[x]+=c[x*2+1];
	mi[x]+=tg[x];
}
void build(int x,int l,int r)
{
	lt[x]=l;
	rt[x]=r;
	tg[x]=0;
	if (l==r)
	{
		mi[x]=0;
		c[x]=1;
		return;
	}
	build(x*2,l,(l+r)/2);
	build(x*2+1,(l+r)/2+1,r);
	pushup(x);
}
void update(int x,int l,int r,int c)
{
	if (lt[x]>r||rt[x]<l) return;
	if (lt[x]>=l&&rt[x]<=r)
	{
		tg[x]+=c;
		mi[x]+=c;
		return;
	}
	update(x*2,l,r,c);
	update(x*2+1,l,r,c);
	pushup(x);
}
int main()
{
	scanf("%d",&n);
	fz1(i,n)
	{
		scanf("%d%d",&x,&y);
		a[x]=y;
	}
	f.push_back(0);
	g.push_back(0);
	build(1,1,n);
	update(1,1,n,1);
	fz1(i,n)
	{
		update(1,1,i,-1);
		while (f.size()>1&&a[f.back()]<a[i])
		{
			update(1,f[f.size()-2]+1,f[f.size()-1],a[i]-a[f.back()]);
			f.pop_back();
		}
		while (g.size()>1&&a[g.back()]>a[i])
		{
			update(1,g[g.size()-2]+1,g[g.size()-1],a[g.back()]-a[i]);
			g.pop_back();
		}
		f.push_back(i);
		g.push_back(i);
		if (mi[1]==0) ans+=c[1];
	}
	cout<<ans<<endl;
	return 0;
}