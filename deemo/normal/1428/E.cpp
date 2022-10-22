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

const int MAXN = 1e5 + 10;

int n, k, a[MAXN];
int cuts[MAXN];
set<pair<ll, int>> st;
ll cost[MAXN];

ll calc(int ln, int c) {
	c++;
	if (c >= ln)
		return ln;

	int dv = ln/c;
	int rem = ln%c;
	ll cs = 1ll*(c - rem)*dv*dv;
	cs += 1ll*rem*(dv+1)*(dv+1);
	return cs;
}

void solve() {
	cin >> n >> k; k -= n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[i] = x;
		cost[i] = 1ll*x*x;
		st.insert({cost[i] - calc(a[i], cuts[i] + 1), i});
		ans += cost[i];
	}

	while (k--) {
		auto x = *st.rbegin();
		st.erase(x);
		int id = x.second;
		ans -= cost[id];
		cuts[id]++;
		cost[id] = calc(a[id], cuts[id]);
		st.insert({cost[id] - calc(a[id], cuts[id]+1), id});
		ans += cost[id];
	}
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}