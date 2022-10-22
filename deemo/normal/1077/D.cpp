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

int n, k, a[MAXN];
int ans[MAXN];
int cnt[MAXN];

bool check(int mid) {
    int t = 0;
    for (int i = 0; i < MAXN; i++)
        t += cnt[i]/mid;
    if (t < k) return false;
    t = 0;
    int cur = 0;
    for (int i = 0; i < MAXN; i++) {
        int g = min(cnt[i]/mid, k - t);
        for (int j = 0; j < g; j++)
            ans[cur++] = i;
        t += g;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
    int lo = 1, hi = n + 1;
    while (hi-lo>1) {
        int mid = hi+lo>>1;
        if (check(mid))
            lo = mid;
        else
            hi = mid;
    }
    check(lo);
    for (int i = 0; i < k; i++)
        cout << ans[i] << " ";
    cout << "\n";
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