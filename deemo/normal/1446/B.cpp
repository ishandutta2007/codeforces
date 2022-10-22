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

const int MAXN = 5e3 + 10;

int n, m;
string s, t;
int d[MAXN][MAXN];

void solve() {
    cin >> n >> m >> s >> t;
    memset(d, -10, sizeof(d));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            d[i][j] = -2;
            if (s[i-1] == t[j-1]) {
                d[i][j] = max(d[i][j], 2 + max(0, d[i-1][j-1]));
            }
            d[i][j] = max(d[i][j], d[i-1][j] - 1);
            d[i][j] = max(d[i][j], d[i][j-1] - 1);
        }

    int ans = 0;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            ans = max(ans, d[i][j]);
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