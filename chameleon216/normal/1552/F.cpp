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
const int MX=400100,P=998244353;
int N,X[MX],Y[MX],Z[MX];
int U[MX],uc;
int J[MX],B[MX];
ll S[MX],dp[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		U[++uc]=X[i],U[++uc]=Y[i];
	}
	U[++uc]=0,U[++uc]=X[N]+1;
	
	sort(U+1,U+uc+1);
	uc=unique(U+1,U+uc+1)-U-1;
	
	Fr(i,1,N)
	{
		int x=lower_bound(U+1,U+uc+1,X[i])-U;
		J[x]=lower_bound(U+1,U+uc+1,Y[i])-U;
		B[x]=Z[i];
	}
	Fr(i,1,uc)if(!J[i])J[i]=i;
	Fo(i,1,uc)
	{
		dp[i]=(S[i-1]-S[J[i]-1]+P+U[i+1]-U[i]+P)%P;
		S[i]=(S[i-1]+dp[i])%P;
	}
	
	ll sum=0;
	Fo(i,1,uc)sum+=B[i]?dp[i]:U[i+1]-U[i],sum%=P;
	printf("%lld\n",sum);
	return 0;
}