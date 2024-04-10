#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const int maxn = 3e5 + 10;
ll fac[maxn];
int main(){
    cin>>n>>m;
    fac[0] = 1;
    for (int i=1;i<maxn;i++)fac[i] = fac[i-1] * i % m;
    ll ans = 0;
    for (int len = 1;len <= n;len ++){
        ll temp = 1ll * (n - len + 1) * fac[len] % m * (n - len + 1) % m * fac[n - len] % m;
        (ans += temp) %= m;
    }
    cout<<ans<<endl;
    return 0;
}