#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
int ex(int b, int st){
    int ans = 1;
    int now = b;
    for (int i=0; i < 40; i++){
        int ba = (1LL << i) & st;
        if (ba == 0){
            now *= now;
            now %= MOD;
            continue;
        }
        ans *= now;
        ans %= MOD;
        now *= now;
        now %= MOD;
    }
    return ans;
}
int res(int a, int b){
    return (ex(b, MOD-2) * a) % MOD;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    if (n + 1 <= k){
        cout << 0 << endl;
        return 0;
    }
    int L = 0;
    vector<int> fact;
    fact.push_back(1);
    for (int i=1; i < 2e6; i++){
        fact.push_back((fact[i-1]*i)%MOD);
    }
    int old = 0;
    vector<int> f(n+1), s(n+1);
    for (int i=0; i <= k+1; i++){
        f[i] = 0;
        s[i] = 0;
    }
    for (int i=k+2; i <= n; i++){
        int N = L * (i-1);
        N += L;
        N += fact[i-2] * (i-k-1);
        old *= (i-2);
        int YY = (f[i-k-2]+s[i-k-2]);
        YY *= fact[i-2];
        YY %= MOD;
        YY = res(YY, fact[i-k-2]);
        old += YY;
        old %= MOD;
        s[i-1] = ((fact[i-2] * (i-k-1) - old) % MOD + MOD) % MOD;
        N -= (old);
        L = (N%MOD + MOD) % MOD;
        f[i] = L % MOD;
    }
    cout << L << endl;
    return 0;
}