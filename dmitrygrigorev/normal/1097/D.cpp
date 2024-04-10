#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 10055, T = 53;
int MOD = 1000000007;
int dp[K][T];
vector<int> obr;
int solve(int num, int vh, int op){
    for (int i=0; i < vh; i++) dp[0][i] = 0;
    dp[0][vh] = 1;
    for (int i=1; i <= op; i++){
        for (int j=0; j <= vh; j++) dp[i][j] = 0;
        for (int j=0; j <= vh; j++){
            for (int p=0; p <= j; p++){
                int V = dp[i-1][j];
                V *= obr[j];
                V %= MOD;
                dp[i][p] += V;
                dp[i][p] %= MOD;
            }
        }
    }
    int res = 0;
    int tet = 1;
    num %= MOD;
    for (int i=0; i <= vh; i++){
        res += tet * dp[op][i];
        res %= MOD;
        tet *= num;
        tet %= MOD;
    }
    return res;
}
int pw(int a, int b){
    if (b==0) return 1;
    if (b==1) return a%MOD;
    if (b%2==0){
        int res = pw(a, b/2);
        return (res*res) % MOD;
    }
    return (pw(a, b-1) * a)%MOD;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=1;i<=1000; i++) obr.push_back(pw(i, MOD-2));
    int n, k;
    cin >> n >> k;
    int cp = n;
    int ans = 1;
    for (int i=2; i*i <= cp; i++){
        int cur = 0;
        while (n % i == 0){
            n /= i;
            cur++;
        }
        if (cur==0) continue;
        ans *= solve(i, cur, k);
        ans %= MOD;
    }
    if (n != 1){
        ans *= solve(n, 1, k);
    }
    cout << ans % MOD;
    return 0;
}