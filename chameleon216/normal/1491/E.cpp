#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <vector>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=210000;
int F[MX];
int kFib(int x)
{
	int k=lower_bound(F+1,F+33,x)-F;
	return F[k]==x?k:-1;
}

int N;
vector<int> V[MX];
int sz[MX];
void dfs1(int x,int f)
{
	sz[x]=1;
	for(int y:V[x])if(y!=f)
		dfs1(y,x),sz[x]+=sz[y];
}
int dfs2(int x,int f,int k,int& rx,int& ry)
{
	if(sz[x]==F[k-1]){rx=x,ry=f;return 1;}
	if(sz[x]==F[k-2]){rx=f,ry=x;return 1;}
	for(int y:V[x])if(y!=f)
		if(dfs2(y,x,k,rx,ry))return 1;
	return 0;
}
void dfs3(int x,int k)
{
	if(F[k]==1)return;
	int u=0,v=0;
	dfs1(x,0);
	if(!dfs2(x,0,k,u,v))printf("NO\n"),exit(0);
//	printf("cut %d-%d\n",u,v);
	for(int i=0,siz=V[u].size();i<siz;++i)if(V[u][i]==v)
		{swap(V[u][i],V[u][siz-1]),V[u].pop_back();break;}
	for(int i=0,siz=V[v].size();i<siz;++i)if(V[v][i]==u)
		{swap(V[v][i],V[v][siz-1]),V[v].pop_back();break;}
	dfs3(u,k-1),dfs3(v,k-2);
}


int main()
{
	F[1]=F[2]=1;
	Fr(i,3,32)F[i]=F[i-1]+F[i-2];
	
	scanf("%d",&N);
	int x,y;
	Fr(i,2,N)
	{
		scanf("%d%d",&x,&y);
		V[x].push_back(y),V[y].push_back(x);
	}
	
	int k=kFib(N);
	if(k==-1)printf("NO\n"),exit(0);
	dfs3(1,k);
	
	printf("YES\n");
	return 0;
}