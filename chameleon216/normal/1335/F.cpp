#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <vector>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=1100000;

int N,M;
inline int Pos(int x,int y){return (x-1)*M+y;}
int Co[MX],F[MX];

int B[MX],Dfn[MX],Low[MX],dcnt;
int C[MX],Ci[MX],ccnt,stk[MX],tp;
void Tarjan(int x)
{
	B[x]=1,Low[x]=Dfn[x]=++dcnt,stk[++tp]=x;
	int y=F[x];
	if(B[y]==0)Tarjan(y),Low[x]=min(Low[x],Low[y]);
	else if(B[y]==1)Low[x]=min(Low[x],Dfn[y]);
	if(Dfn[x]==Low[x])
	{
		++ccnt; int z=0;
		while(z!=x)
			z=stk[tp--],C[z]=ccnt,++Ci[ccnt],B[z]=2;
	}
}

int G[MX],I[MX];
void dfs1(int x,int g)
{
	if(B[x])return;
	B[x]=1,G[x]=g,I[x]=C[x];
	dfs1(F[x],g+1);
}
void dfs2(int x)
{
	if(B[x])return;
	B[x]=1;
	int y=F[x];
	dfs2(y),I[x]=I[y],G[x]=(G[y]-1+Ci[I[x]])%Ci[I[x]];
}

vector<int> V[MX];
int cnt[MX];

void Find()
{
	Fr(x,1,N*M)if(B[x]==0)Tarjan(x);
	Fr(i,1,N*M)B[i]=0;
	Fr(x,1,N*M)
		if(Ci[C[x]]>1&&!B[x])
			dfs1(x,0);
	Fr(x,1,N*M)
		if(Ci[C[x]]==1&&!B[x])
			dfs2(x);
	Fr(x,1,N*M)V[I[x]].push_back(x);
	int sum=0,ans=0;
	Fr(i,1,ccnt)if(Ci[i]>1)
	{
		sum+=Ci[i];
		int sz=V[i].size();
		Fo(j,0,sz)cnt[G[V[i][j]]]|=!Co[V[i][j]];
		Fo(j,0,Ci[i])ans+=cnt[j];
		Fo(j,0,sz)cnt[G[V[i][j]]]=0;
	}
	printf("%d %d\n",sum,ans);
}

int mian()
{
	scanf("%d%d",&N,&M);
	char c;
	Fr(i,1,N)Fr(j,1,M)
	{
		int x=Pos(i,j);
		scanf(" %c",&c),Co[x]=c-'0';
	}
	Fr(i,1,N)Fr(j,1,M)
	{
		int x=Pos(i,j);
		scanf(" %c",&c);
		switch(c)
		{
		case 'U':F[x]=Pos(i-1,j);break;
		case 'D':F[x]=Pos(i+1,j);break;
		case 'L':F[x]=Pos(i,j-1);break;
		case 'R':F[x]=Pos(i,j+1);break;
		}
	}
	
	Find();
	/*Fr(i,1,N)
	{
		Fr(j,1,M)printf("%d ",G[Pos(i,j)]);
		putchar('\n');
	}*/
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		int node=N*M;
		Fr(i,1,node)
			G[i]=I[i]=Co[i]=F[i]=B[i]=Dfn[i]=Low[i]=
			C[i]=Ci[i]=0,V[i].clear();
		dcnt=ccnt=tp=0;
	}
	return 0;
}