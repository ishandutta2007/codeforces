#include <bits/stdc++.h>
#define int long long
int MOD = 1000000007;
using namespace std;
int pw(int a, int b){
    if (b==1) return a;
    if (b%2==1){
        int x = pw(a, b-1);
        return (x*a)%MOD;
    }
    int x = pw(a, b/2);
    return (x*x)%MOD;
}
int obr(int x){
    return pw(x, MOD-2);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i=0; i < n; i++){
        cin >> a[i];
    }
    for (int i=0; i < n; i++){
        cin >> b[i];
    }
    int v1 = 0, v2 = 1, A = 1, B = 1;
    for (int i=0; i < n; i++){
        if (a[i] == 0 && b[i] == 0){
            int v3 = (A*(m-1))%MOD;
            int v4 = (B*2*m)%MOD;
            int V1 = (v1*v4+v3*v2) % MOD;
            int V2 = (v2*v4) % MOD;
            v1 = V1, v2 = V2;
            B = (B*m) % MOD;
        }
        else if (a[i] == 0){
            int tv = m - b[i];
            int v3 = (A*tv)%MOD;
            int v4 = (B*m)%MOD;
            int V1 = (v1*v4+v3*v2) % MOD;
            int V2 = (v2*v4) % MOD;
            v1 = V1, v2 = V2;
            B = (B*m) % MOD;
        }
        else if (b[i] == 0){
            int tv = A*(a[i] - 1)%MOD;
            int v3 = tv;
            int v4 = (B*m)%MOD;
            int V1 = (v1*v4+v3*v2) % MOD;
            int V2 = (v2*v4) % MOD;
            v1 = V1, v2 = V2;
            B = (B*m) % MOD;
        }
        else{
            if (a[i] > b[i]){
                int v3 = A;
                int v4 = B;
                int V1 = (v1*v4+v3*v2) % MOD;
                int V2 = (v2*v4) % MOD;
                v1 = V1, v2 = V2;
                break;
            }
            if (b[i] > a[i]){
                break;
            }
        }
    }
    v1 %= MOD;
    if (v1 < MOD) v1 += MOD;
    v2 %= MOD;
    if (v2 < MOD) v2 += MOD;
    cout<< (v1 * obr(v2)) % MOD;
    return 0;
}