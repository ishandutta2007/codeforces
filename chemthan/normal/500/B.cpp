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

const int maxn = 310;
int n;
int p[maxn];
char s[maxn];
vi adj[maxn];
bool vis[maxn];
vi list1, list2;

void dfs(int u) {
	vis[u] = 1; {list1.push_back(u); list2.push_back(p[u]);}
	FOR(i, 0, sz(adj[u])) {
		int v = adj[u][i];
		if (!vis[v]) dfs(v);
	}
}

void solve() {
	ms(vis, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", p + i);
	FOR(i, 0, n) {scanf("%s", s); FOR(j, 0, n) if (s[j] == '1') adj[i].push_back(j);}
	FOR(i, 0, n) {
		if (!vis[i]) {
			dfs(i);
			sort(list1.begin(), list1.end());
			sort(list2.begin(), list2.end());
			FOR(i, 0, sz(list1)) p[list1[i]] = list2[i];
			list1.clear(); list2.clear();
		}
	}
	FOR(i, 0, n) printf("%d ", p[i]);
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