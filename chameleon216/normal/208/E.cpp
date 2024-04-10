#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=1e5+100;
struct List
{
	struct Node{int y,nx;}E[MX];
	int H[MX],ec;
	void add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}
};
#define Fe(j,x,lis)\
for(int i_=lis.H[x],j=lis.E[i_].y;\
	i_;\
	i_=lis.E[i_].nx,j=lis.E[i_].y)

List edge;
int N,M;
struct Query{int x,k,kf,ans;}q[MX];

/***** k *****/
int F[MX][20],D[MX];
void dfs1(int x,int d)
{
	D[x]=d;
	Fo(i,1,20)F[x][i]=F[F[x][i-1]][i-1];
	Fe(y,x,edge)dfs1(y,d+1);
}

int get_kf(int x,int k)
{
	for(int i=0;k;++i,k>>=1)if(k&1)x=F[x][i];
	return x;
}


/***** dsu on tree *****/
List ql;
int sz[MX],son[MX];
void dfs2(int x)
{
	sz[x]=1,son[x]=-1;
	int mx=0;
	Fe(y,x,edge)
	{
		dfs2(y),sz[x]+=sz[y];
		if(sz[y]>mx)mx=sz[y],son[x]=y;
	}
}

int cnt[MX];

void AddT(int x)
{
	++cnt[D[x]];
	Fe(y,x,edge)AddT(y);
}
void ClearT(int x)
{
	--cnt[D[x]];
	Fe(y,x,edge)ClearT(y);
}
void DsuOnTree(int x)
{
	//Fr(i,1,N)printf("%d ",cnt[i]); putchar('\n');
	Fe(y,x,edge)if(y!=son[x])
		DsuOnTree(y),ClearT(y);
	if(son[x]!=-1)DsuOnTree(son[x]);
	Fe(y,x,edge)if(y!=son[x])AddT(y);
	++cnt[D[x]];
	Fe(i,x,ql)
	{
		int d=D[q[i].x];
		q[i].ans=cnt[d]-1;
	}
}



int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		scanf("%d",&F[i][0]);
		if(F[i][0])edge.add(F[i][0],i);
	}
	Fr(i,1,N)if(F[i][0]==0)dfs1(i,0);
	
	//Fr(i,1,N){Fo(j,0,20)printf("%d ",F[i][j]);putchar('\n');}
	
	scanf("%d",&M);
	Fr(i,1,M)scanf("%d%d",&q[i].x,&q[i].k),q[i].kf=get_kf(q[i].x,q[i].k);
	Fr(i,1,M)if(q[i].kf)ql.add(q[i].kf,i);
	
	Fr(i,1,N)if(F[i][0]==0)dfs2(i);
	Fr(i,1,N)if(F[i][0]==0)DsuOnTree(i),ClearT(i);
	Fr(i,1,M)printf("%d ",q[i].ans);putchar('\n');
	
	return 0;
}