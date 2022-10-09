#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <time.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {
	return out << "(" << a.x << ", " << a.y << ")";
}

template <class A> ostream& operator << (ostream& out, const vector<A> &v) {
	out << "[";
	forn(i, sz(v)) {
		if (i) out << ", ";
		out << v[i];
	}
	return out << "]";
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const int MOD = INF + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);

const int N = 142;

int n;
pt a[N];

bool read() {
	if (!(cin >> n))
		return false;
	forn(i, n) {
		cin >> a[i].x;
		a[i].y = i;
	}
	return true;
}

void solve() {

	if (a[0].x == 0) {
		puts("-1");
		return;
	}

	vector<pt> ans;
	int p = 0;

	sort(a + 1, a + n);
	reverse(a + 1, a + n);

	for (int i = 1; i < n; i++) {
		if (a[p].x == 0) {
			p++;
			if (p == n || a[p].x == 0) {
				puts("-1");
				return;
			}
		}
		ans.pb(mp(a[p].y, a[i].y));
		a[p].x--;
	}

	printf("%d\n", sz(ans));
	forn(i, sz(ans))
		printf("%d %d\n", ans[i].x + 1, ans[i].y + 1);
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tt = clock();

#endif

	cerr.precision(15);
	cout.precision(15);
	cerr << fixed;
	cout << fixed;

	while (read()) {
		solve();

#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif

	}
}