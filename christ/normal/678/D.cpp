// https://codeforces.com/contest/678/problem/D
 
#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
 
const int MOD = 1000000007;
 
int modpow(int a, int exp){
    if(exp == 0) return 1;
    int t = modpow(a, exp/2);
    t %= MOD;
    if(exp%2) {
        return (t*t % MOD) * (a % MOD) % MOD;
    } else {
        return t*t%MOD;
    }
}
 
int geosum(int a, int r, int n) {
	if (r==1) return n;
    return (a%MOD * ((modpow(r, n)-1)%MOD * modpow(r-1, MOD-2) % MOD)) % MOD;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
 
    int A, B, n, x;
    cin >> A >> B >> n >> x;
 
    int ans;
    ans = (modpow(A, n)%MOD*x%MOD)%MOD + (B%MOD)*(geosum(1, A, n)%MOD)%MOD;
 
    ans = ans % MOD;
 
    cout << ans << endl;
}