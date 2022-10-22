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
 
const int MAXN = 1e5 + 10;
 
int n, x[MAXN], y[MAXN], xx[MAXN], yy[MAXN];
map<pii, int> cnt;
 
void solve() {
    cnt.clear();
    cin >> n;
    int pos = 0, neg = 0;
    int pos2 = 0, neg2 = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> xx[i] >> yy[i];
        if (x[i] == xx[i]) {
            if (y[i] > yy[i])
                pos++;
            else
                neg++;
        } else if (y[i] == yy[i]) {
            if (x[i] > xx[i])
                pos2++;
            else
                neg2++;
        } else {
            int rise = yy[i] - y[i];
            int run = xx[i] - x[i];
            int g = abs(__gcd(rise, run));
            rise /= g;
            run /= g;
             
            ans += cnt[{-rise, -run}];
            cnt[{rise, run}]++;
        }
    }
    ans += 1ll*pos*neg + 1ll*pos2*neg2;
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