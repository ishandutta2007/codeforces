#ifndef ONLINE_JUDGE
	#include <iostream>
#else
	#include <bits/stdc++.h>
#endif
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

int const nmax = 5010;
int n;
vi adj[nmax];
int size[nmax];
bool vis[nmax];

void dfs(int u) {
	vis[u] = 1;
	size[u] = 1;
	FOR(j, 0, sz(adj[u])) {
		int v = adj[u][j];
		if (!vis[v]) {dfs(v); size[u] += size[v];}
	}
}

void solve() {
	ms(size, 0); ms(vis, 0);
	cin>>n;
	FOR(i, 0, n - 1) {int x, y; cin>>x>>y; x--; y--; adj[x].push_back(y); adj[y].push_back(x);}
	dfs(0);
	set<int> st;
	bool ck[nmax];
	FOR(i, 0, n) {
		ms(ck, 0); ck[0] = 1;
		FOR(j, 0, sz(adj[i])) {
			int u = adj[i][j];
			if (size[u] < size[i]) FORd(k, n, 0) if (ck[k]) ck[k + size[u]] = 1;
		}
		FOR(j, 0, n) if (ck[j] && j > 0 && j < n - 1) {st.insert(j); st.insert(n - j - 1);}
	}
	cout<<sz(st)<<"\n";
	for (set<int>::iterator it = st.begin(); it != st.end(); it++) cout<<(*it)<<" "<<n - 1 - (*it)<<"\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
	return 0;
}