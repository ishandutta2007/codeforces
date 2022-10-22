#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=500100;
int N,M;

struct Edge{int y,w,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y,int w)
{
	E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;
}

int B[MX],cnt[2],flg;
void dfs(int x,int c)
{
	B[x]=c,++cnt[c];
	Fe(i,x,y)
	{
		if(B[y]==-1)dfs(y,c^E[i].w);
		else flg|=B[y]^c^E[i].w;
	}
}

int mian()
{
	scanf("%d%d",&N,&M);
	char s[12];
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d%s",&x,&y,s);
		Link(x,y,s[0]=='i');
		Link(y,x,s[0]=='i');
	}
	memset(B,0xff,(N+1)*sizeof(int));
	flg=0;
	int sum=0;
	Fr(x,1,N)if(B[x]==-1)
	{
		cnt[0]=cnt[1]=0;
		dfs(x,1);
		if(flg)return -1;
		sum+=max(cnt[0],cnt[1]);
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int r=mian();
		printf("%d\n",r);
		memset(H,0,(N+1)*sizeof(int));
		ec=0;
	}
}