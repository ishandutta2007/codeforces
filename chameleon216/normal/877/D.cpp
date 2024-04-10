#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <algorithm>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=1200,Inf=0x3f3f3f3f;
const int P4[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

int N,M,K;
char S[MX][MX];
struct Pt
{
	int x,y;
	Pt(){}
	Pt(int x_,int y_){x=x_,y=y_;}
};

bool Check(int x,int y)
{
	return 1<=x&&x<=N&&1<=y&&y<=M;
}

int D[MX][MX];
int bfs(int sx,int sy,int tx,int ty)
{
	memset(D,0x3f,sizeof(D));
	queue<Pt> Q;
	Q.push(Pt(sx,sy)),D[sx][sy]=0;
	while(!Q.empty())
	{
		Pt p=Q.front();Q.pop();
		if(p.x==tx&&p.y==ty)return D[p.x][p.y];
		Fo(k,0,4)
		{
			int x=p.x,y=p.y;
			Fr(i,1,K)
			{
				x+=P4[k][0],y+=P4[k][1];
				if(!Check(x,y)||S[x][y]=='#'||D[x][y]<=D[p.x][p.y])break;
				if(D[x][y]>D[p.x][p.y]+1)
					Q.push(Pt(x,y)),D[x][y]=D[p.x][p.y]+1;
			}
		}
	}
	return -1;
}

int main()
{
	scanf("%d%d%d",&N,&M,&K);
	Fr(i,1,N)scanf("%s",S[i]+1);
	int sx,sy,tx,ty;
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	printf("%d\n",bfs(sx,sy,tx,ty));
	return 0;
}