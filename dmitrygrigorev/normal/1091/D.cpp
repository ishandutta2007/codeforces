#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> fact;
int MOD = 998244353;
int solve(int n){
    if (n==1) return 0;
    return (n*solve(n-1) + fact[n] - n)%MOD;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fact.push_back(1);
    for (int i=1; i < 2e6; i++){
        fact.push_back((fact.back() * i)%MOD);
    }
    int ans = fact[n] + solve(n);
    cout << ans%MOD;
    return 0;
}