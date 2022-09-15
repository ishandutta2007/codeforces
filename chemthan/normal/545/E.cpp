//#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FOR2(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, n) for(int i = n - 1; i >= 0; i--)
#define FORd2(i, a, b) for(int i = a - 1; i >= b; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sz(a) int((a).size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
ll gcd(ll a, ll b){ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#define INF 1000000000000000007
#define UNVISITED 0
#define VISITED 1

int n, m, u;
vector<pair<int, ii>> v[300010];
ll d[300010];
int p[300010];
bool vis[300010];
bool edge[300010];
int pe[300010];
int pw[300010];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(d, INF); ms(p, -1); ms(edge, 0); ms(vis, UNVISITED);
	cin>>n>>m;
	FOR(i, m) {int x, y, z; cin>>x>>y>>z; x--; y--; v[x].push_back(make_pair(y, ii(z, i))); v[y].push_back(make_pair(x, ii(z, i))); edge[i] = true;}
	cin>>u; u--; d[u] = 0;
	priority_queue<ii, vector<ii>, greater<ii>> q; q.push(ii(0, u));
	while (!q.empty()) {int u = q.top().second; q.pop(); FOR(i, sz(v[u])) {pair<int, ii> to = v[u][i]; if (d[to.first] > d[u] + to.second.first || (d[to.first] == d[u] + to.second.first && d[u] > d[p[to.first]])) {d[to.first] = d[u] + to.second.first; p[to.first] = u; pe[to.first] = to.second.second; pw[to.first] = to.second.first; q.push(ii(d[to.first], to.first));}}}
	ll wans = 0; vector<int> eans;
	FOR(i, n) {if (vis[i] == VISITED) continue; int v = i; while (p[v] > -1) {if (vis[v] == VISITED) break; vis[v] = VISITED; if (edge[pe[v]]) {wans += pw[v]; eans.push_back(pe[v]); edge[pe[v]] = false;} v = p[v];}}
	cout<<wans<<"\n"; FOR(i, sz(eans)) cout<<eans[i] + 1<<" ";
}

int main() {
	solve();
	return 0;
}