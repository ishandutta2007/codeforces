#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

template<typename T,typename U>
void max_eq(T& a,const U& b){if(a<b)a=b;}
template<typename T,typename U>
void min_eq(T& a,const U& b){if(b<a)a=b;}

const int MX=2100,Inf=0x3f3f3f3f;
const int F[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int N,M;
char G[MX][MX];

bool Check(int x,int y)
{
	if(G[x+1][y]=='.'&&G[x][y+1]=='.'&&G[x+1][y+1]=='.')return 1;
	if(G[x-1][y]=='.'&&G[x][y+1]=='.'&&G[x-1][y+1]=='.')return 1;
	if(G[x+1][y]=='.'&&G[x][y-1]=='.'&&G[x+1][y-1]=='.')return 1;
	if(G[x-1][y]=='.'&&G[x][y-1]=='.'&&G[x-1][y-1]=='.')return 1;
	return 0;
}

void dfs(int x,int y)
{
	if(G[x][y]!='*'||!Check(x,y))return;
	G[x][y]='.';
	Fo(k,0,8)dfs(x+F[k][0],y+F[k][1]);
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%s",G[i]+1);
	Fr(x,1,N)Fr(y,1,M)dfs(x,y);
	Fr(i,1,N)printf("%s\n",G[i]+1);
	return 0;
}