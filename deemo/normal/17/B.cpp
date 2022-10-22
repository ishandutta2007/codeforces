#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second 

const int MAXN = 1e3 + 10;
const ll INF = 2e9;

int n, a[MAXN], sec[MAXN];
vector<pair<int, ll>>	adj[MAXN];

bool cmp(int u, int v){return a[u] > a[v];}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	int m;	cin >> m;
	while (m--){
		int a, b, c;	cin >> a >> b >> c, a--, b--;
		adj[b].push_back({a, c});
	}
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	if (n > 1 && a[sec[0]] == a[sec[1]]){
		cout << "-1\n";
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i < n; i++){
		int v = sec[i];
		ll mn = INF;
		for (auto e:adj[v])
			mn = min(mn, e.S);
		ans += mn;
	}

	if (ans >= INF)
		ans = -1;
	cout << ans << endl;
	return 0;
}