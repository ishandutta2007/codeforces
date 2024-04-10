//#include <bits/stdc++.h>
#include <iostream>
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

int const nmax = 400010;
int n;
vi adj[nmax];
bool deg[nmax];
int s[nmax];
map<ii, bool> del, mp;
set<int> d[2];
vector<int> edge;
vector<ii> eans;

void euler(int u) {
	while (!adj[u].empty()) {
		int v = adj[u].back(); adj[u].pop_back();
		if (!del[ii(u, v)]) {del[ii(u, v)] = del[ii(v, u)] = 1; euler(v);}
	}
	edge.push_back(u);
}

void deledge(int u, int v) {
	del[ii(u, v)] = del[ii(v, u)] = 1;
	d[deg[u]].erase(u);
	deg[u] = !deg[u];
	d[deg[u]].insert(u);
	d[deg[v]].erase(v);
	deg[v] = !deg[v];
	d[deg[v]].insert(v);
}

void solve() {
	if (d[1].empty()) {
		FOR(i, 0 , nmax) {
			edge.clear();
			euler(i);
			FOR(j, 1, sz(edge)) mp[ii(edge[j - 1], edge[j])] = mp[ii(edge[j], edge[j - 1])] = j % 2;
		}
	} else {
		int u = *d[1].begin();
		while (!adj[u].empty() && del[ii(u, adj[u].back())]) adj[u].pop_back();
		int v = adj[u].back();
		deledge(u, v);
		solve();
		int c = 0;
		if (s[v] > 0) c = 1;
		if (c == 1) {s[u]--; s[v]--;}
		else {s[u]++; s[v]++;}
		mp[ii(u, v)] = mp[ii(v, u)] = c;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	ms(s, 0);
	cin>>n;
	FOR(i, 0, n) {int x, y; cin>>x>>y; adj[x].push_back(y + n); adj[y + n].push_back(x); eans.push_back(ii(x, y + n));}
	FOR(i, 0, nmax) {deg[i] = sz(adj[i]) % 2; d[deg[i]].insert(i);}
	solve();
	FOR(i, 0, sz(eans)) cout<<(mp[eans[i]] ? "b" : "r");
	return 0;
}