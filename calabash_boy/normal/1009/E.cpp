

//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = -1;
const int MOD = 998244353;
#define rep(i,l,r) for (int i=(l);i<(r);i++)
#define vl vector<ll>
string s;
ll ans = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vl a(n + 1, 0), bas(n + 1), dp(n + 1, 0);
    rep(i, 1, n + 1) cin >> a[i];
    bas[0] = 1ll;
    rep(i, 1, n + 1) bas[i] = 2LL*bas[i - 1]%MOD;
    rep(i, 1, n) ans =(ans+a[i] * (n - i + 2)%MOD*bas[n-i-1]%MOD)%MOD;
    ans=(ans+a[n])%MOD;
    cout << ans % MOD<< endl;
}