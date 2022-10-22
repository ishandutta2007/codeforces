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
const int MX=2e5+100;
const ll Inf=0x3f3f3f3f3f3f3f3f;

int N;
ll A[MX],X[MX],E[MX][2],F[MX];


int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	Fr(i,1,N)X[i]=A[i]-X[i-1];
//	Fr(i,1,N)printf("%lld ",X[i]);printf("\n");
	E[N+1][0]=E[N+1][1]=F[0]=Inf;
	Fl(i,N,1)
	{
		E[i][0]=E[i+1][0];
		E[i][1]=E[i+1][1];
		E[i][i&1]=min(E[i][i&1],X[i]);
	}
	Fr(i,1,N)F[i]=min(F[i-1],X[i]);
//	Fr(i,1,N)printf("%lld ",E[i][0]);printf("\n");
//	Fr(i,1,N)printf("%lld ",E[i][1]);printf("\n");
	if(E[1][0]>=0&&E[1][1]>=0&&X[N]==0){printf("YES\n");return 0;}
	Fr(i,2,N)
	{
		ll delta=A[i]-A[i-1];
		ll L=F[i-2];
		ll M=X[i-1]+delta;
		ll m0=E[i][i&1]-2*delta;
		ll m1=E[i][(i&1)^1]+2*delta;
		ll R=((N-i)&1)?X[N]+2*delta:X[N]-2*delta;
//		printf("%lld %lld %lld %lld\n",L,m0,m1,R);
		if(L>=0&&M>=0&&m0>=0&&m1>=0&&R==0){printf("YES\n");return 0;}
	}
	printf("NO\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		mian();
		Fr(i,1,N+1)E[i][0]=E[i][1]=0;
	}
}