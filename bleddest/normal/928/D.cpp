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

const int N = 3e5 + 50;

struct node {
	map<char, int> nxt;
	int d;
};

node t[N];
int tsz = 1;

void add(int id, int pos, string &s) {
	++t[id].d;

	if (pos == sz(s)) {
		return;
	}

	if (!t[id].nxt.count(s[pos])) {
		t[id].nxt[s[pos]] = tsz++;
	}

	add(t[id].nxt[s[pos]], pos + 1, s);
}

bool check(int id, int pos, string &s) {
	if (pos == sz(s)) {
		if (sz(t[id].nxt) > 0) {
			return false;
		} else {
			return true;
		}
	}

	if (!t[id].nxt.count(s[pos])) {
		if (sz(t[id].nxt) > 0) {
			return false;
		} else {
			return true;
		}
	}

	return check(t[id].nxt[s[pos]], pos + 1, s);
}

int getcnt(int id, int pos, string &s) {
	int ans = 1;
	bool pref = false;

	while (true) {
		if (pos == sz(s)) {
			break;
		}

		if (!t[id].nxt.count(s[pos])) {
			ans += sz(s) - pos;
			break;
		}

		if (id != 0 && t[id].d == 1) {
			pref = true;
		}

		if (!pref) {
			++ans;
		}

		id = t[id].nxt[s[pos]];
		++pos;
	}

	return ans;
}

string s;
int ans = 0;

bool read() {
	return true;
}

string get_word(int &pos, string &s) {
	string h = "";

	while (pos < sz(s)) {
		if (s[pos] == '.' || s[pos] == ',' || s[pos] == '?' || s[pos] == '!' || s[pos] == '\'' || s[pos] == '-' || s[pos] == ' ') {
			if (sz(h) > 0) {
				return h;
			}

			++ans;
		} else {
			h.pb(s[pos]);
		}

		++pos;
	}

	return h;
}

void solve() {
	set<string> nums;

	while (getline(cin, s)) {
		s.pb('.');
		string h;
		int pos = 0;

		while (true) {
			h = get_word(pos, s);

			if (sz(h) == 0) {
				break;
			}

			if (check(0, 0, h)) {
				ans += min(sz(h), getcnt(0, 0, h));
			} else {
				ans += sz(h);
			}

			if (!nums.count(h)) {
				nums.insert(h);
				add(0, 0, h);
			}
		}

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