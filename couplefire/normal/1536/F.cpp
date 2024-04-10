#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;
const int MOD = 1000000007;

int bpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1) res = 1ll*res*a%MOD;
        a = 1ll*a*a%MOD;
        b >>= 1;
    }
    return res;
}

int inv(int a){return bpow(a, MOD-2);}

int n;
int fact[N], pw[N], ifact[N];

int comb(int a, int b){
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    return 1ll*fact[a]*(1ll*ifact[b]*ifact[a-b]%MOD)%MOD;
}

int main(){
    // freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0] = 1;
    for(int i = 1; i<N; i++)
        fact[i] = 1ll*fact[i-1]*i%MOD;
    for(int i = 0; i<N; i++)
        ifact[i] = inv(fact[i]);
    pw[0] = 1;
    for(int i = 1; i<N; i++)
        pw[i] = 2*pw[i-1]%MOD;
    cin >> n; int ans = 0;
    for(int i = n%2; i<=n/2; i+=2){
        int ways = 2ll*(0ll+comb(n-i+1, i)-comb(n-i-1, i-2)+MOD)%MOD;
        int a = (n-i+1)/2, b = n-i-a;
        ways = 1ll*ways*fact[a]%MOD;
        ways = 1ll*ways*fact[b]%MOD;
        ways = 1ll*ways*comb(n-i, a)%MOD;
        ans = (ans+ways)%MOD;
    }
    cout << ans << endl;
}