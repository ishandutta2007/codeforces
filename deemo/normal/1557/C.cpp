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

const int MAXN = 4e5 + 10;

int ss[MAXN], tt[MAXN];

int choose(int a, int b) {
    if (a < b) return 0;
    return 1ll*ss[a]*tt[b]%MOD*tt[a-b]%MOD;
}

void solve() {
    int n, k; cin >> n >> k;
    if (n&1) {
        int sm = 1;
        for (int t = 0; t < n; t += 2)
            add(sm, choose(n, t));
        cout << pw(sm, k) << "\n";
    } else {
        int temp = pw(2, n);
        int sm = 0, ans = 0;
        for (int t = 0; t < n; t += 2)
            add(sm, choose(n, t));
        for (int i = 0; i < k; i++)
            add(ans, 1ll*pw(sm, i)*pw(temp, k-i-1)%MOD);
        add(ans, pw(sm, k));
        cout << ans << "\n";
    }
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
    ss[0] = 1;
    for (int i = 1; i < MAXN; i++) ss[i] = 1ll*i*ss[i-1] % MOD;
    for (int i = 0; i < MAXN; i++) tt[i] = pw(ss[i], MOD-2);

	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}