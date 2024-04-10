#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=300100;
int N,P[MX];

#define li (i<<1)
#define ri (i<<1|1)
struct SegmentTree{int v,c,z;}T[MX*4];
inline void Put(int i,int x){T[i].v+=x,T[i].z+=x;}
void Build(int i,int l,int r)
{
	T[i].c=r-l+1;
	if(l==r)return;
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
}
void Add(int i,int l,int r,int a,int b,int x)
{
	if(a<=l&&r<=b){Put(i,x);return;}
	if(T[i].z){Put(li,T[i].z),Put(ri,T[i].z),T[i].z=0;}
	int m=(l+r)>>1;
	if(a<=m)Add(li,l,m,a,b,x);
	if(b>m)Add(ri,m+1,r,a,b,x);
	T[i].v=min(T[li].v,T[ri].v);
	T[i].c=(T[i].v==T[li].v)*T[li].c+(T[i].v==T[ri].v)*T[ri].c;
}

int U[MX],D[MX],tu,td;


int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int x,y;
		scanf("%d%d",&x,&y),P[x]=y;
	}
	Build(1,1,N);
	ll ans=0;
	Fr(i,1,N)
	{
		while(tu&&P[U[tu]]<P[i])Add(1,1,N,U[tu-1]+1,U[tu],P[i]-P[U[tu]]),--tu;
		while(td&&P[D[td]]>P[i])Add(1,1,N,D[td-1]+1,D[td],P[D[td]]-P[i]),--td;
		U[++tu]=i,D[++td]=i,Add(1,1,N,1,i,-1);
		ans+=T[1].c;
	}
	printf("%lld\n",ans);
	return 0;
}