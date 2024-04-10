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
int N,A[MX];

int Work()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	sort(A+1,A+N+1);
	Fr(i,1,N/2)printf("%d %d\n",A[i+1],A[1]);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)Work();
	return 0;
}