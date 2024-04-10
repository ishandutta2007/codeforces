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
#define x first
#define y second
#define XX first
#define YY second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
const double pi = acos(-1.0);
 
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
 
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

int n, bit;
vector<int> g[100007];
ll ans, ansnow;
int sz[100007];
int sum[100007];
int ha[100007];
int color[100007];

void dfs(int v, int pred, int ss) {
	sz[v] = 1;
	ha[v] = ss ^ ((color[v] >> bit) & 1);
	sum[v] = ha[v];
	for (int to : g[v])
		if (to != pred) dfs(to, v, ha[v]), sz[v] += sz[to], sum[v] += sum[to];
}

void zfs(int v, int pred) {
	vector<pair<int, int> > t;
	for (int to : g[v]) {
		if (to != pred) zfs(to, v), t.pub(mp(sum[to], sz[to] - sum[to]));
	}
	int sum0 = 0, sum1 = 0;
	for (auto c : t)
		sum0 += c.y, sum1 += c.x;
	ll ansnow1 = 0;
	if ((color[v] >> bit) & 1) {
		for (auto c : t) {
			ansnow1 += (ll)(sum0 - c.y) * c.y;
			ansnow1 += (ll)(sum1 - c.x) * c.x;
		}
	} else {
		for (auto c : t) {
			ansnow1 += (ll)(sum0 - c.y) * c.x;
			ansnow1 += (ll)(sum1 - c.x) * c.y;
		}
	}
	if (((color[v] >> bit) & 1) ^ ha[v]) ansnow1 += (ll)2 * sum0;
	else ansnow1 += (ll)2 * sum1;
	//cout << v << ' ' << ansnow1 << endl;
	ansnow += ansnow1;
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
        //freopen("lamps.in", "r", stdin);
        //freopen("lamps.out", "w", stdout);
    }
	cin >> n;
	for (int i = 0; i < n; i++) cin >> color[i];
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pub(b);
		g[b].pub(a);
	}
	for (bit = 0; bit <= 20; bit++) {
		ansnow = 0;
		memset(sum, 0, sizeof(sum));
		memset(sz, 0, sizeof(sz));
		dfs(0, -1, 0);
		zfs(0, -1);
		ansnow /= 2;
		for (int i = 0; i < n; i++)
			if ((color[i] >> bit) & 1) ansnow++;
		//cout << ansnow << endl;
		ans += ansnow * (ll)(1 << bit);
	}
	cout << ans;
}