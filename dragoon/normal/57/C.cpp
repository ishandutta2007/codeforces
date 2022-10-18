#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,y1,x2,y2) (sqrt( S((x1)-(x2)) + S((y1)-(y2)) ))
#define EPS 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )

typedef pair<int,int> PII;
typedef __int64 LL;

//int dr[]={0,0,1,-1,-1,-1,1,1};
//int dc[]={1,-1,0,0,1,-1,1,-1};

LL f[200004];
LL MOD = 1000000007;

LL bigmod(LL a, LL n)
{
	if(n==0) return 1;
	LL x = bigmod(a,n/2);
	x=(x*x)%MOD;
	if(n%2==1) x=(x*a)%MOD;
	return x;
}

LL INV(LL X)
{
	return bigmod(X,MOD-2);
}

int main()
{
	int i,n;
	LL ans;

	f[0]=1;
	for(i=1;i<=200000;i++)
		f[i]=(f[i-1]*i)%MOD;

	scanf("%d",&n);

	ans = (2*f[2*n-1])%MOD;
	ans = ans*INV( (f[n]*f[n-1])%MOD );
	ans = (ans + MOD - n)%MOD;

	printf("%I64d\n",ans);

	return 0;
}