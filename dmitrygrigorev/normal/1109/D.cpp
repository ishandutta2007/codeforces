#include<bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
const int K = 1000007;
int fact[K], obr[K], pwn[K], pwm[K];
int pw(int a, int b){
    if (b==0) return 1;
    if (b==1) return a%MOD;
    if (b%2!=0){
        return (a*pw(a, b-1))%MOD;
    }
    int S = pw(a, b/2);
    return (S*S)%MOD;
}
int C(int n, int k){
    if (n < k) return 0;
    int A = fact[n], B = (obr[k] * obr[n-k])%MOD;
    return (A*B)%MOD;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(NULL));
    fact[0] = 1;
    for (int i=1; i < K; i++) fact[i] = (fact[i-1] * i) % MOD;
    for (int i=0; i < K; i++) obr[i] = pw(fact[i], MOD-2);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    pwn[0] = 1;
    for (int i=1; i < K; i++) pwn[i] = (pwn[i-1]*n)%MOD;
    pwm[0] = 1;
    for (int i=1; i < K; i++) pwm[i] = (pwm[i-1]*m)%MOD;
    int ans = 0;
    for (int path=2; path <= n; path++){
        int kek = 1;
        if (path < n){
            kek = path * pwn[n-path-1];
            kek %= MOD;
        }
        kek *= fact[n-2];
        kek %= MOD;
        kek *= obr[n-path];
        kek %= MOD;
        //cout <<  << endl;
        kek *= pwm[n-path];
        kek %= MOD;
        kek *= C(m-1, path-2);
        kek %= MOD;
        ans += kek;
        //cout << ans << endl;
    }
    cout << ans%MOD;
}