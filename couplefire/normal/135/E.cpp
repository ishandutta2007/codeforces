#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int binpow(int a, int b) {
    a %= MOD;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = 1ll*res * a % MOD;
        a = 1ll*a * a % MOD;
        b >>= 1;
    }
    return res;
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int inverse(int n, int m){
    int x, y;
    int g = gcd(n,m, x, y);
    return (x%m+m)%m;
}

int k, w;
int fac[1000005];
int invfac[1000005];

int get(int m, int l){
    if(k-m < 0) return -1;
    if(l-2*m < 0){
        int aa = 1ll*fac[k]*invfac[k-(2*m-l)]%MOD;
        int bb = 1ll*fac[k-(2*m-l)]*invfac[k-(2*m-l)-(l-m)]%MOD;
        bb = (1ll*bb*bb)%MOD;
        int ans = 1ll*aa*bb%MOD;
        return ans;
    }
    int aa = binpow(k, l-2*m);
    int bb = 1ll*fac[k]*invfac[k-m]%MOD;
    bb = (1ll*bb*bb)%MOD;
    int ans = 1ll*aa*bb%MOD;
    return ans;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> w;
    fac[0] = 1;
    for(int i = 1; i<=k; i++) fac[i] = (1ll*fac[i-1]*i)%MOD;
    for(int i = 0; i<=k; i++){
        invfac[i] = inverse(fac[i], MOD);
    }
    int ans = 0;
    int l = w+1;
    int tmp;
    while((tmp = get(l-w, l)) >= 0){
        ans += tmp;
        if(ans >= MOD) ans -= MOD;
        l++;
    }
    l = w+1;
    while((tmp = get(l-w+1, l)) >= 0){
        ans -= tmp;
        if(ans < 0) ans += MOD;
        l++;
    }
    cout << ans << endl;
}