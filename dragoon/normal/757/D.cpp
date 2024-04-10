#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<list>
#include<bitset>
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
#include<assert.h>
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
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

char word[100];
int next_nz[100];
LL MOD = 1000000007;
int dp[76][1 << 20];
int n;

int DP(int at, int mask) {
	int &ret = dp[at][mask];
	if (ret != -1) return ret;

	ret = 0;
	if (mask) {
		if ((mask & (mask + 1)) == 0)
			ret++; // end here
	}

	int np = next_nz[at];
	if (np == n) {
		return ret;
	}

	LL here = ret;
	int now = 1;
	for (int i = np; i < n; i++) {
		here += DP(i + 1, mask | (1<<(now-1)));
		now <<= 1;
		if (i + 1 < n) now |= word[i + 1] - '0';
		if (now > 20) break;
	}
	here %= MOD;
	ret = here;

	return ret;
}

int main()
{
	MEM(dp, -1);

	scanf("%d", &n);
	scanf("%s", word);
	next_nz[n] = n;
	for (int i = n - 1; i >= 0; i--) {
		next_nz[i] = next_nz[i + 1];
		if (word[i] != '0') {
			next_nz[i] = i;
		}
	}

	LL ans = 0;
	for (int i = 0; i < n; i++) {
		ans += DP(i, 0);
	}
	ans %= MOD;
	printf("%I64d\n", ans);

	return 0;
}