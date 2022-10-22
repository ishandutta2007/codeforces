#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=200100,Inf=0x3f3f3f3f;
int N,M;
int A[MX],B[MX];
int F[MX];

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,0,N-1)scanf("%d",&A[i]);
	Fl(i,N-1,1)A[i]-=A[i-1];
	Fr(i,0,M-1)scanf("%d",&B[i]);
	Fl(i,M-1,1)B[i]-=B[i-1];
	if(M==1){printf("%d\n",N);return 0;}
	
	F[0]=-1,B[M]=Inf;
	int j=-1;
	Fr(i,1,M-1)
	{
		while(j!=-1 and B[j+1]!=B[i])j=F[j];
		F[i]=++j;
	}
	int cnt=0;
	j=0;
	Fr(i,1,N-1)
	{
		while(j!=-1 and B[j+1]!=A[i])j=F[j];
		if(++j==M-1)++cnt;
	}
	printf("%d\n",cnt);
	return 0;
}