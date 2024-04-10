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

const int N = 1e5 + 10;

int s[N], t[N];
char buf[N];
int prefs[N];
int preft[N];
int idxs[N];
int idxt[N];

int n, m;

bool read() {
	gets(buf);
	n = strlen(buf);

	forn(i, n) {
		s[i] = (buf[i] != 'A');
	}

	gets(buf);
	m = strlen(buf);

	forn(i, m) {
		t[i] = (buf[i] != 'A');
	}

	return true;
}

int getz(int pref[N], int l, int r) {
	return pref[r + 1] - pref[l];
}

void calcz(int s[N], int prefs[N], int n) {
	forn(i, n) {
		prefs[i + 1] = prefs[i] + s[i];
	}
}

void calcidx(int s[N], int idxs[N], int n) {
	int last = -1;

	forn(i, n) {
		if (s[i]) {
			last = i;
		}

		idxs[i] = last;
	}
}

void precalc() {
	calcz(s, prefs, n);
	calcz(t, preft, m);
	calcidx(s, idxs, n);
	calcidx(t, idxt, m);
}

void solve() {
	precalc();

	int nq;
	scanf("%d", &nq);
	string ans = "";

	forn(i, nq) {
		int ls, rs, lt, rt;
		scanf("%d%d%d%d", &ls, &rs, &lt, &rt);
		--ls, --rs, --lt, --rt;

		int nums = getz(prefs, ls, rs);
		int numt = getz(preft, lt, rt);

		if (nums > numt || (nums % 2) != (numt % 2)) {
			ans.pb('0');
			continue;
		}

		int cs = idxs[rs];
		int ct = idxt[rt];

		int cnts = rs - max(cs, ls - 1);
		int cntt = rt - max(ct, lt - 1);

		if (cnts < cntt) {
			ans.pb('0');
			continue;
		}

		if (nums == 0 && numt > 0 && cnts == cntt) {
			ans.pb('0');
			continue;
		}

		if (nums < numt) {
			ans.pb('1');
		} else {
			if (cnts % 3 == cntt % 3) {
				ans.pb('1');
			} else {
				ans.pb('0');
			}
		}
	}

	puts(ans.c_str());
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