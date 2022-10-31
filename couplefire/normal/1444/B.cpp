#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[2*n];
    int fac[2*n+1];
    fac[0] = 1;
    for(int i = 1; i<2*n+1; i++) fac[i] = 1ll*fac[i-1]*i%MOD;
    for(int i = 0; i<2*n; i++) cin >> arr[i];
    sort(arr, arr+2*n);
    long long sum1 = 0, sum2 = 0;
    for(int i = 0; i<n; i++) sum1 += arr[i];
    for(int i = n; i<2*n; i++) sum2 += arr[i];
    cout << 1ll*(sum2 - sum1)%MOD*fac[2*n]%MOD*binpow(fac[n], MOD-2, MOD)%MOD*binpow(fac[n], MOD-2, MOD)%MOD << endl;
    
}