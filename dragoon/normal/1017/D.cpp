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
#define FORN(i, n) for(int i = 0; i < n; i++)
#define FORAB(i, a, b) for(int i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
typedef long long int LL;
//typedef __int64 LL;

LL INF = 1000000009;

typedef pair<int,int> PII;
typedef pair<LL, LL> PLL;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;

int n, q, m, extra;
int w[20], Sw[1<<13];
char S[100];
VI bucket[1 << 6];

int ans[64][64][102];

void process(int upper) {
	VI cnt(64, 0);
	for (int i : bucket[upper]) cnt[i]++;
	for (int mask = 0; mask < 64; mask++) {
		for (int i = 0; i < 64; i++) {
			int match = (i ^ mask ^ 63);
			int cost = Sw[match];
			if (cost > 100) continue;
			ans[upper][mask][cost]+=cnt[i];
		}
		for (int i = 0; i < 100; i++) {
			ans[upper][mask][i + 1] += ans[upper][mask][i];
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d %d %d", &n, &m, &q) != EOF) {
		CLR(Sw);
		CLR(w);
		for (int i = 0; i < 64; i++) bucket[i].clear();
		CLR(ans);

		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}
		for (int i = 0; i < (1 << 12); i++) {
			int sum = 0;
			for (int j = 0; j < 12; j++) {
				if (i & (1 << j)) {
					sum += w[j];
				}
			}
			Sw[i] = sum;
		}

		for (int i = 0; i < m; i++) {
			scanf("%s", S);
			int mask = 0;
			for (int j = 0; j < n; j++) {
				mask |= (S[j] - '0') << j;
			}

			int upper = mask >> 6;
			int lower = mask & 63;

			bucket[upper].push_back(lower);
		}

		for (int i = 0; i < 64; i++) {
			process(i);
		}

		while (q--) {
			int k, mask = 0;
			scanf("%s %d", S, &k);
			for (int j = 0; j < n; j++) {
				mask |= (S[j] - '0') << j;
			}

			int upper = mask >> 6;
			int lower = mask & 63;

			int ret = 0;
			for (int i = 0; i < 64; i++) {
				int match = (i ^ upper ^ 63) << 6;
				int remaining_cost = k - Sw[match];
				if (remaining_cost < 0) continue;
				ret += ans[i][lower][remaining_cost];
			}
			printf("%d\n", ret);
		}
	}
	return 0;
}