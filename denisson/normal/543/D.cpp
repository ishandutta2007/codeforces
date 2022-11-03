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

int n;
vector<int> g[2 * 100007];
vector<ll> pref[2 * 100007];
vector<ll> suf[2 * 100007];
ll dp[2 * 100007];
ll ans[2 * 100007];

void dfs(int v, int pred = -1) {
	dp[v] = 1;
	vector<ll> now;
	for (int to : g[v])
		if (pred != to) {
			dfs(to, v);
			now.pub(dp[to] + 1);
			dp[v] = dp[v] * (dp[to] + 1) % MOD;
		} else now.pub(1);
	ll last = 1;
	for (ll x : now)
		pref[v].pub(last * x % MOD), last = last * x % MOD;
	last = 1;
	reverse(all(now));
	for (ll x : now)
		suf[v].pub(last * x % MOD), last = last * x % MOD;
	reverse(all(suf[v]));
}

ll bp(ll a, ll k) {
	if (k == 1)
		return a;
	if (k & 1) {
		return bp(a, k - 1) * a % MOD;
	} else {
		ll q = bp(a, k / 2);
		return q * q % MOD;
	}
}

ll getobr(ll q) {
	return bp(q, MOD - 2);
}

void dfs2(int v, int pred, ll was) {
	ans[v] = dp[v] * (was + 1) % MOD;
	int f = 0;
	for (int to : g[v]) {
		if (pred != to) {
			ll fd = (f - 1 < 0 ? 1 : pref[v][f - 1]) * (f + 1 > (int)suf[v].size() - 1 ? 1 : suf[v][f + 1]) % MOD;
			fd = fd * (was + 1) % MOD;
			dfs2(to, v, fd);
		}
		f++;
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
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int q;
		cin >> q;
		q--;
		g[q].pub(i + 1);
		g[i + 1].pub(q);
	}
	dfs(0);
	ans[0] = dp[0];
	int f = 0;
	for (int to : g[0]) {
		ll fd = (f - 1 < 0 ? 1 : pref[0][f - 1]) * (f + 1 > (int)suf[0].size() - 1 ? 1 : suf[0][f + 1]) % MOD;
		dfs2(to, 0, fd);
		f++;
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
}