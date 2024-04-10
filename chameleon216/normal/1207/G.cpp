#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <queue>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
typedef long long ll;
using namespace std;
const int MX=510000;
int N,M;
char S[MX];

struct Fail{int y,nx;}E[MX]; //ACFail
int H[MX],ec;
void Adde(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

struct ACAM{int c[26],f;}T[MX]; //ACTrie
int ac=1;
queue<int> Que;
#define cx T[x].c[k]
#define fx T[x].f
int Ins(char* s)
{
	int x=1,l=strlen(s+1);
	Fr(i,1,l)
	{
		int k=s[i]-'a';
		if(!cx)cx=++ac;
		x=cx;
	}
	return x;
}
void Build()
{
	int x=0;Que.push(1);
	Fo(k,0,26)cx=1;
	while(!Que.empty())
	{
		x=Que.front(),Que.pop();
		Fo(k,0,26)
			if(cx)
			{
				T[cx].f=T[fx].c[k],Que.push(cx);
				Adde(T[cx].f,cx);
			}
			else cx=T[fx].c[k];
	}
}

int sz[MX],id[MX],ic; //Failsize,Dfn
void dfs1(int x)
{
	sz[x]=1,id[x]=++ic;
	Fe(i,x)
	{
		int y=E[i].y;
		dfs1(y),sz[x]+=sz[y];
	}
}

struct Trie{int c[26];}Q[MX]; //Trie
int qc=1;
int Qi[MX]; //


struct Seg{int v,l,r;}U[MX<<5]; //
int sc;
#define li U[i].l
#define ri U[i].r
int Copy(int i){U[++sc]=U[i];return sc;}
void Add(int i,int l,int r,int a)
{
	++U[i].v;if(l==r)return;
	int m=(l+r)>>1;
	if(a<=m)li=Copy(li),Add(li,l,m,a);
	else ri=Copy(ri),Add(ri,m+1,r,a);
}
int Ask(int i,int l,int r,int a,int b)
{
	if(!i||(a<=l&&r<=b))return U[i].v;
	int m=(l+r)>>1,A=0;
	if(a<=m)A+=Ask(li,l,m,a,b);
	if(b>m)A+=Ask(ri,m+1,r,a,b);
	return A;
}

struct Query{int qnode,anode;}Qry[MX];
//qnode,anodeAC/Fail

int Se[MX]; //
void dfs2(int x,int f,int a) //fatherAC
{
	Se[x]=Copy(Se[f]);
	Add(Se[x],1,ac,id[a]);
	Fo(k,0,26)
	{
		int y=Q[x].c[k];
		if(y)dfs2(y,x,T[a].c[k]);
	}
}


int main()
{
	scanf("%d",&N);
	int op,j,k,x;char ch;
	Fr(i,1,N)
	{
		scanf("%d",&op);
		if(op==1)x=1;
		else scanf("%d",&j),x=Qi[j];
		scanf(" %c",&ch),k=ch-'a';
		if(!Q[x].c[k])Q[x].c[k]=++qc;
		Qi[i]=Q[x].c[k];
	}
	//dfs1(1);
	scanf("%d",&M);
	Fr(i,1,M)
	{
		scanf("%d%s",&j,S+1);
		Qry[i].qnode=Qi[j];
		Qry[i].anode=Ins(S);
	}
	Build();
	dfs1(1);
	dfs2(1,0,1);
	//printf("dfn: ");Fr(i,1,ac)printf("%2d ",id[i]);putchar('\n');
	//printf("siz: ");Fr(i,1,ac)printf("%2d ",sz[i]);putchar('\n');
	Fr(i,1,M)
	{
		int q=Qry[i].qnode;
		int a=Qry[i].anode;
		int res=Ask(Se[q],1,ac,id[a],id[a]+sz[a]-1);
		printf("%d\n",res);
	}
	return 0;
}