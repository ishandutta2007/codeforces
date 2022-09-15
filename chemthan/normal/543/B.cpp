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

#define UNVISITED 0
#define VISITED 1

int n, m;
int s1, t1, l1, s2, t2, l2;
vi v[3000];
bool vis[3000];
int d[3001][3001];

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	cin>>n>>m;
	FOR(i, n) FOR(j, n) d[i][j] = INT_MAX;
	FOR(i, m) {int a, b; cin>>a>>b; a--; b--; v[a].push_back(b); v[b].push_back(a);}
	cin>>s1>>t1>>l1>>s2>>t2>>l2; s1--; t1--; s2--; t2--;
	FOR(i, n) {
		ms(vis, UNVISITED); d[i][i] = 0;
		priority_queue<ii, vector<ii>, greater<ii>> pq; 
		pq.push(ii(d[i][i], i));
		while (!pq.empty()) {
			int u = pq.top().second; pq.pop();
			vis[u] = VISITED;
			FOR(j, sz(v[u])) {
				int to = v[u][j];
				if (vis[to] == UNVISITED && d[i][to] > d[i][u] + 1) {d[i][to] = d[i][u] + 1; pq.push(ii(d[i][to], to));}
			}
		}
	}
	if (d[s1][t1] > l1 || d[s2][t2] > l2) {cout<<-1; return;}
	int ans = m - d[s1][t1] - d[s2][t2];
	FOR(i, n) FOR(j, n) {if (d[s1][i] + d[j][t1] + d[i][j] <= l1 && d[s2][i] + d[j][t2] + d[i][j] <= l2) ans = MAX(ans, m - d[s1][i] - d[j][t1] - d[s2][i] - d[j][t2] - d[i][j]); if (d[s1][j] + d[i][t1] + d[i][j] <= l1 && d[s2][i] + d[j][t2] + d[i][j] <= l2) ans = MAX(ans, m - d[s1][j] - d[i][t1] - d[s2][i] - d[j][t2] - d[i][j]);}
	cout<<ans;
}

int main() {
	solve();
	return 0;
}