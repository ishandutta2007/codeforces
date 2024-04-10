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

const int MX=100100;
int N,K,A[MX],ac;

int main()
{
	scanf("%d%d",&N,&K);
	if(!K)
	{
		Fr(i,1,N)printf("%d %d ",N+i,i);
		putchar('\n');
	}
	else
	{
		Fr(i,2,2*N)if(i!=1+K)A[++ac]=i;
		printf("%d %d ",1,1+K);
		Fr(i,1,ac>>1)printf("%d %d ",A[(ac>>1)+i],A[i]);
		putchar('\n');
	}
	return 0;
}