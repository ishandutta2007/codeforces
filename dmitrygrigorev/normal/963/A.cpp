#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000009;
int pw(int a, int b){
    if (b==0) return 1;
    if (b==1) return a%MOD;
    if (b%2){
        int rs = pw(a, b-1);
        return (rs*a)%MOD;
    }
    int rs = pw(a, b/2);
    return (rs*rs)%MOD;
}
vector<int> sm;
int solve(int a, int b){
    if (b==0) return 0;
    for (int i=0; i < 35; i++){
        int ba = (1LL<<i) & b;
        if (ba==0) continue;
        return (sm[i] + solve(a, b-(1LL<<i)) * pw(a, (1LL<<i))) % MOD;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int X = 1, Y = 1;
    for (int i=0; i < k; i++){
        X *= b;
        X %= MOD;
    }
    for (int i=0; i < k; i++){
        Y *= a;
        Y %= MOD;
    }
    X *= pw(Y, MOD-2);
    X %= MOD;
    sm.push_back(1);
    for (int i=0; i < 40; i++){
        sm.push_back(sm.back() + sm.back() * pw(X, (1LL<<i)));
        sm.back() %= MOD;
    }
    int st = solve(X, (n+1)/k);
    int ans = 0;
    for (int i=0; i < k; i++){
        int rs = (pw(b, i) * pw(a, n-i)) % MOD;
        if (s[i] == '-') rs *= -1;
        rs *= st;
        ans += rs;
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}