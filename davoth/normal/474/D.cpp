#include <bits/stdc++.h>

#define ll long long
const ll MAX_N=1e5+1,MOD=1e9+7;
using namespace std;
ll dp[MAX_N];
int main() {
    ll t,k;
    cin >> t >> k;
    ll a[t],b[t];
    for(ll i=0; i<t; i++) cin >> a[i] >> b[i];
    for(ll i=0; i<k; i++) dp[i]=1;
    for(ll i=k; i<MAX_N; i++) dp[i]=(dp[i-1]+dp[i-k])%MOD;
    ll s[MAX_N];
    s[0]=dp[0];
    for(ll i=1; i<MAX_N; i++) s[i]=(s[i-1]+dp[i])%MOD;
    for(ll i=0; i<t; i++) cout << (s[b[i]]-s[a[i]-1]+MOD)%MOD << '\n';
    return 0;
}