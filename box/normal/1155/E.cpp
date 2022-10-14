// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
const int MOD = 1000003;

int qpow(int b, int e) {
	int ans = 1;
	while(e) {
		if(e & 1) ans = 1ll * ans * b % MOD;
		b = 1ll * b * b % MOD;
		e >>= 1;
	}
	return ans;
}

int n = 11;
int x[11], y[11], D[11];
void init() {
	rep(i, n) {
		int de = 1;
		rep(j, n) {
			if(i == j) continue;
			de = 1ll * de * (MOD + x[i] - x[j]) % MOD;
		}
		D[i] = qpow(de, MOD - 2);
	}
}
int intp(int v) {
	int ans = 0;
	rep(i, n) {
		int nu = y[i];
		rep(j, n) {
			if(i == j) continue;
			nu = 1ll * nu * (MOD + v - x[j]) % MOD;
		}
		ans = (ans + 1ll * nu * D[i]) % MOD;
	}
	return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    rep(i, 11) {
    	x[i] = i;
    	cout << "? " << i << endl;
    	cin >> y[i];
    }
    init();
    rep(i, MOD)
    	if(!intp(i)) {
    		cout << "! " << i << endl;
    		return 0;
    	}
    cout << "! -1" << endl;
}