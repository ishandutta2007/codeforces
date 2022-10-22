#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x],y=E[i].y;i;i=E[i].nx,y=E[i].y)
using namespace std;
typedef long long ll;

const int MB=1<<21;
struct FastIO
{
	char buf[MB+100],*p,*e;
	int getChar()
	{
		if(p==e)p=buf,e=buf+fread(buf,1,MB,stdin);
		return p==e?EOF:*p++;
	}
	template<typename T>
	FastIO& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getChar())l=c;
		for(x=0;isdigit(c);c=getChar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IO;

const int MX=50100;
struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int N,K;

int B[MX],O[MX],oc,sz[MX],msz[MX];
void dfs1(int x,int f)
{
	O[++oc]=x,sz[x]=1,msz[x]=0;
	Fe(i,x)if(!B[y]&&y!=f)
		dfs1(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
}
int Centroid(int rt)
{
	oc=0,dfs1(rt,0);
	int siz=sz[rt];
	Fr(i,2,oc)
	{
		int x=O[i];
		msz[x]=max(msz[x],siz-sz[x]);
		if(msz[x]<msz[rt])rt=x;
	}
	return rt;
}

ll A;
int tmp[MX],tc,cnt[MX];
void dfs2(int x,int f,int d)
{
	tmp[++tc]=d;
	Fe(i,x)if(!B[y]&&y!=f)dfs2(y,x,d+1);
}
ll Calc(int x,int d)
{
	tc=0,dfs2(x,0,d);
	ll sum=0;
	Fr(i,1,tc)
	{
		if(K-tmp[i]>=0)sum+=cnt[K-tmp[i]];
		++cnt[tmp[i]];
	}
	Fr(i,1,tc)cnt[tmp[i]]=0;
	return sum;
}

void Divide(int x)
{
	A+=Calc(x,0),B[x]=1;
	Fe(i,x)if(!B[y])A-=Calc(y,1);
	Fe(i,x)if(!B[y])Divide(Centroid(y));
}



int main()
{
	IO>>N>>K;
	Fr(i,2,N)
	{
		int x,y;
		IO>>x>>y;
		Add(x,y),Add(y,x);
	}
	Divide(Centroid(1));
	printf("%lld\n",A);
	return 0;
}