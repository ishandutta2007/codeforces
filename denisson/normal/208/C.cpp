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
vector<int> g[107];
int r1[107], r2[107];
vector<int> g2[107];
vector<pair<int, int> > reb;

ll ma = 0;
ll dp[107];
ll dp2[107];

ll go(int v) {
	if (dp[v] != -1)
		return dp[v];
	ll ans = 0;
	for (int to : g2[v]) {
		if (r1[to] > r1[v])
			ans += go(to);
	}
	dp[v] = ans;
	return ans;
}

ll go2(int v) {
	if (dp2[v] != -1)
		return dp2[v];
	ll ans = 0;
	for (int to : g2[v]) {
		if (r2[to] > r2[v])
			ans += go2(to);
	}
	dp2[v] = ans;
	return ans;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	for (int i = 0; i < 107; i++)
		r1[i] = -1, r2[i] = -1, dp[i] = -1, dp2[i] = -1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		reb.pub(mp(a, b));
		g[a].pub(b);
		g[b].pub(a);
	}
	vector<int> t;
	int uk = 0;
	t.pub(0);
	r1[0] = 0;
	while (uk < t.size()) {
		int v = t[uk++];
		for (int to : g[v]) {
			if (r1[to] == -1) {
				r1[to] = r1[v] + 1;
				t.pub(to);
			}
		}
	}
	t.clear(), uk = 0;
	r2[n - 1] = 0;
	t.pub(n - 1);
	while (uk < t.size()) {
		int v = t[uk++];
		for (int to : g[v]) {
			if (r2[to] == -1) {
				r2[to] = r2[v] + 1;
				t.pub(to);
			}
		}
	}
	for (auto c : reb) {
		int a = c.XX, b = c.YY;
		if (r1[a] + r2[b] + 1 == r1[n - 1] || r1[b] + r2[a] + 1 == r1[n - 1])
			g2[a].pub(b), g2[b].pub(a);
	}
	dp[n - 1] = 1;
	dp2[0] = 1;
	go(0);
	go2(n - 1);
	for (int i = 0; i < n; i++) {
		ll now = 0;
		for (int to : g2[i]) {
			if (r1[to] > r1[i]) {
				now += dp[to] * dp2[i];
			} else {
				now += dp2[to] * dp[i];
			}
		}
		//cout << i << ' ' << now << endl;
		ma = max(ma, now);
	}
	cout.precision(8);
	cout << fixed << (db)ma / go(0);
}