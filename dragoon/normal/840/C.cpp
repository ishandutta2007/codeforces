//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include <ctime>
#include<list>
#include <numeric>
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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int128 LL;
//typedef __int64 LL;

typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<long double, long double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;

typedef long double ld;

int ncr[603][603];
LL dp[603][603];
const int MOD = 1000000007;
int n; map<int, int> M;
LL fact[603];

int process(int a) {
	int ret = 1;
	if (a == 1) return 1;
	for (int i = 2; i * i <= a; i++) {
		if (a % i) continue;
		int cnt = 0;
		while (a % i == 0) a /= i, cnt++;
		if (cnt & 1) ret *= i;
	}
	if (a > 1) ret *= a;
	return ret;
}

LL bigmod(LL a, LL n) {
	if (n == 0) return 1;
	LL x = bigmod(a, n / 2);
	x = (x * x) % MOD;
	if (n & 1) x = (x * a) % MOD;
	return x;
}

void solve() {
	fact[0] = 1;
	for (int i = 1; i <= 602; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	ncr[0][0] = 1;
	int limncr = 602;
	for (int i = 1; i <= limncr; i++) {
		for (int j = 0; j <= limncr; j++)
		{
			if (j > i) ncr[i][j] = 0;
			else if (j == i || j == 0) ncr[i][j] = 1;
			else {
				ncr[i][j] = ncr[i - 1][j - 1] + ncr[i - 1][j];
				if (ncr[i][j] >= MOD) ncr[i][j] -= MOD;
			}
		}
	}

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		int aa = process(a);
		M[aa]++;
	}

	int all = 1, same = 0;
	dp[all - same][same] = 1;
	LL extra = 1;
	for (auto& p : M) {
		int cnt = p.second;
		extra *= fact[cnt];
		extra %= MOD;

		for (int j = 0; j <= same; j++) {
			int i = all - j;
			for (int s = 1; s <= cnt; s++) {
				for (int t = 0; t <= s; t++) {
					// t dhukbe i te
					// s - t dhukbe j te
					if (t > i || s - t > j) continue;
					LL way = ncr[cnt - s + s - 1][s - 1];
					way *= ncr[i][t];
					way %= MOD;
					way *= ncr[j][s - t];
					way %= MOD;

					int new_all = all + cnt;
					int new_same = j /* prev */ + cnt /* new */ - s /* num split */ - (s - t) /* splitting old */;
					dp[new_all - new_same][new_same] += dp[all - j][j] * way;
					dp[new_all - new_same][new_same] %= MOD;
				}
			}
		}
		all += cnt;
		same += cnt - 1;
	}

	extra *= dp[all][0];
	extra %= MOD;

	printf("%lld\n", extra);
}

int main()
{
	double start_time = clock();
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	solve();


	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);

	return 0;
}