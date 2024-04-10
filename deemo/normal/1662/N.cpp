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

const int MAXN = 1500 + 10;

int n, a[MAXN][MAXN];
pii sec[MAXN*MAXN];
int sz;
int cnt[2][MAXN];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j], sec[sz++] = {i, j};
    sort(sec, sec + sz, [](pii p, pii q) {
            return a[p.F][p.S] < a[q.F][q.S];
            });

    ll ans = 0;
    for (int i = 0; i < sz; i++) {
        auto [r, c] = sec[i];
        ans += cnt[0][r] * (n-1-cnt[1][c]);
        ans += (n-1-cnt[0][r]) * cnt[1][c];
        cnt[0][r]++;
        cnt[1][c]++;
    }
    cout << ans / 2 << "\n";
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