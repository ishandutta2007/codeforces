#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;

const int MX=150;

int A[MX],B[MX],N,M;

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",A+i);
	scanf("%d",&M);
	Fr(i,1,M)scanf("%d",B+i);
	Fr(i,1,N)A[i]+=A[i-1];
	Fr(i,1,M)B[i]+=B[i-1];
	//Fr(i,1,N){Fr(j,1,M)printf("%d ",A[i]+B[j]);printf("\n");}
	int mxa=0,mxb=0;
	Fr(i,1,N)mxa=max(mxa,A[i]);
	Fr(i,1,M)mxb=max(mxb,B[i]);
	printf("%d\n",mxa+mxb);
	return 0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}