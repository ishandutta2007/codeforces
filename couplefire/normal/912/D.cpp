#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <string>
#include <map>
#include <unordered_map>
#include <random>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <numeric>
#include <bitset>
 
using namespace std;
 
const int N = 100005, M = 350;
 
mt19937 gen(time(NULL));
#define forn(i, n) for (int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define mp make_pair
#define endl '\n'
 
typedef long long ll;
 
template<typename T = int>
inline T read() {
	T val = 0, sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	return sign * val;
}
 
int n, m, r, k;
 
ll get(int x, int y) {
	return (min(n + 1, x + r) - max(x, r)) * 1LL * (min(m + 1, y + r) - max(y, r));
}
 
bool ok(int x, int y) {
	return min(x, y) > 0 && x <= n && y <= m;
}
 
struct cmp {
	bool operator()(const pii &a, const pii &b) {
		ll f_a = get(a.first, a.second);
		ll f_b = get(b.first, b.second);
		return f_a > f_b || (f_a == f_b && a > b);
	}
};
 
set<pii, cmp> s;
 
set<int> used[N];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
 
double get() {
	s.insert(mp((n + 1) / 2, (m + 1) / 2));
	used[(n + 1) / 2].insert((m + 1) / 2);
 
	ll total = 0;
	forn(i, k) {
		auto e = *s.begin();
		s.erase(s.begin());
 
		int x = e.first, y = e.second;
		total += get(x, y);
 
		forn(j, 4) {
			int _x = x + dx[j], _y = y + dy[j];
			if (!ok(_x, _y) || used[_x].count(_y)) continue;
 
			s.insert(mp(_x, _y));
			used[_x].insert(_y);
		}
	}
 
	return (double)total / ((n - r + 1) * 1LL * (m - r + 1));
}
 
void solve() {
	n = read(), m = read(), r = read(), k = read();
	if (n > m) swap(n, m);
 
	if (n == 1 && m == 1)
		printf("%.10f\n", 1.0);
	else
		printf("%.10f\n", get());
}
 
signed main() {
	int t = 1;
 
	while (t--)
	{
		clock_t z = clock();
		solve();
		debug("Elapsed Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);
	}
}