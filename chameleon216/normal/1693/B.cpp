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

const int MX=200100;
int N,F[MX];
ll L[MX],R[MX],V[MX];

void Solve()
{
	scanf("%d",&N);
	Fr(i,2,N)scanf("%d",&F[i]);
	Fr(i,1,N)scanf("%lld%lld",&L[i],&R[i]);
	int c=0;
	Fl(i,N,1)
	{
		if(V[i]<L[i])++c,V[i]=R[i];
		V[i]=min(V[i],R[i]);
		V[F[i]]+=V[i];
	}
	printf("%d\n",c);
	Fr(i,1,N)F[i]=L[i]=R[i]=V[i]=0;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)Solve();
	return 0;
}