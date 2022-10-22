#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
const int MX=5e5+100;

struct Star{int y,nx;}E[MX<<2]; // 
int H[MX],qid[MX],ec;
#define Fe(H,i,x) for(int i=H[x];i;i=E[i].nx)
void add(int H[],int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}
struct Query{int a,b,ans;}Q[MX];
int N,M;
int C[MX];

int cnt[MX][26]; //  
char ans[MX];

int D[MX],sz[MX],son[MX];
#define y E[i].y
void dfs1(int x,int d)
{
	D[x]=d,sz[x]=1,son[x]=-1;
	int mx=0;
	Fe(H,i,x)
	{
		dfs1(y,d+1),sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}
void Add(int x)
{
	int d=D[x],c=C[x];
	cnt[d][c]++;
	if(cnt[d][c]%2)++ans[d];
	else --ans[d];
}
void AddT(int x)
{
	Add(x);
	Fe(H,i,x)AddT(y);
}
void ClearT(int x)
{
	cnt[D[x]][C[x]]=0;
	ans[D[x]]=0;
	Fe(H,i,x)ClearT(y);
}
void DsuOnTree(int x)
{
	Fe(H,i,x)if(y!=son[x])DsuOnTree(y),ClearT(y);
	if(son[x]!=-1)DsuOnTree(son[x]);
	Fe(H,i,x)if(y!=son[x])AddT(y);
	Add(x);
	/*
	printf("Point %d:\n",x);
	Fr(i,1,3)
	{
		printf("dep %d:",i);
		Fo(j,0,26)if(cnt[i][j])printf(" %c=%d",j+'a',cnt[i][j]);
		printf(" |ans=%d\n",ans[i]);
		putchar('\n');
	}
	putchar('\n');
	*/
	Fe(qid,i,x)
	{
		int q=y;
		Q[q].ans=ans[Q[q].b]<=1;
	}
}
#undef y

int main()
{
	scanf("%d%d",&N,&M);
	int x;
	Fr(i,2,N)scanf("%d",&x),add(H,x,i);
	char c;
	Fr(i,1,N)scanf(" %c",&c),C[i]=c-'a';
	Fr(i,1,M)scanf("%d%d",&Q[i].a,&Q[i].b),add(qid,Q[i].a,i);
	dfs1(1,1);
	DsuOnTree(1);
	Fr(i,1,M)printf(Q[i].ans?"Y""e""s":"N""o"),putchar('\n');
	return 0;
}