#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=1200000;
int N,M,I[MX];
char S[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y)
	{ E[++ec].y=y,E[ec].nx=H[x],H[x]=ec; }

int C[MX][26],F[MX],ac=1;
queue<int> Q;
int Ins(char* s)
{
	int x=1,l=strlen(s+1);
	Fr(i,1,l)
	{
		int k=s[i]-'a';
		if(!C[x][k])C[x][k]=++ac;
		x=C[x][k];
	}
	return x;
}
void Build()
{
	Q.push(1);
	Fo(k,0,26)C[0][k]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		if(F[x])Add(F[x],x);
		Fo(k,0,26)
			if(C[x][k])F[C[x][k]]=C[F[x]][k],Q.push(C[x][k]);
			else C[x][k]=C[F[x]][k];
	}
}

int sz[MX],id[MX],ic;
#define y E[i].y
void dfs1(int x)
{
	sz[x]=1,id[x]=++ic;
	Fe(i,x)dfs1(y),sz[x]+=sz[y];
}
#undef y

struct Bit
{
	int v[MX];
	void add(int i,int x)
	{ while(i<=ac)v[i]+=x,i+=(i&-i); }
	void add(int l,int r,int x)
	{ add(l,x),add(r+1,-x); }
	int ask(int i)
	{
		int r=0;
		while(i)r+=v[i],i-=(i&-i);
		return r;
	}
}T;

char B[MX];
void AddPoint(int x,int a)
	{ T.add(id[x],id[x]+sz[x]-1,a); }
int AskRoot(int x)
	{ return T.ask(id[x]); }
ll Match(char* s)
{
	int x=1,l=strlen(s+1);
	ll ans=0;
	Fr(i,1,l)x=C[x][s[i]-'a'],ans+=AskRoot(x);
	return ans;
}


int main()
{
	scanf("%d%d",&M,&N);
	Fr(i,1,N)scanf("%s",S+1),I[i]=Ins(S);
	Build();
	dfs1(1);
	Fr(i,1,N)AddPoint(I[i],1),B[i]=1;
	Fr(i,1,M)
	{
		char c;
		int x;
		scanf(" %c",&c);
		switch(c)
		{
		case '+':
			scanf("%d",&x);
			if(!B[x])AddPoint(I[x],1),B[x]=1;
			break;
		case '-':
			scanf("%d",&x);
			if(B[x])AddPoint(I[x],-1),B[x]=0;
			break;
		case '?':
			scanf("%s",S+1);
			printf("%lld\n",Match(S));
			break;
		}
	}
	return 0;
}