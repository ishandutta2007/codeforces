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

const int MAXN = 155555;

int n, K, q;
int t[MAXN], val[MAXN];
int id[MAXN], _id[MAXN];

bool cmp(int i, int j) {
	return t[i] < t[j];
}

void add(int x, int v) {
	for (; x <= n; x += x & -x) val[x] += v;
}

int get(int x, int y) {
	int ret = 0;
	x--;
	for (; x; x -= x & -x) ret -= val[x];
	for (; y; y -= y & -y) ret += val[y];
	return ret;
}

int main() {
	
	scanf("%d%d%d", &n, &K, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", t + i);
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		_id[id[i]] = i;
	}
	while (q--) {
		int tp, x;
		scanf("%d%d", &tp, &x);
		if (tp == 1) {
			add(_id[x], 1);
		} else {
			printf("%s\n", get(_id[x], _id[x]) == 1 && get(_id[x], n) <= K ? "YES" : "NO");
		}
	}
	
	return 0;
}