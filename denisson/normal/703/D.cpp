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
const ll MOD = 2e9 + 7;
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

int n, q;
int a[1000007];
vec<pair<int, int> > zap[1000007];
int ans[1000007];
int s[1000007];
map<int, int> was;
set<int> ga;
int t[16 * 1000007];

int get(int l, int r) {
	if (l == 0)
		re s[r];
	re s[r] ^ s[l - 1];
}

void up(int v, int vl, int vr, int pos, int d) {
	if (vr < pos || vl > pos)
		re;
	t[v] ^= d;
	if (vl == vr)
		re;
	int vm = (vl + vr) / 2;
	up(v * 2 + 1, vl, vm, pos, d);
	up(v * 2 + 2, vm + 1, vr, pos, d);
}

int get2(int v, int vl, int vr, int l, int r) {
	if (vr < l || vl > r)
		re 0;
	if (vl >= l && vr <= r)
		re t[v];
	int vm = (vl + vr) / 2;
	re get2(v * 2 + 1, vl, vm, l, r) ^ get2(v * 2 + 2, vm + 1, vr, l, r);
}

const bool is_testing = 0;
int main() {
	srand(423);
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &a[i]);
	s[0] = a[0];
	form(i, 1, n - 1)
		s[i] = s[i - 1] ^ a[i];
	scanf("%d", &q);
	forn(i, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--; r--;
		zap[r].pb(mp(l, i));
	}
	forn(i, n) {
		if (ga.find(a[i]) != ga.end()) {
			up(0, 0, n - 1, was[a[i]], a[i]);
		} else {
			ga.insert(a[i]);
		}
		was[a[i]] = i;
		up(0, 0, n - 1, i, a[i]);
		forn(j, zap[i].size()) {
			ans[zap[i][j].YY] = get(zap[i][j].XX, i) ^ get2(0, 0, n - 1, zap[i][j].XX, i);
		}
	}
	forn(i, q)
		printf("%d\n", ans[i]);
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}