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
vector<int> g[10*100007];
int p[10*100007];
bool del[10*100007];
int w[10*100007];
int h[10*100007];
int root;
vector<int> s;
int tin[10*100007];
int sp[25][10*100007];
int lg[10*100007];
int ans[10*100007];

void dfs(int v, int pred, int hh) {
	h[v] = hh;
	bool f = 0;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != pred) {
			if (!f)
				tin[v] = s.size(), f = 1;
			s.pub(v);
			dfs(to, v, hh + 1);
		}
	}
	if (!f)
		tin[v] = s.size(),
	s.pub(v);
}

int dfsw(int v, int pred) {
	w[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != pred && !del[to]) {
			w[v] += dfsw(to, v);
		}
	}
	return w[v];
}

int dfsg(int v, int pred, int ww) {
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (to != pred && !del[to]) {
			if (w[to] > ww / 2)
				return dfsg(to, v, ww);
		}
	}
	return v;
}

int build(int v) {
	dfsw(v, -1);
	v = dfsg(v, -1, w[v]);
	del[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i];
		if (!del[to]) {
			int now = build(to);
			p[now] = v;
		}
	}
	return v;
}

int getlca(int v1, int v2) {
	int l = tin[v1];
	int r = tin[v2];
	if (l > r)
		swap(l, r);
	int lv = lg[r - l + 1];
	v1 = sp[lv][l];
	v2 = sp[lv][r - (1 << (lv)) + 1];
	if (h[v1] < h[v2])
		return v1;
	else
		return v2;
}

int rast(int v1, int v2) {
	int c = getlca(v1, v2);
	return h[v1] + h[v2] - 2 * h[c];
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "w", stdout);
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	//
	dfs(0, -1, 0);

	for (int l = 0; l <= 23; l++) {
		for (int st = 0; ; st++) {
			int r = st + (1 << l) - 1;
			if (r >= s.size())
				break;
			if (l == 0) {
				sp[l][st] = s[st];
			} else {
				int v1 = sp[l - 1][st];
				int v2 = sp[l - 1][r - (1 << (l - 1)) + 1];
				if (h[v1] < h[v2])
					sp[l][st] = v1;
				else
					sp[l][st] = v2;
			}
		}
	}
	lg[1] = 0;
	for (int i = 2; i <= 200005; i++)
		lg[i] = lg[i / 2] + 1;

	//

	root = build(0);
	p[root] = -1;
	
	/*for (int i = 0; i < n; i++) {
		cout << i + 1 << ' ' << p[i] + 1 << endl;
	}*/


	for (int i = 0; i < n; i++)
		ans[i] = INF;

	int t = 0;
	while (t != -1) {
		ans[t] = rast(0, t);
		t = p[t];
	}

	for (int i = 0; i < m; i++) {
		int type, v;
		scanf("%d %d", &type, &v);
		v--;
		if (type == 1) {
			int t = v;
			while (t != -1) {
				ans[t] = min(ans[t], rast(v, t));
				//cout << i << ' ' << t << endl;
				t = p[t];
			}
		} else {
			int now = INF;
			int t = v;
			while (t != -1) {
				now = min(ans[t] + rast(v, t), now);
				//cout << i << ' ' << t << ' ' << ans[t] << endl;
				t = p[t];
			}

			printf("%d\n", now);
		}
	}
}