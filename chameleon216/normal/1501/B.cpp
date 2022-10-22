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
const int MX=222222;
int N,A[MX],C[MX];
void Add(int l,int r){++C[l],--C[r+1];}

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",A+i);
	Fr(i,1,N)Add(max(1,i-A[i]+1),i);
	Fr(i,1,N)C[i]+=C[i-1];
	Fr(i,1,N)printf("%d ",C[i]>0);
	putchar('\n');
	Fr(i,0,N+1)C[i]=A[i]=0;
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}