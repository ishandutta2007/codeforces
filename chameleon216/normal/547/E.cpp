#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100,MY=500100;
int N,M,I[MX];
char S1[MX];
string S[MX];

int C[MX][26],F[MX],ac=1;
int Ins(string& s)
{
	int x=1,n=s.size();
	Fr(i,0,n-1)
	{
		int k=s[i]-'a';
		if(!C[x][k])C[x][k]=++ac;
		x=C[x][k];
	}
	return x;
}
void Build()
{
	queue<int> q;
	Fr(k,0,25)C[0][k]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		Fr(k,0,25)
		{
			if(C[x][k])F[C[x][k]]=C[F[x]][k],q.push(C[x][k]);
			else C[x][k]=C[F[x]][k];
		}
	}
}

struct Edge{int y,nx;}E[MX*2];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int sz[MX],dfn[MX],dc;
void dfs1(int x)
{
	sz[x]=1,dfn[x]=++dc;
	Fe(i,x,y)dfs1(y),sz[x]+=sz[y];
}
struct Fenwick
{
	int v[MX];
	void Add(int i,int x)
	{
		while(i<=ac)v[i]+=x,i+=i&-i;
	}
	int Ask_(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=i&-i;
		return r;
	}
	int Ask(int l,int r){return Ask_(r)-Ask_(l-1);}
}T;

struct Query{int q,x,w,nx;}Q[MY*2];
int Hq[MX],qc,ans[MY];
void AddQ(int q,int x,int w,int i)
{
	Q[++qc].q=q,Q[qc].x=x,Q[qc].w=w,Q[qc].nx=Hq[i],Hq[i]=qc;
}

void Match(string& s)
{
	int x=1,n=s.size();
	Fr(i,0,n-1)
	{
		int k=s[i]-'a';
		x=C[x][k],T.Add(dfn[x],1);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%s",S1),S[i]=S1,I[i]=Ins(S[i]);
	Build();
	Fr(x,2,ac)Link(F[x],x);
	dfs1(1);
	Fr(i,1,M)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		AddQ(i,I[k],-1,l-1),AddQ(i,I[k],1,r);
	}
	Fr(i,1,N)
	{
		Match(S[i]);
		for(int j=Hq[i];j;j=Q[j].nx)
		{
			int x=Q[j].x;
			ans[Q[j].q]+=T.Ask(dfn[x],dfn[x]+sz[x]-1)*Q[j].w;
		}
	}
	Fr(i,1,M)printf("%d\n",ans[i]);
	return 0;
}