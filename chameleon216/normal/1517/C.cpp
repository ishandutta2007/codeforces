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
const int MX=600;
int N;
int A[MX][MX];


int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[1][i]);
	Fr(i,2,N)
	{
		int c=0;
		Fr(j,1,N-i+2)if(A[i-1][j]!=i-1)
			A[i][++c]=A[i-1][j];
	}
	Fr(i,1,N)
	{
		Fr(j,1,i)printf("%d ",A[i-j+1][j]);
		//Fr(j,1,N-i+1)printf("%d ",A[i][j]);
		putchar('\n');
	}
	return 0;
}