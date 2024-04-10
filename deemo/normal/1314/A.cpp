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

int n;
pii p[MAXN];
set<pii> st;
ll xx;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].F;
	for (int i = 0; i < n; i++) cin >> p[i].S;
	sort(p, p + n);

	int ptr = 0;
	ll ans = 0;
	for (int i = 0; i < (int)2e9; i++) {
		while (ptr < n && p[ptr].F == i) 
			st.insert({p[ptr].S, ptr}), xx += p[ptr++].S;

		if (st.empty()) {
			if (ptr == n) break;
			i = p[ptr].F - 1;
			continue;
		}

		auto x = *st.rbegin();
		st.erase(x);
		xx -= x.F;
		ans += xx;
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