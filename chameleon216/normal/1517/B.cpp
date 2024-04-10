#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;

int N,M;
int A[200][200];

int mian()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)Fr(j,1,M)scanf("%d",&A[i][j]);
	Fr(k,1,M)
	{
		int x=1,y=k;
		Fr(i,1,N)Fr(j,k,M)
			if(A[x][y]>A[i][j])x=i,y=j;
		swap(A[x][y],A[x][k]);
		Fr(i,1,N)if(i!=x)
			swap(A[i][k],*max_element(A[i]+k,A[i]+M+1));
	}
	Fr(i,1,N){Fr(j,1,M)printf("%d ",A[i][j]);putchar('\n');}
	Fr(i,1,N)Fr(j,1,M)A[i][j]=0;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)mian();
}