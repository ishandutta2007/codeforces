#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a[1<<20]={}, t, n, p[1<<20]={1}, f[1<<20]={};
#define rep(i, n) for(int i = 0; i < n; ++i)
int main() {
    scanf("%d", &n); rep(i, n) { scanf("%d", &t); f[t]++; }
    rep(i, n) p[i+1]=p[i]*2%mod;
    rep(i, 20) rep(j, (1<<20)) if(!(j>>i&1)) f[j]+=f[j+(1<<i)]; else a[j]^=1;
    long long ans = 0; rep(i, (1<<20)) ans = (ans+(p[f[i]]*(a[i]?-1:1)) + mod) %mod;
    printf("%I64d", ans);
    return 0;
}