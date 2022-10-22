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

int n;
pair<ll, ll> p[MAXN];

void solve() {
    cin >> n;
    ll sm = 0;
    for (int i = 0; i < n; i++) cin >> p[i].F >> p[i].S, sm += p[i].F * 2;
    sort(p, p + n, [](pair<ll, ll> a, pair<ll, ll> b) {
            return a.S < b.S;
            });

    ll cur = 0;
    int r = n-1;
    for (int i = 0; i < n; i++) {
        while (r > i && cur < p[i].S) {
            if (!p[r].F) {
                r--;
                continue;
            }

            ll g = min(p[i].S - cur, p[r].F);
            cur += g;
            p[r].F -= g;
        }
        cur += p[i].F;
        if (cur > p[i].S)
            sm -= min(p[i].F, cur-p[i].S);
    }
    cout << sm << "\n";
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