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
#define db double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;
 
const ll P = 353251;
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 1e4 + 7;
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

ll n, m, k;
pair<ll, ll> a[100007];
ll type = 0;
ll x = 0, y = 0, lx = 0, ly = 0;
ll tt = 0;
pair<ll, ll> d1[200007], d2[200007];
ll s1[200007], s2[200007];

ll getd1(ll x, ll y) {
	return x - y + 100000;
}

ll getd2(ll x, ll y) {
	return x + y;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	cin >> n >> m >> k;
	forn(i, k)
		cin >> a[i].XX >> a[i].YY;
	forn(i, 200007)
		d1[i] = mp(-1, -1), d2[i] = mp(-1, -1), s1[i] = -1, s2[i] = -1;
	bool f = 0;
	while (1) {
		//cout << x << ' ' << y << ' '  << tt << endl;
		if (f) {
			if (x == 0 && y == m ||
				x == 0 && y == 0 ||
				x == n && y == 0 ||
				x == n && y == m)
				break;
		}
		if (type == 0 || type == 2) {
			if (d1[getd1(x, y)] == mp((ll)-1, (ll)-1)) {
				d1[getd1(x, y)] = mp(x, y);
				s1[getd1(x, y)] = tt;
			}
		} else {
			if (d2[getd2(x, y)] == mp((ll)-1, (ll)-1)) {
				d2[getd2(x, y)] = mp(x, y);
				s2[getd2(x, y)] = tt;
			}
		}
		f = 1;
		lx = x;
		ly = y;
		if (type == 0) {
			ll k = min(n - x, m - y);
			x += k;
			y += k;
			tt += k;
			if (x == n)
				type = 3;
			else
				type = 1;
			continue;
		}
		if (type == 1) {
			ll k = min(n - x, y);
			x += k;
			y -= k;
			tt += k;
			if (x == n)
				type = 2;
			else
				type = 0;
			continue;
		}
		if (type == 2) {
			ll k = min(x, y);
			x -= k;
			y -= k;
			tt += k;
			if (x == 0)
				type = 1;
			else
				type = 3;
			continue;
		}
		if (type == 3) {
			ll k = min(x, m - y);
			x -= k;
			y += k;
			tt += k;
			if (x == 0)
				type = 0;
			else
				type = 2;
		}
	}
	forn(i, k) {
		ll q1 = getd1(a[i].XX, a[i].YY);
		ll q2 = getd2(a[i].XX, a[i].YY);
		if (d1[q1] == mp((ll)-1, (ll)-1) && d2[q2] == mp((ll)-1, (ll)-1)) {
			cout << -1 << LN;
			continue;
		}
		if (d1[q1] != mp((ll)-1, (ll)-1) && s1[q1] < s2[q2] || s2[q2] == -1) {
			ll pa = s1[q1];
			pa += min(abs(a[i].XX - d1[q1].XX), abs(a[i].YY - d1[q1].YY));
			cout << pa << LN;
		} else {
			ll pa = s2[q2];
			pa += min(abs(a[i].XX - d2[q2].XX), abs(a[i].YY - d2[q2].YY));
			cout << pa << LN;
		}
	}
}