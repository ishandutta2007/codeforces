#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int N,M,deg[MX];
vector<int> G[MX];

struct Node
{
	int x,d;
	Node(){}
	Node(int x_,int d_){x=x_,d=d_;}
};
inline bool operator<(const Node& a,const Node& b){return a.d>b.d;}
priority_queue<Node> Q;
char B[MX];
int D[MX],cnt[MX];

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		G[y].push_back(x),++deg[x];
	}
	memset(D,0x3f,sizeof(D)),D[N]=0;
	Q.push(Node(N,0));
	while(!Q.empty())
	{
		int x=Q.top().x;
		Q.pop();
		if(B[x])continue;
		B[x]=1;
		for(int y:G[x])
		{
			++cnt[y];
			int d=D[x]+1+deg[y]-cnt[y];
			if(d<D[y])D[y]=d,Q.push(Node(y,D[y]));
		}
	}
	printf("%d\n",D[1]);
	return 0;
}