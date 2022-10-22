#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 998244353;

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

const int C = 11;

int d[30][C+1][C+1][C+1];

// last, moves, groups, last2, k, x;
int e[C+1][C+1][C+1][C+1][C+1][C+1];
// groups, non-zeros, k, x
int f[C+1][C+1][C+1][C+1];
int g[C+1][C+1][C+1][C+1];

int choose(int a, int b) {
    if (a < b) return 0;
    int res = 1;
    for (int i = a; i > a-b; i--)
        res = 1ll*res*i%MOD;
    for (int i = 2; i <= b; i++)
        res = 1ll*res*pw(i, MOD-2) %MOD;
    return res;
}

void solve() {
    int n, k, x; cin >> n >> k >> x;
    n--;
    int ans = 0;
    if (n < 30) {
        for (int lst = 0; lst <= C; lst++)
            add(ans, d[n][k][x][lst]);
    } else {
        for (int groups = 0; groups <= k; groups++)
            for (int nz = groups; nz <= k; nz++) {
                ans = (ans + 1ll*f[groups][nz][k][x] * choose(n-29-nz, groups)) % MOD;
                ans = (ans + 1ll*g[groups][nz][k][x] * choose(n-29-nz+1, groups)) % MOD;
            }
    }
    cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
    d[0][0][0][0] = 1;
    for (int moves = 0; moves + 1 < 30; moves++)
        for (int k = 0; k <= C; k++)
            for (int x = 0; x <= C; x++)
                for (int lst = 0; lst <= C; lst++)
                    if (d[moves][k][x][lst])
                        for (int nxt = 0; nxt <= C && nxt <= moves+1; nxt++)
                            if (nxt <= lst) {
                                if (k+nxt <= C)
                                    add(d[moves+1][k+nxt][x][nxt], d[moves][k][x][lst]);
                            } else {
                                if (k+nxt <= C)
                                    add(d[moves+1][k+nxt][x+1][nxt], d[moves][k][x][lst]);
                            }

    // last, moves, groups, last2, k, x;
    for (int i = 0; i <= C; i++) {
        e[i][0][0][i][0][0] = 1;
        for (int moves = 0; moves <= C; moves++)
            for (int groups = 0; groups <= C; groups++)
                for (int lst = C; ~lst; lst--)
                    for (int k = 0; k <= C; k++)
                        for (int x = 0; x <= C; x++) {
                            int pl = e[i][moves][groups][lst][k][x];
                            if (pl) {
                                if (!lst) {  // follow a 0
                                    if (x+1 <= C && moves + 1 <= C)
                                        for (int nxt = 1; k + nxt <= C; nxt++)
                                            add(e[i][moves+1][groups+1][nxt][k+nxt][x+1], pl);
                                } else {
                                    for (int nxt = 0; k + nxt <= C; nxt++)
                                        if (!nxt)
                                            add(e[i][moves][groups][nxt][k][x], pl);
                                        else if (x + (nxt>lst) <= C && moves+1 <= C)
                                            add(e[i][moves+1][groups][nxt][k+nxt][x + (nxt > lst)], pl);
                                }
                            }
                        }
    }

    // groups, non-zeros, k, x
    for (int groups = 0; groups <= C; groups++)
        for (int nz = groups; nz <= C; nz++)
            for (int k = 0; k <= C; k++)
                for (int x = 0; x <= k; x++)
                    for (int kl = 0; kl <= k; kl++)
                        for (int xl = 0; xl <= x; xl++) {
                            add(g[groups][nz][k][x], 1ll*d[29][kl][xl][0] * e[0][nz][groups][0][k-kl][x-xl] % MOD);
                            for (int lst = 1; lst <= kl; lst++)
                                add(f[groups][nz][k][x], 1ll*d[29][kl][xl][lst] * e[lst][nz][groups][0][k-kl][x-xl] % MOD);
                        }
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}