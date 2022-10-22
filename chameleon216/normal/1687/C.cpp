#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=200100;
int N,M,A[MX],B[MX];
vector<int> V[MX];
ll S[MX];
int F[MX];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}
queue<int> Q;
void Fill(int l,int r)
{
	if(l>r)swap(l,r);
	for(int i=Find(l);i<=r;i=Find(i))
		F[i]=i+1,S[i]=0,Q.push(i);
}

void Work()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,N)scanf("%d",&B[i]);
	Fr(i,1,N)S[i]=S[i-1]+B[i]-A[i];
	Fr(i,0,N+1)F[i]=i;
	Fr(i,1,M)
	{
		int l,r;
		scanf("%d%d",&l,&r),--l;
		V[l].push_back(r);
		V[r].push_back(l);
	}
	Fr(i,0,N)if(S[i]==0)
	{
		Q.push(i);
		F[i]=i+1;
	}
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int r:V[x])if(S[r]==0)Fill(x,r);
		
//		Fr(i,0,N)printf("%lld ",S[i]);putchar('\n');
	}
	if(Find(0)<=N)printf("NO\n");
	else printf("YES\n");
	
	Fr(i,0,N)S[i]=F[i]=0,V[i].clear();
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)Work();
	return 0;
}