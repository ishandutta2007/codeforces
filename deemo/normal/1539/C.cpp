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

int n;
ll k, x;
ll a[MAXN];

void solve() {
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int ans = 1;
    vector<ll> vec;
    for (int i = 0; i + 1 < n; i++) {
        ll dif = a[i+1] - a[i];
        ll req = (dif-1)/x;
        if (dif)
            ans++, vec.push_back(req);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    while (vec.size() && vec.back() <= k) {
        k -= vec.back();
        vec.pop_back();
        ans--;
    }
    cout << ans << endl;
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