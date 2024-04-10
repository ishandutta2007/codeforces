#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

long long inverse(long long n, long long m){
    long long x, y;
    long long g = gcd(n,m, x, y);
    return (x%m+m)%m;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    int arr[n+1];
    for(int i = 0; i<n; i++) cin >> arr[i+1];
    sort(arr+1, arr+n+1);
    long long sum[n+1];
    sum[0] = 0ll;
    for(int i = 1; i<=n; i++) sum[i] = sum[i-1]+arr[i];
    for(int k = 1; k<=n; k++){
        long long ans = 0;
        for(int kk = 1; kk<=ceil((n-k+0.0)/k); kk++){
            int cur1 = n-kk*k;
            int cur2 = n-(kk+1)*k;
            ans += kk*(sum[cur1]-sum[max(0, cur2)]);
        }
        // cout << ans << endl;
        ans %= MOD;
        ans = (ans * inverse(n, MOD))%MOD;
        cout << ans << endl;
    }
}