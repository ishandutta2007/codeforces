#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=200100,W=1000005;

char B[W+100];
int P[MX],pc;
void Euler()
{
	B[0]=B[1]=1;
	Fr(i,2,W)
	{
		if(!B[i])P[++pc]=i;
		Fr(j,1,pc)
		{
			int p=P[j];
			if(i*p>W)break;
			B[i*p]=1;
			if(i%p==0)break;
		}
	}
}

int N,E,A[MX];
int C[MX];
void mian()
{
	scanf("%d%d",&N,&E);
	Fr(i,1,N)scanf("%d",&A[i]);
	ll sum=0;
	Fr(i,1,E)
	{
		int cc=0,c=1;
		for(int j=i;j<=N;j+=E,++c)
			if(A[j]!=1)C[++cc]=c;
		C[0]=0,C[cc+1]=c;
//		printf("C ");Fr(j,0,cc+1)printf("%d ",C[j]);putchar('\n');
		Fr(j,1,cc)if(B[A[i+(C[j]-1)*E]]==0)
			sum+=(ll)(C[j]-C[j-1])*(C[j+1]-C[j])-1;
//		printf("sum=%lld\n",sum);
	}
	printf("%lld\n",sum);
}

int main()
{
	Euler();
	int t;
	scanf("%d",&t);
	Fr(i,1,t)
	{
		mian();
		Fr(j,1,N)A[j]=0;
	}
	return 0;
}