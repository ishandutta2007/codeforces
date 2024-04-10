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

ll d[3];

void solve() {
    ll a, b, c; cin >> a >> b >> c;

    ll ans = 4e18;
    if (max({a, b, c}) == 1)
        ans = 0;
    else {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                d[0] = d[1] = d[2] = 0;
                for (int w = i; w < 3; w++)
                    d[w]++;
                for (int w = 0; w <= j; w++)
                    d[w]++;
                ll x = max({0ll, a - d[0], b - d[1], c - d[2]});
                d[0] += x, d[1] += x, d[2] += x;
                ll tmp = max(0ll, d[0] - a) + max(0ll, d[1] - b) + max(0ll, d[2] - c);
                ans = min(ans, tmp);
            }
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