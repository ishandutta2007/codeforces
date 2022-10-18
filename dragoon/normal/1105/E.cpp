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
#include<unordered_map>
#include<unordered_set>
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
typedef vector<LL> VL;
typedef vector<PII > VP;
typedef vector<double> VD;
typedef vector<LL> VL;
typedef long double ld;

set<int> adj[50];
bitset<40> adjB[50];

map<string, int> M;
int n, m;
int ans;

void bktk(bitset<40> B, int taken, int st = 0) {
	int best = m - B.count() + taken;
	if (best <= ans) return;
	ans = MAX(ans, taken);
	if (B.count() == m) return;
	for (int i = st; i < m; i++) {
		if (B.test(i)) continue;
		bitset<40> C = B;
		C |= adjB[i];
		C.set(i);
		bktk(C, taken + 1, i + 1);
		B.set(i);
	}
}

void solve(int ks) {
	scanf("%d %d", &n, &m);
	set<int> V;
	int cnt = 0;
	while(n--) {
		int now; char name[100];
		scanf("%d", &now);
		if (now == 1) {
			if (V.empty()) continue;
			for (int i : V) for (int j : V) {
				if (i != j) {
					adj[i].insert(j);
					adj[j].insert(i);
				}
			}
			V.clear();
			continue;
		}
		scanf("%s", name);
		if (M.find(name) == M.end()) M[name] = ++cnt;
		V.insert(M[name]);
	}
	for (int i : V) for (int j : V) {
		if (i != j) {
			adj[i].insert(j);
			adj[j].insert(i);
		}
	}


	{
		VI V;
		for (int i = 1; i <= m; i++) {
			V.push_back(i - 1);
		}
		random_shuffle(ALL(V));
		set<int> a[50];
		for (int i = 1; i <= m; i++) {
			for (int j : adj[i]) {
				a[i].insert(V[j - 1]);
			}
		}
		for (int i = 0; i < m; i++) {
			adj[V[i]] = a[i + 1];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j : adj[i]) adjB[i].set(j);
	}
	bktk(0, 0);
	printf("%d\n", ans);
}

int main()
{
#ifdef LOCAL
	double start_time = clock();
	freopen("C:\\Home\\ContestCodes\\sample.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
#endif

	if (0) {
		int T;
		scanf("%d", &T);
		for (int ks = 1; ks <= T; ks++) solve(ks);
	}
	else {
		solve(0);
	}

#ifdef LOCAL
	double end_time = clock();
	fprintf(stderr, "Time = %lf\n", (end_time - start_time) / CLOCKS_PER_SEC);
#endif

	return 0;
}