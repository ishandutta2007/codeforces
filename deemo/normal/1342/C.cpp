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

const int MAXN = 202 * 202;

int a, b, q;
int cnt[MAXN];

ll get(ll r) {
	if (r == 0) return cnt[0];

	ll t = r / (a*b);
	ll res = t * cnt[a*b-1];

	res += cnt[r % (a*b)];
	return res;
}

void solve() {
	cin >> a >> b >> q;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < a*b; i++) {
		if (i)
			cnt[i] = cnt[i-1];
		if (i%a%b ^ i%b%a)
			cnt[i]++;
	}

	while (q--) {
		ll l, r; cin >> l >> r;
		cout << get(r) - get(l-1) << " ";
	}
	cout << "\n";
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