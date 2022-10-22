#include<bits/stdc++.h>

using namespace std;

typedef __int128_t ll;
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

int n, x;
int a[MAXN];
ll p[MAXN];

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++) p[i+1] = p[i] + a[i];
    ll ans = 0;
    ll tt = 0;
    for (int i = n; i; i--) {
        ll lo = 0, hi = x / i + 1;
        while (hi-lo>1) {
            ll mid = hi+lo>>1;
            if (p[i] + (mid+ans-1)*i > x)
                hi = mid;
            else
                lo = mid;
        }
        ans += lo;
        tt += lo * i;
    }
    cout << (long long) tt << "\n";
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