#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=30000;
int N;
ll U,V;
int A[MX];

int Abs(int x){return x>=0?x:-x;}

int mian()
{
	scanf("%d%lld%lld",&N,&U,&V);
	Fr(i,1,N)scanf("%d",A+i);
	Fr(i,2,N)if(Abs(A[i]-A[i-1])>=2){printf("0\n");return 0;}
	Fr(i,2,N)if(Abs(A[i]-A[i-1])>=1){printf("%lld\n",min(U,V));return 0;}
	printf("%lld\n",V+min(U,V));return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fr(i,1,N)A[i]=0;
		N=U=V=0;
	}
	return 0;
}