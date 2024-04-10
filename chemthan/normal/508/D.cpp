#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 200010;
const int maxv = 100000;
int n;
vi adj[maxv];
int din[maxv];
int dou[maxv];
char ans[maxn];
int nlen;

int make(int a, int b) {
	return (a << 8) + b;
}

void dfs(int u) {
	while (sz(adj[u])) {
		int v = adj[u].back(); adj[u].pop_back();
		dfs(v);
	}
	ans[nlen++] = u % 256;
}

void solve() {
	ms(din, 0); ms(dou, 0);
	scanf("%d", &n);
	FOR(i, 0, n) {
		char s[10]; scanf("%s", s);
		int u = make(s[0], s[1]), v = make(s[1], s[2]);
		adj[u].push_back(v); dou[u]++; din[v]++;
	}
	ms(ans, 0); nlen = 0;
	int cnt =0, idx, idx1, idx2;
	FOR(i, 0, maxv) {
		if (dou[i] == din[i]) {if (dou[i]) idx1 = i;}
		else if (abs(dou[i] - din[i]) == 1) {cnt++; if (dou[i] > din[i]) idx2 = i;}
		else {printf("NO"); return;}
	}
	if (cnt == 0) idx = idx1;
	else if (cnt == 2) idx = idx2;
	else {printf("NO"); return;}
	dfs(idx);
	ans[nlen++] = idx >> 8;
	reverse(ans, ans + nlen);
	if (nlen == n + 2) printf("YES\n%s", ans); else printf("NO"); return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}