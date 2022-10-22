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
using namespace std;
typedef long long ll;

template<typename T1,typename T2>
inline void max_eq(T1& a,T2 b){if(a<b)a=b;}
template<typename T1,typename T2>
inline void min_eq(T1& a,T2 b){if(b<a)a=b;}

const int MX=310,MY=MX*MX;
const int E[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int N,M,P,G[MX][MX];
ll dp[MX][MX];

inline bool Check(int x,int y)
{
	return 1<=x&&x<=N&&1<=y&&y<=M;
}

struct Node
{
	int x,y;
	Node(){}
	Node(int x_,int y_){x=x_,y=y_;}
};
int Dis(Node a,Node b){return abs(a.x-b.x)+abs(a.y-b.y);}
vector<Node> V[MY];

ll D[MX][MX];
inline bool operator<(const Node& a,const Node &b)
{
	return dp[a.x][a.y]<dp[b.x][b.y];
}

int main()
{
	scanf("%d%d%d",&N,&M,&P);
	Fr(i,1,N)Fr(j,1,M)
	{
		scanf("%d",&G[i][j]);
		V[G[i][j]].push_back(Node(i,j));
	}
	memset(dp,0x3f,sizeof(dp));
	int zs=V[1].size();
	Fo(i,0,zs)
	{
		Node s=V[1][i];
		dp[s.x][s.y]=Dis(s,Node(1,1));
	}
	Fo(i,1,P)
	{
		vector<Node> &va=V[i],&vb=V[i+1];
		int za=V[i].size(),zb=V[i+1].size();
		if((ll)za*zb<=4*N*M)
		{
			Fo(j,0,za)Fo(k,0,zb)
			{
				Node a=va[j],b=vb[k];
				min_eq(dp[b.x][b.y],dp[a.x][a.y]+Dis(a,b));
			}
		}
		else
		{
			memset(D,0x3f,sizeof(D));
			queue<Node> q1,q2;
			sort(va.begin(),va.end());
			Fo(j,0,za)
			{
				Node a=va[j];
				q1.push(a),D[a.x][a.y]=dp[a.x][a.y];
			}
			while(!(q1.empty()&&q2.empty()))
			{
				Node a;
				if(q1.empty())a=q2.front(),q2.pop();
				else if(q2.empty())a=q1.front(),q1.pop();
				else
				{
					Node b1=q1.front(),b2=q2.front();
					if(D[b1.x][b1.y]<D[b2.x][b2.y])a=b1,q1.pop();
					else a=b2,q2.pop();
				}
				Fo(k,0,4)
				{
					int x=a.x+E[k][0],y=a.y+E[k][1];
					if(!Check(x,y))continue;
					if(D[x][y]>D[a.x][a.y]+1)
					{
						D[x][y]=D[a.x][a.y]+1;
						q2.push(Node(x,y));
					}
				}
			}
			Fo(j,0,zb)
			{
				Node b=vb[j];
				dp[b.x][b.y]=D[b.x][b.y];
			}
		}
	}
	Node p=V[P][0];
	printf("%lld\n",dp[p.x][p.y]);
	return 0;
}