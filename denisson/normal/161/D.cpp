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

int n, k;
vec<int> g[50007];
int kol[50007][507];
ll ans = 0;

void dfs(int v, int pred) {
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (to != pred) {
			dfs(to, v);
			forn(j, k)
				kol[v][j + 1] += kol[to][j];
		}
	}
	kol[v][0]++;
}

void go(int v, int pred) {
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (to != pred) {
			forn(j, k)
				kol[v][j + 1] -= kol[to][j];
			for (int x = k; x >= 1; x--)
				ans += (ll)kol[to][x - 1] * kol[v][k - x];
			//forn(j, k)
			//	kol[v][j + 1] += kol[to][j];
		}
	}
	//cout << v << ' ' << ans << LN;
	forn(i, g[v].size()) {
		int to = g[v][i];
		if (to != pred) {
			go(to, v);
		}
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	ios_base::sync_with_stdio(0);
	//cin.tie();
	if (is_testing)
	{
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("fisher.in", "r", stdin);
		//freopen("fisher.out", "w", stdout);
	}
	cin >> n >> k;
	forn(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0, -1);
	go(0, -1);
	cout << ans;
	if (is_testing) {
		cout << LN << 1.0 * clock() / CLOCKS_PER_SEC << LN;
	}
}