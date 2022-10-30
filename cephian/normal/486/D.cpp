#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 2005, M = 1e9+7;
int d,n,a[N];
vvi T;

ll dfs(int u, int v, int mn, int ind) {
	ll ans = 1;
	for(int w : T[v]) {
		if(w == u || a[w] > mn+d || a[w] < mn || (a[w]==mn && w > ind)) continue;
		ans *= 1+dfs(v,w,mn,ind);
		ans %= M;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> d >> n;
	T = vvi(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 1; i < n; ++i) {
		int u,v;
		cin >> u >> v;
		--u;--v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	ll ans = 0;
	for(int v = 0; v < n; ++v) {
		ll k = dfs(-1,v,a[v],v);
		ans = (ans+k)%M;
	}
	cout << ans << "\n";
	return 0;
}