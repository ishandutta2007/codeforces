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

int n, m, p[MAXN], x[MAXN];
ll pt[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> p[i]; for (int i = 0; i < m; i++) cin >> x[i];
    sort(x, x + m);
    for (int i = 0; i < n; i++) pt[i+1] = pt[i] + p[i];
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
        if (100 * i < x[0])
            ans += p[i];

    ll tmp = 0;
    for (int i = 0; i < n; i++)
        if (100*i > x[m-1])
            tmp += p[i];
    ans = max(ans, tmp);

    for (int i = 0; i + 1 < m; i++) {
        int l = x[i] / 100 + 1;
        int r = (x[i+1]-1) / 100 + 1;
        l = min(l, n);
        r = min(r, n);
        if (r - l >= 1) {
            int cur = 0;
            for (int j = l; j < r; j++) {
                int pos = 100*j + (100*j-x[i]);
                cur = max(cur, j + 1);
                while (cur < r && (100 * cur < pos || abs(100 * cur - pos) < abs(100 * cur - x[i+1]))) cur++;
                ans = max(ans, pt[cur] - pt[j]);
            }
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