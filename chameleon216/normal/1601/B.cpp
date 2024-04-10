#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <queue>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=300100;
int N,A[MX],B[MX];
queue<int> Q;
int D[MX],F[MX];

void bfs()
{
	memset(D,0xff,sizeof(D));
	Q.push(N),D[N]=0;
	int p=N-1;
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		int y=x+B[x];
		while(p>=y-A[y])
			D[p]=D[x]+1,F[p]=x,Q.push(p--);
	}
}

int stk[MX],tp;

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,N)scanf("%d",&B[i]);
	bfs();
	printf("%d\n",D[0]);
	if(D[0]!=-1)
	{
		for(int x=0;x!=N;x=F[x])stk[++tp]=x;
		while(tp)printf("%d ",stk[tp--]);
		putchar('\n');
	}
	return 0;
}