#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int N=300000,MX=600100;

struct DisjointSet
{
	ll sum;
	int f[MX],sz[MX],sx[MX],sy[MX];
	int stk[MX],tp;
	void Init()
	{
		Fr(x,1,N)f[x]=x,sz[x]=1,sx[x]=1;
		Fr(y,N+1,2*N)f[y]=y,sz[y]=1,sy[y]=1;
	}
	int Find(int x)
	{
		while(x!=f[x])x=f[x];
		return x;
	}
	void Union(int x,int y)
	{
		int a=Find(x),b=Find(N+y);
		if(a==b)return;
		if(sz[a]>sz[b])swap(a,b);
		sum+=(ll)sx[a]*sy[b]+(ll)sx[b]*sy[a];
		f[a]=b,sz[b]+=sz[a];
		sx[b]+=sx[a],sy[b]+=sy[a];
		stk[++tp]=a;
	}
	void Rollback(int t)
	{
		while(t<tp)
		{
			int a=stk[tp--],b=f[a];
			f[a]=a,sz[b]-=sz[a];
			sx[b]-=sx[a],sy[b]-=sy[a];
			sum-=(ll)sx[a]*sy[b]+(ll)sx[b]*sy[a];
		}
	}
}T;

struct List{int x,y,nx;}L[MX<<3];
int H[MX<<2],lc;
ll A[MX];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Modify(int i,int l,int r,int a,int b,int x,int y)
{
	if(a<=l&&r<=b)
	{
		L[++lc].x=x,L[lc].y=y,L[lc].nx=H[i],H[i]=lc;
		return;
	}
	if(a<=mid)Modify(li,l,mid,a,b,x,y);
	if(b>mid)Modify(ri,mid+1,r,a,b,x,y);
}
void Divide(int i,int l,int r)
{
	int t=T.tp;
	for(int j=H[i];j;j=L[j].nx)
		T.Union(L[j].x,L[j].y);
	if(l==r){A[l]=T.sum,T.Rollback(t);return;}
	Divide(li,l,mid);
	Divide(ri,mid+1,r);
	T.Rollback(t);
}


int M;

int main()
{
	scanf("%d",&M);
	map<pair<int,int>,int> mp;
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int &las=mp[make_pair(x,y)];
		if(las)Modify(1,1,M,las,i-1,x,y),las=0;
		else las=i;
	}
	for(map<pair<int,int>,int>::iterator it=mp.begin(),jt=mp.end();it!=jt;++it)
	{
		int x=it->first.first,y=it->first.second,las=it->second;
		if(las)Modify(1,1,M,las,M,x,y);
	}
	
	T.Init();
	Divide(1,1,M);
	Fr(i,1,M)printf("%lld ",A[i]);
	putchar('\n');
	
	return 0;
}