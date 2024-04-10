#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

const int MAXN = 1e3 + 10;
const int C = 62;

int n, ch[MAXN][MAXN], d[C+2][2*MAXN][2];
ll z, dif;

int get(ll r) {
    if (r < z) return 0;
    dif = r - z;
    memset(d, 0, sizeof(d));
    d[C-1][0][0] = 1;
    for (int w = C-1; w; w--)
        for (int rem = 0; rem <= n*2; rem += 2)
            if (d[w][rem][0] || d[w][rem][1]) {
                for (int t = 0; t <= min(n, rem); t += 2)
                    if (rem - t << 1 < 2*MAXN) {
                        d[w-1][rem-t<<1][1] = (d[w-1][rem-t<<1][1] + 1ll*ch[n][t+(z>>w-1&1)]*d[w][rem][1]) % MOD;
                        if ((rem-t<<1) + 2 < 2*MAXN)
                            d[w-1][(rem-t<<1)+2][1] = (d[w-1][(rem-t<<1)+2][1] + 1ll*ch[n][t+(z>>w-1&1)]*d[w][rem][1]) % MOD;
                        
                        d[w-1][rem-t<<1][dif>>w-1&1] = (d[w-1][rem-t<<1][dif>>w-1&1] + 1ll*ch[n][t+(z>>w-1&1)]*d[w][rem][0]) % MOD;
                        if (dif>>w-1&1 && (rem-t<<1)+2 < 2*MAXN)
                            d[w-1][(rem-t<<1)+2][0] = (d[w-1][(rem-t<<1)+2][0] + 1ll*ch[n][t+(z>>w-1&1)]*d[w][rem][0]) % MOD;
                    }
            }
    return fix(d[0][0][0] + d[0][0][1]);
}

void solve() {
    for (int i = 0; i < MAXN; i++) {
        ch[i][0] = 1;
        for (int j = 1; j <= i; j++)
            ch[i][j] = fix(ch[i-1][j] + ch[i-1][j-1]);
    }

    ll l, r; cin >> n >> l >> r >> z;
    cout << fix(get(r) - get(l-1)) << "\n";
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