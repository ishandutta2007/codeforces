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

int n, m, q, t;
int h[100007];
vector<int> color[100007];
vector<int> g[100007];
int up[10][21][100007];
int kek[21][100007];
int kek2[21][100007];
int tin[100007], tout[100007];
int ss[21];

void merge1(int d1, int a, int d2, int b, int d3, int c) {
	forn(i, 10)
		ss[i] = up[i][d2][b];
	forn(i, 10)
		ss[i + 10] = up[i][d3][c];
	sort(ss, ss + 20);
	int kk = 0;
	forn(i, 20)
		if (i == 0 || ss[i] != ss[i - 1] && kk < 10)
			up[kk++][d1][a] = ss[i];
}	

void dfs(int v, int pred = 0, int hh = 0) {
	tin[v] = t++;
	h[v] = hh;
	//
	kek[0][v] = pred;
	for (int i = 1; i <= 20; i++)
		kek[i][v] = kek[i - 1][kek[i - 1][v]];
	kek2[0][v] = v;
	for (int i = 1; i <= 20; i++)
		kek2[i][v] = kek2[i - 1][kek2[i - 1][v]];
	//
	for (int i = 0; i < min((int)color[v].size(), 10); i++)
		up[i][0][v] = color[v][i];
	for (int i = 1; i <= 20; i++)
		merge1(i, v, i - 1, v, i - 1, kek2[i - 1][kek[i - 1][v]]);
	//
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (to != pred)
			dfs(to, v, hh + 1);
	}
	tout[v] = t++;
}

bool ispred(int v, int u) {
	return (tin[v] <= tin[u] && tout[u] <= tout[v]);
}

int getlca(int a, int b) {
	if (ispred(a, b))
		return a;
	if (ispred(b, a))
		return b;
	for (int i = 20; i >= 0; i--)
		if (!ispred(kek[i][a], b))
			a = kek[i][a];
	return kek[0][a];
}

void go(int v, int d, int now) {
	for (int i = 20; i >= 0; i--)
		if ((d >> i) & 1) {
			merge1(0, now, i, v, 0, now);
			v = kek[i][v];
		}
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0); cin.tie(0);  
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("input.txt", "w", stdout);
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }
	scanf("%d%d%d", &n, &m, &q);
	forn(i, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	forn(i, m) {
		int c;
		scanf("%d", &c);
		c--;
		color[c].pub(i + 1);
	}
	forn(i, n)
		sort(all(color[i]));
	forn(i, 10) {
		forn(j, 21) {
			forn(kk, n)
				up[i][j][kk] = INF;
		}
	}
	dfs(0);
	forn(sdfsdf, q) {
		int a, b, k;
		scanf("%d%d%d", &a, &b, &k);
		a--; b--;
		int c = getlca(a, b);
		for (int i = 0; i < 10; i++)
			up[i][0][n] = INF, up[i][0][n + 1] = INF;
		go(a, h[a] - h[c] + 1, n);
		go(b, h[b] - h[c] + 1, n +  1);
		merge1(0, n, 0, n, 0, n + 1);
		int sz = 0;
		forn(i, 10)
			if (up[i][0][n] != INF)
				sz++;
		printf("%d", min(sz, k));
		forn(i, min(sz, k))
			printf(" %d", up[i][0][n]);
		printf("\n");
	}
}