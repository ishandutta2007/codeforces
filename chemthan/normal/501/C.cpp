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

const int maxn = 100000;
int n;
int deg[maxn];
int s[maxn];
queue<int> q;
queue<pi> ans;

void solve() {
	scanf("%d", &n);
	FOR(i, 0, n) {scanf("%d%d", deg + i, s + i); if (deg[i] == 1) q.push(i);}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (deg[u] == 1) {
			int v = s[u];
			s[v] ^= u; deg[u]--; deg[v]--;
			if (deg[v] == 1) q.push(v);
			ans.push(make_pair(u, v));
		}
	}
	printf("%d\n", sz(ans));
	while (sz(ans)) {printf("%d %d\n", ans.front().first, ans.front().second); ans.pop();}
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