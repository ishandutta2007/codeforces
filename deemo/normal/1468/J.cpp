#include<bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
 
#define F first
#define S second
 
const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX
 
void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}
 
int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}
 
int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}
 
const int MAXN = 2e5 + 10;
const int INF = 1e9+5;

int n, m, k, dsu[MAXN], sz;
array<int,3> edges[MAXN];

int find(int i) {
	return dsu[i] = i == dsu[i] ? i : find(dsu[i]);
}

bool unite(int i, int j) {
	i = find(i), j = find(j);
	if(i == j) {
		return false;
	}
	dsu[i] = j;
	return true;
}

void solve() {
	cin >> n >> m >> k;
	sz = 0;
	for(int i = 0, u, v, w; i < m; i++) { 
		cin >> u >> v >> w;
		--u, --v;
		edges[sz++] = {w - k, u, v};
	}
	sort(edges, edges+sz);
	ll ans = 0, last = 0;
	iota(dsu, dsu+n, 0);
	bool big = false;
	for(int i = 0; i < sz; i++) {
		auto [w, u, v] = edges[i];
		if(unite(u, v)) {
			ans += max(0, w);
			if(w >= 0) {
				big = true;
			}
		}
		if(w <= 0) {
			last = w;
		}
	}
	if(!big) {
		
		ll now = INF;
		
		for(int i = 0; i < sz; i++) {
			if(edges[i][0] >= 0) {
				now = min(now, (ll) edges[i][0]);
			}
		} 
		
		ans = min(-last, now);
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}