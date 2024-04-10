#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
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

long long p, q;
int b;

long long get(long long st, long long en, long long cnt) {
	for (int i = b-1; i >= 0; i--) {
		long long mid = st + en >> 1;
		if (bitl(i) >= cnt) {
			en = mid;
		} else {
			cnt -= bitl(i);
			st = mid;
		}
	}
	return (st + en) / 2;
}

long long query(long long st, long long en, int f, long long cnt) {
	long long ans = 0;
	for (int i = b-1; i >= 0; i--) {
		long long mid = st + en >> 1;
		long long del = mid - st - p * bitl(i);
		if (!f) del = bitl(i) - del;
		if (del >= cnt) {
			en = mid;
		} else {
			cnt -= del;
			st = mid;
			ans += bitl(i);
		}
	}
	return ans + 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	long long n, m; cin >> n >> m;
	if (m == 1) {
		puts("1");
		return 0;
	}
	if (m == 2) {
		cout << n << endl;
		return 0;
	}
	p = n - 1, q = n;
	for (int i = 1; i <= 60; i++) {
		if (bitl(i) < m-1) {
			p = p >> 1, q = (q + 1) >> 1;
			long long y = n - 1 - bitl(i) * p;
			long long t = (y == 0 ? p / 2 : q / 2);
			if (p == 3 && y > 0) {
				long long st = 1, en = n, cnt = m - 1 - bitl(i);
				if (m - 1 - bitl(i) > y) {
					long long cnt = m - 1 - bitl(i) - y;
					for (int j = i - 1; j >= 0; j--) {
						long long mid = st + en >> 1;
						long long del = bitl(j + 1);
						if (del >= cnt) en = mid;
						else cnt -= del, st = mid;
					}
					if (cnt == 2) cout << en - 1 << endl;
					if (cnt == 1) cout << st + 1 << endl;
					return 0;
				}
			} else if (t == 1) {
				long long st = 1, en = n, cnt = m - 1 - bitl(i);
				for (int j = i - 1; j >= 0; j--) {
					long long mid = st + en >> 1;
					if (mid - st - bitl(j) >= cnt) en = mid;
					else cnt -= mid - st - bitl(j), st = mid;
				}
				while (cnt--) st = st + en >> 1;
				cout << st << endl;
				return 0;
			}
		} else {
			b = i - 1;
			if (p / 2 == q / 2) {
				cout << get(1, n, m - 1 - bitl(b)) << endl;
			} else {
				long long y = n - 1 - p * bitl(b);
				if (m - 1 - bitl(b) <= y) {
					cout << get(1, n, query(1, n, 1, m - 1 - bitl(b))) << endl;
				} else {
					cout << get(1, n, query(1, n, 0, m - 1 - bitl(b) - y)) << endl;
				}
			}
			return 0;
		}
	}
	return 0;
}