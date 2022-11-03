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
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

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

struct st {
	ll ma, mi;
	pair<ll, ll> p;
	bool f;
	st() {}
	st(ll mi1, ll ma1, pair<ll, ll> p1, bool f1) { ma = ma1, mi = mi1, p = p1, f = f1; }
};

int n, m;
int d[200007];
int h[200007];
ll sum[200007];
st t[4 * 200007];

pair<ll, ll> ge(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.YY - a.XX > b.YY - b.XX)
		return a;
	return b;
}

void build(int v, int vl, int vr) {
	if (vl == vr) {
		t[v] = st(sum[vl - 1] - (ll)2 * h[vl], sum[vl - 1] + (ll)2 * h[vl], mp(sum[vl - 1] - (ll)2 * h[vl], sum[vl - 1] + (ll)2 * h[vl]), 1);
	} else {
		int vm = (vl + vr) >> 1;
		build(v * 2 + 1, vl, vm);
		build(v * 2 + 2, vm + 1, vr);
		t[v].mi = min(t[v * 2 + 1].mi, t[v * 2 + 2].mi);
		t[v].ma = max(t[v * 2 + 1].ma, t[v * 2 + 2].ma);
		pair<ll, ll> now = mp(t[v * 2 + 1].mi, t[v * 2 + 2].ma);
		if (!t[v * 2 + 1].f)
			now = ge(now, t[v * 2 + 1].p);
		if (!t[v * 2 + 2].f)
			now = ge(now, t[v * 2 + 2].p);
		t[v].p = now;
		t[v].f = 0;
	}
}

st get(int v, int vl, int vr, int l, int r) {
	if (vl >= l && vr <= r) {
		return t[v];
	} else {
		int vm = (vl + vr) >> 1;
		if (l > vm)
			return get(v * 2 + 2, vm + 1, vr, l, r);
		if (r <= vm)
			return get(v * 2 + 1, vl, vm, l, r);
		st s1 = get(v * 2 + 1, vl, vm, l, r);
		st s2 = get(v * 2 + 2, vm + 1, vr, l, r);
		pair<ll, ll> now = mp(s1.mi, s2.ma);
		if (!s1.f)
			now = ge(now, s1.p);
		if (!s2.f)
			now = ge(now, s2.p);
		return st(min(s1.mi, s2.mi), max(s1.ma, s2.ma), now, 0);
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> h[i]; 

	for (int i = n + 1; i <= 2 * n; i++)
		h[i] = h[i - n], d[i] = d[i - n];
	for (int i = 1; i <= 2 * n; i++)
		sum[i] = sum[i - 1] + d[i];

	build(0, 1, 2 * n);

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		if (l <= r) {
			st kek = get(0, 1, 2 * n, r + 1, n + l - 1);
			cout << kek.p.YY - kek.p.XX << "\n";
		} else {
			st kek = get(0, 1, 2 * n, r + 1, l - 1);
			cout << kek.p.YY - kek.p.XX << "\n";
		}
	}
}