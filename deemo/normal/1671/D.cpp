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

int n, x, a[MAXN];

void solve() {
    cin >> n >> x;
    int mx = -1;
    ll sm = 0;
    for (int i = 0; i < n; i++) cin >> a[i], mx = max(mx, a[i]);
    for (int i = 0; i + 1 < n; i++)
        sm += abs(a[i+1] - a[i]);

    ll tsm = sm;
    ll ans = sm + abs(a[0] - x);
    for (int i = 0; i < n; i++)
        ans = min(ans, sm + abs(a[i] - x) + (i+1==n? 0: abs(a[i+1] - x)) - (i+1==n? 0: abs(a[i+1] - a[i])));
    sm = ans;
    ans = sm + abs(a[0] - 1);
    for (int i = 0; i < n; i++)
        ans = min(ans, sm + abs(a[i] - 1) + (i+1==n? 0: abs(a[i+1] - 1)) - (i+1==n? 0: abs(a[i+1] - a[i])));
    ans = min(ans, tsm + x-1 + abs(a[0] - x));
    ans = min(ans, tsm + x-1 + abs(a[n-1] - x));
    ans = min(ans, tsm + x-1 + abs(a[0] - 1));
    ans = min(ans, tsm + x-1 + abs(a[n-1] - 1));

    for (int i = 0; i + 1 < n; i++) {
        ans = min(ans, tsm + x-1 + abs(a[i] - 1) + abs(x - a[i+1]) - abs(a[i+1]-a[i]));
        ans = min(ans, tsm + x-1 + abs(a[i] - x) + abs(1 - a[i+1]) - abs(a[i+1]-a[i]));
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}