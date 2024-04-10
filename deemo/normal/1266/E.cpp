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

int n, a[MAXN];
ll sm = 0;
map<pii, int> mp;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], sm += a[i];
	ll ans = sm;
	int q;	cin >> q;
	while (q--){
		int s, t, u; cin >> s >> t >> u, s--;
		int prev = mp[{s, t}];
		if (prev) {
			prev--;
			a[prev]++;
			if (a[prev] > 0)
				ans++;
		}
		mp[{s, t}] = u;
		if (u){
			u--;
			a[u]--;
			if (a[u] >= 0)
				ans--;
		}

		cout << ans << "\n";
	}
	return 0;
}