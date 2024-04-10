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
#include<cmath>
#include<stack>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)

typedef pair<int,int> PII;
typedef pair<double, double> PDD;

//typedef int LL;
typedef __int64 LL;

int check(LL sum, int a, int b)
{
	while(sum)
	{
		int d = sum%10;

		if(d!=a && d!=b)
			return 0;
		sum /= 10;
	}

	return 1;
}

LL MOD = 1000000007;
LL fact[1000006];

LL BIGMOD(LL a, LL b)
{
	if(b==0) return 1;
	LL x = BIGMOD(a, b/2);
	x = (x*x)%MOD;
	if(b&1) x = (x*a)%MOD;
	return x;
}

LL ncr(LL n, LL r)
{
	LL ret = fact[n];

	ret = (ret * BIGMOD(fact[r], MOD-2))%MOD;
	ret = (ret * BIGMOD(fact[n-r], MOD-2))%MOD;
	return ret;
}


int main()
{
	LL n;
	int a, b;
	int i, x, y;
	LL sum, ans = 0;
	
	scanf("%d%d%I64d",&a,&b,&n);

	fact[0] = 1;
	for(i = 1; i <= n; i++)
		fact[i] = (fact[i-1]*i)%MOD;

	for(x = 0; x <= n; x++)
	{
		y = n-x;

		sum = a*x + b*y;

		if(!check(sum, a, b))
			continue;

		ans = (ans + ncr(n, x))%MOD;
	}

	printf("%I64d\n", ans);

	return 0;
}