#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 3.1e5;
const int MOD = 998244353;
long long mypow(long long x,long long y){
    x%=MOD;
    long long res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
long long fac[SIZE];
long long inv_fac[SIZE];
void pre() {
    fac[0] = 1;
    for(int i = 1; i < SIZE; i++) {
        fac[i] =  fac[i-1] * i % MOD;
    }
    inv_fac[SIZE - 1] = mypow(fac[SIZE - 1], MOD - 2);
    for(int i = SIZE - 2; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}
long long C(long long n, long long m) {
    if(m < 0 || m > n) {
        return 0;
    }
    return fac[n] * inv_fac[m] % MOD * inv_fac[n - m] % MOD;
}
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<pair<int,int>>AA;
    for(int i = 0; i < n; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        AA.PB(MP(l,-1));
        AA.PB(MP(r,1));
    }
    sort(AA.begin(), AA.end());
    int now = 0;
    long long an = 0;
    for(int i = 0; i < SZ(AA); i++) {
        now -= AA[i].second;
        if(AA[i].second == -1) {
            an = (an + C(now - 1, k - 1)) %MOD;
        }
    }
    printf("%lld\n", an);
}
int main() {
    pre();
    solve();
    return 0;
}