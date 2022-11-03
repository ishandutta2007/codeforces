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
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 2e8;
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
int root;
int p[100007];
int w[100007];
bool del[100007];

ll st1[100007];
ll st2[100007];

map<int, int> ma, ma2;
ll ans[100007];
vector<pair<int, int> > g[100007];

int dfsw(int v, int pred) {
	w[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		if (to != pred && !del[to])
			w[v] += dfsw(to, v);
	}

	return w[v];
}

int dfsg(int v, int pred, int ww) {
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		if (to != pred && !del[to]) {
			if (w[to] > ww / 2)
				return dfsg(to, v, ww);
		}
	}
	return v;
}

void dfsans(int v, int pred, ll now, bool f, int hh) {
	if (f)
		ma[now]++;
	else
		ma2[now]++;

	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		int c = g[v][i].YY;
		ll d = (now + (ll)c * st1[hh]) % m;
		if (to != pred && !del[to]) {
			dfsans(to, v, d, f, hh + 1);
		}
	}
}

int rt;

void go(int v, int pred, ll now, int hh) {
	if (now == 0)
		ans[rt]++;
	ans[rt] += (ma[(m - now) * st2[hh] % m] - ma2[(m - now) * st2[hh] % m]);
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		int c = g[v][i].YY;
		ll d = (now * (ll)10 + c) % m;
		if (to != pred && !del[to]) {
			go(to, v, d, hh + 1);
		}
	}
}

int build(int v) {
	dfsw(v, -1);
	v = dfsg(v, -1, w[v]);
	del[v] = 1;

	ma.clear();

	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		if (!del[to]) {
			dfsans(to, -1, g[v][i].YY % m, 1, 1);
		}
	}

	ans[v] += ma[0];
	rt = v;
	//for (pair<int, int> x : ma)
	//	cout << x.XX << ' ' << x.YY << endl;

	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		if (!del[to]) {
			ma2.clear();
			dfsans(to, -1, g[v][i].YY % m, 0, 1);
			go(to, -1, g[v][i].YY % m, 1);
		}
	}

	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].XX;
		if (!del[to]) {
			p[build(to)] = v;
		}
	}
	return v;
}

ll bp(ll a, int k) {
	if (k == 1)
		return a;
	if (k & 1) {
		return bp(a, k - 1) * a % m;
	} else {
		ll q = bp(a, k / 2);
		return q * q % m;
	}
}

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	scanf("%d %d", &n, &m);
	if (m == 1) {
		cout << (ll)(n - 1) * (ll)n;
		exit(0);
	}
	st1[1] = 10 % m;
	int ss = phi(m);
	for (int i = 2; i <= 100005; i++)
		st1[i] = (st1[i - 1] * (ll)10) % m;
	for (int i = 1; i <= 100005; i++)
		st2[i] = bp(st1[i], ss - 1);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].pub(mp(b, c));
		g[b].pub(mp(a, c));
	}
	root = build(0);
	p[root] = -1;

	ll ha = 0;
	for (int i = 0; i < n; i++)
		ha += ans[i];
	cout << ha;
}