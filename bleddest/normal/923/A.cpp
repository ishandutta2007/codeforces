#pragma comment(linker, "/STACK:250000000")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <fstream>
#include <bitset>
#include <algorithm>
#include <cmath>
        
//#include <unordered_map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define forft(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ms(a, v) memset(a, v, sizeof(a))
#define x first
#define y second
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(4e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;     

const int N = 1e6 + 10;

bool used[N];
int p[N];
int n;

void precalc() {
	for (int i = 2; i < N; ++i) {
		if (used[i]) {
			continue;
		}
		
		p[i] = i;
		li j = i + i;

		while (j < N) {
			used[j] = true;
			p[j] = max(p[j], i);
			j += i;
		}
	}
}

bool read() {
	cin >> n;
	return true;
}

void solve() {
	precalc();
	int ans = INF;

	for (int i = n - p[n] + 1; i <= n; ++i) {
		if (p[i] == i) {
			continue;
		}

		ans = min(ans, i - p[i] + 1);
	}

	cout << ans << endl;
}

//#define FILES

int main() {
#ifdef AR
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#else
#ifdef FILES
	assert(freopen(".in", "rt", stdin));
	assert(freopen(".out", "wt", stdout));
#endif
#endif

	srand(time(NULL));

	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;

	read();
	solve();

#ifdef AR
	cerr << "Time: " << clock() << endl;
#endif
	return 0;
}