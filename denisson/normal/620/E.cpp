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

int n, m;
vector<int> g[4 * 100007];
int color[4 * 100007];
vector<int> s;
int tin[4 * 100007], tout[4 * 100007];
ll t[2 * 4 * 4 * 100007];
int p[2 * 4 * 4 * 100007];

void dfs(int v, int pred) {
	tin[v] = s.size();
	s.pub(v);
	for (int to : g[v]) {
		if (pred != to)
			dfs(to, v);
	}
	tout[v] = s.size();
	s.pub(v);
}

void build(int v, int vl, int vr) {
	if (vl == vr) {
		t[v] = (ll)1 << color[s[vl]];
	} else {
		int vm = (vl + vr) >> 1;
		build(v * 2 + 1, vl, vm);
		build(v * 2 + 2, vm + 1, vr);
		t[v] = t[v * 2 + 1] | t[v * 2 + 2];
	}
}

void push(int v) {
	if (p[v] != -1) {
		t[v] = (ll)1 << p[v];
		if (v * 2 + 1 < 2 * 4 * 4 * 100007)
			p[v * 2 + 1] = p[v];
		if (v * 2 + 2 < 2 * 4 * 4 * 100007)
			p[v * 2 + 2] = p[v];
		p[v] = -1;
	}
}

ll get(int v, int vl, int vr, int l, int r) {
	push(v);
	if (vr < l || vl > r)
		return 0;
	if (vl >= l && vr <= r)
		return t[v];
	else {
		int vm = (vl + vr) >> 1;
		return get(v * 2 + 1, vl, vm, l, r) | get(v * 2 + 2, vm + 1, vr, l, r);
	}
}

void up(int v, int vl, int vr, int l, int r, int col) {
	push(v);
	if (vr < l || vl > r)
		return;
	if (vl >= l && vr <= r) {
		p[v] = col;
		push(v);
	} else {
		int vm = (vl + vr) >> 1;
		up(v * 2 + 1, vl, vm, l, r, col);
		up(v * 2 + 2, vm + 1, vr, l, r, col);
		t[v] = t[v * 2 + 1] | t[v * 2 + 2];
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	
	for (int i = 0; i < 2 * 4 * 4 * 100007; i++)
		p[i] = -1;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &color[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	dfs(0, -1);
	build(0, 0, (int)s.size() - 1);

	for (int it = 0; it < m; it++) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int v, col;
			scanf("%d %d", &v, &col);
			v--;
			up(0, 0, (int)s.size() - 1, tin[v], tout[v], col);
		} else {
			int v;
			scanf("%d", &v);
			v--; 
			ll now = get(0, 0, (int)s.size() - 1, tin[v], tout[v]);
			int ans = 0;
			for (int i = 61; i >= 0; i--)
				if ((now >> i) & 1)
					ans++;
			printf("%d\n", ans);
		}
	}
}