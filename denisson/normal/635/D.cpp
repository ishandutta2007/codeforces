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
typedef string str;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pb push_back
#define XX first
#define YY second
#define db long double
#define re return
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
#define vec vector
#define all(a) a.begin(), a.end()
const str LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 239017;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
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

ll n, k, a, b, q;
ll was[2 * 100007];
ll t[16 * 2 * 100007];
ll t2[16 * 2 * 100007];

void up(int v, int vl, int vr, int pos, ll add) {
	if (vr < pos || vl > pos)
		re;
	if (vl == vr) {
		if (vl == pos) {
			t[v] += add;
		}
	} else {
		int vm = (vl + vr) / 2;
		up(v * 2 + 1, vl, vm, pos, add);
		up(v * 2 + 2, vm + 1, vr, pos, add);
		t[v] = t[v * 2 + 1] + t[v * 2 + 2];
	}
}

ll get(int v, int vl, int vr, int l, int r) {
	if (l > r)
		re 0;
	if (vr < l || vl > r)
		re 0;
	if (vl >= l && vr <= r) {
		re t[v];
	} else {
		int vm = (vl + vr) / 2;
		re get(v * 2 + 1, vl, vm, l, r) + get(v * 2 + 2, vm + 1, vr, l, r);
	}
}

void up2(int v, int vl, int vr, int pos, ll add) {
	if (vr < pos || vl > pos)
		re;
	if (vl == vr) {
		if (vl == pos) {
			t2[v] += add;
		}
	} else {
		int vm = (vl + vr) / 2;
		up2(v * 2 + 1, vl, vm, pos, add);
		up2(v * 2 + 2, vm + 1, vr, pos, add);
		t2[v] = t2[v * 2 + 1] + t2[v * 2 + 2];
	}
}

ll get2(int v, int vl, int vr, int l, int r) {
	if (l > r)
		re 0;
	if (vr < l || vl > r)
		re 0;
	if (vl >= l && vr <= r) {
		re t2[v];
	} else {
		int vm = (vl + vr) / 2;
		re get2(v * 2 + 1, vl, vm, l, r) + get2(v * 2 + 2, vm + 1, vr, l, r);
	}
}

const bool is_testing = 0;
int main() {
    ios_base::sync_with_stdio(0);
	srand(423);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	cin >> n >> k >> a >> b >> q;
	forn(sf, q) {
		int type;
		cin >> type;
		if (type == 1) {
			ll kol, day;
			cin >> day >> kol;
			day--;
			int add1 = min(was[day] + kol, b) - min(was[day], b);
			int add2 = min(was[day] + kol, a) - min(was[day], a);
			up(0, 0, n - 1, day, add1);
			up2(0, 0, n - 1, day, add2);
			was[day] += kol;
		} else {
			ll l, r;
			cin >> l;
			r = l + k - 1;
			l--; r--;
			cout << get(0, 0, n - 1, 0, l - 1) + get2(0, 0, n - 1, r + 1, n - 1) << LN;
		}
	}
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}