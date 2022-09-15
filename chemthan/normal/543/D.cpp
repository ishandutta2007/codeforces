//#include <bits/stdc++.h>
#include <iostream>
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
#define INF 1000000007
#define UNVISITED 0
#define VISITED 1

int n;
bool dfs_num[200001];
vi rev[200001];
vii v[200001];
int ans[200001];

void dfs(int k) {
	dfs_num[k] = VISITED;
	FOR(i, sz(v[k])) {
		int u = v[k][i].first;
		if (dfs_num[u] == VISITED || v[k][i].second > 0) continue;
		if (ans[u] == 0) dfs(u);
		v[k][i].second = 1;
		FOR(j, v[u].size()) if (v[u][j].first != k) v[k][i].second = 1LL * v[k][i].second * ( 1 + v[u][j].second) % INF;
	}
}

void solve() {
	//freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	ms(ans, 0);
	cin>>n;
	FOR2(i, 1, n) {
		int p; cin>>p; p--;
		rev[i].push_back(v[p].size()); rev[p].push_back(v[i].size());
		v[i].push_back(ii(p, 0)); v[p].push_back(ii(i, 0));
	}
	FOR(i, n) {
		if (ans[i] > 0) {cout<<ans[i]<<" "; continue;}
		else {
			ms(dfs_num, UNVISITED);
			dfs(i);
			ans[i] = 1; FOR(j, sz(v[i])) ans[i] = 1LL * ans[i] * (v[i][j].second + 1) % INF; cout<<ans[i]<<" ";
			vector<int> lo, hi; int a = 1, b = 1;
			FOR(j, v[i].size()) {
				lo.push_back(a); hi.push_back(b);
				a = 1LL * a * (v[i][j].second + 1) % INF;
				b = 1LL * b * (v[i][v[i].size() - j - 1].second + 1) % INF;
			}
			FOR(j, sz(v[i])) {
				int u = v[i][j].first;
				int k = rev[i][j];
				v[u][k].second = 1LL * lo[j] * hi[v[i].size() - j - 1] % INF;
				ans[u] = (0LL + INF + ans[i] - v[u][k].second + v[i][j].second) % INF;
			}
		}
	}
}

int main() {
	solve();
	return 0;
}