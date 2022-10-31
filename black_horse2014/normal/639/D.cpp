#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

int n, K, b, c;
VPII v[5];
multiset<LL> S;

LL solve(int mod) {
	sort(all(v[mod]));
	
	S.clear();
	LL ret = LL(1e18), sum = 0;
	for (int i = 0; i < sz(v[mod]); i++) {
		int t = v[mod][i].X;
		int cst = v[mod][i].Y;
		LL cc = cst + (LL)b * (mod - t) / 5;
		sum += cc;
		S.insert(cc);
		
		if (S.size() > K) {
			sum -= *(--S.end());
			S.erase(--S.end());	
		}
		if (S.size() == K) {
			chkmin(ret, sum + (LL)K * b * (t - mod) / 5);	
		}
	}
	return ret;
}

int main() {

	scanf("%d%d%d%d", &n, &K, &b, &c);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		for (int j = 0; j < 5; j++) {
			v[((x + j) % 5 + 5) % 5].push_back(PII(x + j, c * j));
		}
	}
	if (b >= 5 * c) {
		b = 5 * c;
	}
	
	LL ans = LL(1e18);
	for (int i = 0; i < 5; i++) {
		chkmin(ans, solve(i));
	}
	printf("%lld\n", ans);
	
	return 0;
}