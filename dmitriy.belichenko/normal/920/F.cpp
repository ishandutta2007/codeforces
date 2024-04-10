#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

template<typename T = int>
inline T read()
{
	T val = 0, sign = 1;
	char ch;

	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar()) {
		if (ch == '-') {
			sign = -1;
		}
	}
	for (; ch >= '0' && ch <= '9'; ch = getchar()) {
		val = val * 10 + ch - '0';
	}
	return sign * val;
}

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define eputs(s) eprintf("%s\n", (s))
#else
#define eprintf(...) ((void)0)
#define eputs(s) ((void)0)
#endif

#define forn(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using ll = long long;
using pii = pair<int, int>;

const int N = 1e6 + 5;

int d[N];
int a[N];

ll fw[N];

int n;

void upd(int u, ll x = 1) {
	for (; u < n; u |= (u + 1))
		fw[u] += x;
}

ll get(int l, int r) {
	ll ans = 0;
	l--;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ans += fw[r];
	for (; l >= 0; l = (l & (l + 1)) - 1)
		ans -= fw[l];

	return ans;
}

mt19937 gen(time(NULL));

void test() {
	n = read();
	int q = read();

	forn(i, n) a[i] = 1 + gen() % 1000000;

	set<int> arr;
	forn(i, n) arr.insert(i);


	forn(i, q) {
		int t = gen() % 2, l = gen() % n, r = gen() % n;
		if (l > r) swap(l, r);
		if (t == 1) {
			auto it = arr.lower_bound(l);
			if (it == arr.end()) continue;

			vector<int> ers;
			while (it != arr.end() && *it <= r) {
				int v = *it;
				a[v] = d[a[v]];

				if (a[v] == 1) ers.push_back(v);

				it++;
			}

			for (auto v : ers) {
				upd(v);
				arr.erase(v);
			}
		}
		else {
			ll ans = 0;
			auto it = arr.lower_bound(l);
			while (it != arr.end() && *it <= r) {
				ans += a[*it];
				it++;
			}

			ans += get(l, r);

			//printf("%lld\n", ans);
		}
	}
}

void solve() {
	n = read();
	int q = read();
	forn(i, n) a[i] = read();

	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			d[j]++;

	set<int> arr;
	forn(i, n) arr.insert(i);

	forn(i, n) upd(i, a[i]);

	forn(i, q) {
		int t = read(), l = read(), r = read();
		l--, r--;

		if (t == 1) {
			auto it = arr.lower_bound(l);
			if (it == arr.end()) continue;

			vector<int> ers;
			while (it != arr.end() && *it <= r) {
				int v = *it;
				upd(v, -a[v]);
				a[v] = d[a[v]];
				upd(v, a[v]);

				if (a[v] <= 2) ers.push_back(v);
				
				it++;
			}

			for (auto v : ers) {
				arr.erase(v);
			}
		}
		else {
			printf("%lld\n", get(l, r));
		}
	}
}

int main() {
	int t = 1;
	//test();
	while (t--) solve();
}