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

void solve() {
    int n, k, a, b; cin >> n >> k >> a >> b;
    if (k == 1)
        cout << 1ll*(n-1)*a << "\n";
    else {
        ll ans = 0;
        while (n>1) {
            if (n%k)
                ans += 1ll*a*(n%k), n -= n%k;
            else {
                ll dif = n - n/k;
                if (dif * a >= b)
                    ans += b;
                else
                    ans += dif * a;
                n /= k;
            }
        }
        if (n == 0)
            ans -= a;
        cout << ans << "\n";
    }
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