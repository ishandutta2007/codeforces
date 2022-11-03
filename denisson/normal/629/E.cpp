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

ll n, m, tt = 0;
vector<ll> g[100007];
ll sz[100007];
ll up[24][100007];
ll h[100007];
ll kek[100007];
ll lel[100007];
ll tin[100007], tout[100007];

void dfs(ll v, ll pred, ll hh) {
	tin[v] = tt++;
	h[v] = hh;
	sz[v] = 1;
	up[0][v] = pred;
	for (int i = 1; i <= 22; i++)
		up[i][v] = up[i - 1][up[i - 1][v]];

	for (int to : g[v]) {
		if (to != pred) {
			dfs(to, v, hh + 1);
			sz[v] += sz[to];
			kek[v] += kek[to] + sz[to];
		}
	}

	tout[v] = tt++;
}

bool isPred(ll a, ll b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

ll get(ll v, ll k) {
	for (int i = 21; i >= 0; i--)
		if ((k >> i) & 1)
			v = up[i][v];
	return v;
}

void dfs2(ll v, ll pred) {
	if (v != 0) {
		lel[v] = lel[pred] - sz[v] + (n - sz[v]);
	 }
	for (int to : g[v])
		if (to != pred) 
			dfs2(to, v);
}

int getlca(int a, int b) {

	for (int i = 20; i >= 0; i--)
		if (!isPred(up[i][a], b))
			a = up[i][a];

	return up[0][a];
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
	for (int i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	dfs(0, 0, 0);
	lel[0] = kek[0];
	dfs2(0, 0);
	cout.precision(7);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a--; b--;

		if (isPred(b, a))
			swap(a, b);

		if (isPred(a, b)) {
			ll l = h[b] - h[a] + 1;
			ll sz1 = n - sz[get(b, h[b] - h[a] - 1)], sz2 = sz[b];
			ll k = sz1 * sz2;
			ll now = k * l + (lel[a] - kek[get(b, h[b] - h[a] - 1)] - sz[get(b, h[b] - h[a] - 1)]) * sz2 + kek[b] * sz1;
			cout << fixed << (db)now / k << "\n";
		} else {
			ll l = h[a] + h[b] + 1 - 2 * h[getlca(a, b)];
			ll sz1 = sz[a], sz2 = sz[b];
			ll k = sz1 * sz2;
			ll now = k * l + kek[a] * sz2 + kek[b] * sz1;
			cout << fixed << (db)now / k << "\n";
		}
	}
}