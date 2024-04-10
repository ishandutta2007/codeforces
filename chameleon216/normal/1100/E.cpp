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

const int MX=100100;
int N,M;

struct Edge{int x,y,w,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y,int w)
{
	E[++ec].x=x,E[ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

int B[MX],id[MX],ic;
int dfs(int x,int w)
{
	B[x]=1;
	Fe(i,x,y)if(E[i].w>w)
	{
		if(B[y]==0)
		{
			if(dfs(y,w))return 1;
		}
		else if(B[y]==1)return 1;
	}
	B[x]=2,id[x]=++ic;
	return 0;
}

bool Check(int w)
{
	memset(B,0,sizeof(B)),ic=0;
	Fr(x,1,N)if(B[x]==0&&dfs(x,w))return 1;
	return 0;
}

int BinarySearch(int l,int r)
{
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(Check(m))l=m+1;
		else r=m-1;
	}
	return l;
}

int ans[MX],ac;

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		Link(x,y,w);
	}
	int w=BinarySearch(0,1000000000);
	
	Check(w);
	Fr(i,1,ec)
	{
		int x=E[i].x,y=E[i].y;
		if(id[x]<id[y])ans[++ac]=i;
	}
	
	printf("%d %d\n",w,ac);
	Fr(i,1,ac)printf("%d ",ans[i]);
	putchar('\n');
	
	return 0;
}