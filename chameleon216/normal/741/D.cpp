#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=654321,MY=4400000,Inf=0x3f3f3f3f;
struct Edge{int y,nx,c;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y,int c)
	{E[++ec].y=y,E[ec].c=c,E[ec].nx=H[x],H[x]=ec;}
int N;

#define y E[i].y
int D[MX],sz[MX],son[MX],C[MX];
void dfs1(int x,int f,int d,int s)
{
	D[x]=d,sz[x]=1,C[x]=s;int mx=0;
	Fe(i,x)if(y!=f)
	{
		dfs1(y,x,d+1,s^(1<<E[i].c)),sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}

int tmp[MX],tc,Len;
int B[MY],A[MX];
void dfs3(int x,int f)
{
	tmp[++tc]=x;
	Fe(i,x)if(y!=f)dfs3(y,x);
}
void Calc(int x)
{
	int mx=-Inf;
	Fo(i,0,22)mx=max(mx,B[C[x]^(1<<i)]); //
	mx=max(mx,B[C[x]]); //
	Len=max(Len,mx+D[x]);
}
void AddN(int x){B[C[x]]=max(B[C[x]],D[x]);}
void AddT(int x,int f)
{
	tc=0,dfs3(x,f);
	Fr(i,1,tc)Calc(tmp[i]);
	Fr(i,1,tc)AddN(tmp[i]);
}

void ClearT(int x,int f)
{
	B[C[x]]=-Inf;
	Fe(i,x)if(y!=f)ClearT(y,x);
}

void dfs2(int x,int f)
{
	Fe(i,x)if(y!=son[x]&&y!=f)
		dfs2(y,x),ClearT(y,x),Len=0;
	if(son[x])dfs2(son[x],x);
	Fe(i,x)if(y!=son[x]&&y!=f)AddT(y,x);
	AddN(x),Calc(x),A[x]=Len-2*D[x],Len=0;
	Fe(i,x)if(y!=f)A[x]=max(A[x],A[y]);
}


int main()
{
	scanf("%d",&N);
	Fr(i,2,N)
	{
		int f;char c;
		scanf("%d %c",&f,&c);
		Add(f,i,c-'a');
	}
	dfs1(1,0,0,0);
	Fill(B,0xc0);
	dfs2(1,0);
	Fr(i,1,N)printf("%d ",A[i]);
	return 0;
}