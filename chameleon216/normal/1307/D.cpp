#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;
const int MX=200100;
int N,M,K,A[MX];

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int B[MX],Ds[MX],Dt[MX];
void bfs(int s,int d[])
{
	memset(B,0,(N+1)*sizeof(int));
	queue<int> q;
	q.push(s),B[s]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		Fe(i,x,y)if(!B[y])
			q.push(y),d[y]=d[x]+1,B[y]=1;
	}
}

bool cmp(int x,int y){return Ds[x]<Ds[y];}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	Fr(i,1,K)scanf("%d",&A[i]);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	bfs(1,Ds);
	bfs(N,Dt);
	sort(A+1,A+K+1,cmp);
//	Fr(i,1,K)printf("%d ",A[i]);putchar('\n');
	int ans=0;
	Fo(i,1,K)
	{
		int x=A[i],y=A[i+1];
		ans=max(ans,min(min(Ds[x]+Dt[y],Ds[y]+Dt[x])+1,Ds[N]));
	}
	printf("%d\n",ans);
	return 0;
}