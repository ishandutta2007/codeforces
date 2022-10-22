//If you're trying to find pity well you need to look somewhere else
//Cause I surely can't help you
//I'm hurting myself
//I've turned into someone else..

#include<iostream>
#include<algorithm>
#include<utility>
#include<iomanip>
#include<vector>

using namespace std;

typedef long long ll;
typedef long double ld;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n;
ll d[MAXN], sz[MAXN], cnt[MAXN];
vector<pair<int, int>>	adj[MAXN];

bool cmp(pair<int, int> uu, pair<int, int> vv){
	int u = uu.F, v = vv.F;
	return cnt[u] * sz[v] > cnt[v] * sz[u];
}

void dfs(int v, int p = -1){
	for (int i = 0; i < adj[v].size(); i++)
		if (adj[v][i].F == p){
			adj[v].erase(adj[v].begin() + i);
			break;
		}

	cnt[v] = 1;
	for (auto e:adj[v]){
		int u = e.F;
		dfs(u, v);
		cnt[v] += cnt[u];
		sz[u] += 2ll * e.S;
		sz[v] += sz[u];
	}
	sort(adj[v].begin(), adj[v].end(), cmp);
}

ll sm = 0, t = 0;

void go(int v){
	sm += t;
	for (auto e:adj[v])
		t += e.S, go(e.F), t += e.S;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b, c;	cin >> a >> b >> c, a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(0);
	go(0);
	cout << fixed << setprecision(9) << sm/ ld(n - 1) << "\n";
	return 0;
}