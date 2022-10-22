#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <deque>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
#define Fe(i,x) for(int i=H[x];i;i=E[i].nx)
using namespace std;
typedef long long ll;
const int MX=5100000,MY=1100;
const int Inf=0x3f3f3f3f;
const int Up=0,Down=1,Left=2,Right=3,Z=4;
struct Edge{int y,w,nx;}E[MX*3];
int H[MX],ec;
void Add(int x,int y,int w)
	{E[++ec].y=y,E[ec].w=w,E[ec].nx=H[x],H[x]=ec;}

int N,M;
inline int Pos(int x,int y,int z){return z*N*M+(x-1)*M+y;}

char G[MY][MY];

int S,T;

#define y E[i].y
#define w E[i].w
char B[MX];
int D[MX];
deque<int> Q;
void Dijkstra()
{
	Fill(D,0x3f);
	Q.push_back(S),D[S]=0;
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop_front();
		if(B[x])continue;
		B[x]=1;
		Fe(i,x)if(D[y]>D[x]+w)
		{
			D[y]=D[x]+w;
			if(w)Q.push_back(y);
			else Q.push_front(y);
		}
	}
}
#undef y
#undef w

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%s",G[i]+1);
	Fr(x,1,N)Fr(y,1,M)
	{
		if(x>1)Add(Pos(x,y,Up),Pos(x-1,y,Up),0);
		if(x<N)Add(Pos(x,y,Down),Pos(x+1,y,Down),0);
		if(y>1)Add(Pos(x,y,Left),Pos(x,y-1,Left),0);
		if(y<M)Add(Pos(x,y,Right),Pos(x,y+1,Right),0);
	}
	Fr(x,1,N)Fr(y,1,M)if(G[x][y]=='#')
		Fr(z,0,3)
			Add(Pos(x,y,z),Pos(x,y,Z),1),
			Add(Pos(x,y,Z),Pos(x,y,z),0);
	S=Pos(N,M,Left),T=Pos(1,1,Left);
	Dijkstra();
	printf("%d\n",(D[T]==Inf?-1:D[T]));
	return 0;
}