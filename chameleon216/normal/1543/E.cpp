#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;~i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=1000100;
int K,N,M;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Link(int x,int y)
{
	E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;
}

int B[MX],P[MX],P_[MX];

int mian()
{
	scanf("%d",&K);
	N=1<<K,M=K*(1<<(K-1));
	memset(H,0xff,N*sizeof(int)),ec=0;
	memset(B,0,N*sizeof(int));
	memset(P,0,N*sizeof(int));
	memset(P_,0,N*sizeof(int));
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		Link(x,y),Link(y,x);
	}
	
	queue<int> q;
	q.push(0);
	int c=0;
	Fe(i,0,y)P[y]=1<<(c++);
	while(!q.empty())
	{
		int x=q.front();
		q.pop(),B[x]=2;
		Fe(i,x,y)
		{
			if(!B[y])q.push(y),B[y]=1;
			if(B[y]<2)P[y]|=P[x];
		}
	}
	Fo(i,0,N)P_[P[i]]=i;
	Fo(i,0,N)printf("%d ",P_[i]);
	putchar('\n');
	if(K&(K-1)){printf("-1\n");return 0;}
	Fo(i,0,N)
	{
		int p=P[i],x=0;
		Fo(k,0,K)if(p>>k&1)x^=k;
		printf("%d ",x);
	}
	putchar('\n');
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
	}
}