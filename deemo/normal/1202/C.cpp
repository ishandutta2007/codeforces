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

int mp[200];
int a[MAXN], n;
pii tl[MAXN], tr[MAXN];

pii get(string s){
	n = 0;
	for (char c: s)
		a[n++] = mp[c];
	tr[n] = {0, 0};
	for (int i = n-1; ~i; i--){
		tr[i] = tr[i+1];
		tr[i].F += a[i];
		tr[i].S += a[i];
		tr[i].F = min(tr[i].F, 0);
		tr[i].S = max(tr[i].S, 0);
	}

	int sm = 0, ret = 1e9;
	pii cur(0, 0);
	for (int i = 0; i <= n; i++){
		for (int w = -1; w <= 1; w++)
			if (w)
				ret = min(ret, max(cur.S, tr[i].S+sm+w) - min(cur.F, tr[i].F+sm+w) + 1);

		sm += a[i];
		if (i < n) {
			cur.F = min(cur.F, sm);
			cur.S = max(cur.S, sm);
		}
	}
	return {abs(cur.S) + abs(cur.F) + 1, ret};
}

void solve() {
	mp['W'] = 1;
	mp['S'] = -1;
	mp['A'] = 1;
	mp['D'] = -1;

	string s;
	cin >> s;
	string a, b;
	for (char c: s)
		if (c == 'W' || c == 'S')
			a += c;
		else
			b += c;

	auto x = get(a);
	auto y = get(b);
	ll ans = min({1ll*x.F*y.F, 1ll*x.F*y.S, 1ll*x.S*y.F});
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