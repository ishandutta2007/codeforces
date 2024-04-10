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

const int maxn = 100010;
const int mod  = 1000000007;
int n, m;
vii edgeone;
vii edgezero;
vi adj[maxn];
int p[maxn];
int size[maxn];
int color[maxn];

int find(int a) {
    return p[a] == a ? a : (p[a] = find(p[a]));
}

void join(int a, int b) {
     int x = find(a);
     int y = find(b);
     if (x < y) swap(x, y);
     p[y] = x;
     size[x] += size[y];
}

void dfs(int u) {
     while (!adj[u].empty()) {
           int v = adj[u].back(); adj[u].pop_back();
           if (color[v] == color[u]) {printf("0"); exit(0);}
           else {color[v] = 3 - color[u]; dfs(v);}
     }
}

void solve() {
     ms(color, 0);
     scanf("%d%d", &n, &m);
     int a, b, c;
     FOR(i, 0, m) {
            scanf("%d%d%d", &a, &b, &c); a--; b--;
            if (c) edgeone.push_back(pi(a, b));
            else edgezero.push_back(pi(a, b));
     }
     FOR(i, 0, n) {p[i] = i; size[i] = 1;}
     FOR(i, 0, sz(edgeone)) join(edgeone[i].first, edgeone[i].second);
     FOR(i, 0, sz(edgezero)) {
            int x = find(edgezero[i].first);
            int y = find(edgezero[i].second);
            adj[x].push_back(y);
            adj[y].push_back(x);
     }
     int cnt = 0;
     FOR(i, 0, n) if (find(i) == i && !color[i]) {cnt++; color[i] = 1; dfs(i);}
     ll ans = 1;
     FOR(i, 0, cnt - 1) ans = ans * 2 % mod;
     printf("%d", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}