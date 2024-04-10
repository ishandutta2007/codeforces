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

const int MAXN = 222222;
LL l[MAXN], t[MAXN];
LL s[MAXN];
LL r;

int main() {

	int n;
	int f = 0;
	scanf("%d%lld", &n, &r);
	for (int i = 0; i < n; i++) scanf("%lld", l + i);
	for (int i = 0; i < n; i++) {
		scanf("%lld", t + i);
		if (l[i] > t[i]) f = 1;
	}
	if (f) {
		puts("-1");
		return 0;
	}
	LL k = 1;
	s[0] = 0;
	int pos = 0;
	LL pot = 0;
	LL rem = 0;
	while (pos < n) {
		if (rem >= l[pos]) {
			rem -= l[pos];
			pot += l[pos];
			pos++;
			continue;
		}
		if ((l[pos] - rem) * 2 + rem <= t[pos]) {
			pot += (l[pos] - rem) * 2 + rem;
			pos++;
			rem = 0;
		} else {
			LL x = t[pos] - l[pos], y = -t[pos] - rem + l[pos] * 2;
			k += (y + r - 1) / r;
			rem = (r - (y % r)) % r;
			pos++;
		}
	}
	if (k - 1 > 100000) {
		cout<<k - 1<<endl;
		return 0;
	}
	k = 1;
	s[0] = 0;
	pos = 0;
	pot = 0;
	rem = 0;
	while (pos < n) {
		if (rem >= l[pos]) {
			rem -= l[pos];
			pot += l[pos];
			pos++;
			continue;
		}
		if ((l[pos] - rem) * 2 + rem <= t[pos]) {
			pot += (l[pos] - rem) * 2 + rem;
			pos++;
			rem = 0;
		} else {
			LL x = t[pos] - l[pos], y = -t[pos] - rem + l[pos] * 2;
			s[k++] = pot + rem + x * 2;
			y -= r;
			while (y > 0) {
				s[k] = s[k - 1] + r;
				k++;
				y -= r;
			}
			rem = -y;
			pot += t[pos];
			pos++;
		}
	}
	cout<<k - 1<<endl;
	for (int i = 1; i < k; i++) printf("%lld%c", s[i], (i < k - 1) ? ' ':'\n'); 
	return 0;
}