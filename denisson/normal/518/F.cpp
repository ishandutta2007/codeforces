#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/
//

int n, m;
char a[2007][2007];
ll ans = 0;
int pref[2007][2007];
int pref2[2007][2007];
int rr[2007][2007];
int le[2007][2007];
bool was[2007][2007];

int get(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2)
		return 0;
	return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int get2(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2)
		return 0;
	return pref2[x2][y2] - pref2[x1 - 1][y2] - pref2[x2][y1 - 1] + pref2[x1 - 1][y1 - 1];
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	cin >> n >> m;
	forn(i, n) {
		forn(j, m) {
			cin >> a[i + 1][j + 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = (a[i][j] == '#') + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
		}
	}
	// 0
	for (int i = 2; i < n; i++) {
		if (get(i, 1, i, m) == 0)
			ans++;
	}
	for (int i = 2; i < m; i++) {
		if (get(1, i, n, i) == 0)
			ans++;
	}
	// 1
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			int q1 = get(1, j, i, j);
			int q2 = get(i, j, i, m);
			int q3 = get(i, j, n, j);
			int q4 = get(i, 1, i, j);
			if (!q1 && !q2)
				ans++;
			if (!q2 && !q3)
				ans++;
			if (!q3 && !q4)
				ans++;
			if (!q4 && !q1)
				ans++;
		}
	}
	// 2
	// |_|
	///1
	for (int i = 2; i < n; i++) {
		int last = -1;
		for (int j = m - 1; j >= 2; j--) {
			if (a[i][j] == '.') {
				if (last == -1)
					last = j;
				rr[i][j] = last;
			} else
				last = -1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			was[i][j] = 0;
			if (get(1, j, i, j) == 0)
				was[i][j] = 1;
			pref2[i][j] = was[i][j] + pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (get(1, j, i, j) != 0)
				continue;
			int r = rr[i][j];
			ans += get2(i, j + 2, i, r);
		}
	}
	///2
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			was[i][j] = 0;
			if (get(i, j, n, j) == 0)
				was[i][j] = 1;
			pref2[i][j] = was[i][j] + pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (get(i, j, n, j) != 0)
				continue;
			int r = rr[i][j];
			ans += get2(i, j + 2, i, r);
		}
	}
	///3
	for (int j = 2; j < m; j++) {
		int last = -1;
		for (int i = n - 1; i >= 2; i--) {
			if (a[i][j] != '#') {
				if (last == -1)
					last = i;
				rr[i][j] = last;
			} else {
				last = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			was[i][j] = 0;
			if (get(i, 1, i, j) == 0)
				was[i][j] = 1;
			pref2[i][j] = was[i][j] + pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (get(i, 1, i, j) != 0)
				continue;
			int r = rr[i][j];
			ans += get2(i + 2, j, r, j);
		}
	}
	///4
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			was[i][j] = 0;
			if (get(i, j, i, m) == 0)
				was[i][j] = 1;
			pref2[i][j] = was[i][j] + pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (get(i, j, i, m) != 0)
				continue;
			int r = rr[i][j];
			ans += get2(i + 2, j, r, j);
		}
	}
	// |_
	//   |
	for (int i = 2; i < n; i++) {
		int last = -1;
		for (int j = 2; j < m; j++) {
			if (a[i][j] == '.') {
				if (last == -1)
					last = j;
				le[i][j] = last;
			} else {
				last = -1;
			}
		}
		last = -1;
		for (int j = m - 1; j >= 2; j--) {
			if (a[i][j] == '.') {
				if (last == -1)
					last = j;
				rr[i][j] = last;
			} else {
				last = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			was[i][j] = 0;
			if (get(i, j, n, j) == 0)
				was[i][j] = 1;
			pref2[i][j] = was[i][j] + pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (get(1, j, i, j) != 0)
				continue;
			int l1 = le[i][j];
			int r1 = rr[i][j];
			ans += get2(i, j + 1, i, r1);
			ans += get2(i, l1, i, j - 1);
		}
	}
	// _
	//  |_
	for (int j = 2; j < m; j++) {
		int last = -1;
		for (int i = 2; i < n; i++) {
			if (a[i][j] == '.') {
				if (last == -1)
					last = i;
				le[i][j] = last;
			} else {
				last = -1;
			}
		}
		last = -1;
		for (int i = n - 1; i >= 2; i--) {
			if (a[i][j] == '.') {
				if (last == -1)
					last = i;
				rr[i][j] = last;
			} else {
				last = -1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			was[i][j] = 0;
			if (get(i, j, i, m) == 0)
				was[i][j] = 1;
			pref2[i][j] = was[i][j] + pref2[i - 1][j] + pref2[i][j - 1] - pref2[i - 1][j - 1];
		}
	}
	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			if (get(i, 1, i, j) != 0)
				continue;
			int l1 = le[i][j];
			int r1 = rr[i][j];
			ans += get2(i + 1, j, r1, j);
			ans += get2(l1, j, i - 1, j);
		}
	}
	//
	cout << ans;
}