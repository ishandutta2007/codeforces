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
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>

using namespace std;

typedef unsigned int uint;
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;
typedef long double LD;

#define pb push_back
#define mset(a, b) (memset(a, b, sizeof a))
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define X first
#define Y second

template <typename T, typename U>
inline void chkmax(T& x, U y) {
    if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
    if (y < x) x = y;
}
vector<PLI> V;
void solve(LL A, LL B) {
	int flg = 0;
	if (A <= B) {
		swap(A, B);
		flg = 1;
	}

	for (int i = 0; ; i++) {
		LL c = A / B;
		A %= B, swap(A, B);

		V.pb(PLI(c, flg));
		flg ^= 1;
		if (B == 0) return;
	}
}

int main() {

	LL A, B;
	scanf("%I64d%I64d", &A, &B);
	if (__gcd(A, B) != 1) {
		puts("Impossible");
		return 0;
	}

	solve(A, B);
	for (int i = 0; i < V.size() - 1; i++) printf("%I64d%c", V[i].X, (V[i].Y == 1) ? 'B' : 'A');
	if (V.back().X > 1) printf("%I64d%c", V.back().X - 1, (V.back().Y == 1) ? 'B' : 'A');
	puts("");

	return 0;
}