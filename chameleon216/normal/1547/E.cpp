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


const int MX=300100,Inf=0x3f3f3f3f;

int N,M;
int P[MX];
int X[MX],A[MX],B[MX];


int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&M);
		memset(X,0x3f,(N+1)*sizeof(int));
		Fr(i,1,M)scanf("%d",&P[i]);
		int e;
		Fr(i,1,M)scanf("%d",&e),X[P[i]]=e;
		A[0]=B[N+1]=Inf;
		Fr(i,1,N)A[i]=min(A[i-1]+1,X[i]);
		Fl(i,N,1)B[i]=min(B[i+1]+1,X[i]);
		Fr(i,1,N)printf("%d ",min(A[i],B[i]));
		putchar('\n');
	}
	return 0;
}