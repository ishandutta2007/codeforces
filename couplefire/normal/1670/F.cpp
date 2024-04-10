#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MOD = 1000000007;

inline int add(int a, int b){return a+b>=MOD?a+b-MOD:a+b;}
inline int sub(int a, int b){return a-b<0?a-b+MOD:a-b;}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void inc(int& a, int b){a = add(a, b);}
inline void dec(int& a, int b){a = sub(a, b);}
inline void grow(int& a, int b){a = mul(a, b);}

int solve(int n, ll r, ll z){
    vector<vector<int>> dp(65, vector<int>(n+1, 0));
    vector<vector<int>> comb(n+1, vector<int>(n+1, 0));
    for(int i = 0; i<=n; ++i){
        comb[i][0] = 1;
        for(int j = 1; j<=i; ++j)
            comb[i][j] = add(comb[i-1][j-1], comb[i-1][j]);
    }
    dp[64][0] = 1;
    for(int i = 63; i>=0; --i){
        int tmp = ((r>>i)&1);
        for(int j = 0; j<=n; ++j){
            for(int k = ((z>>i)&1); k<=n; k+=2){
                if((j<<1)-k+tmp<0) continue;
                inc(dp[i][min(n, (j<<1)-k+tmp)], mul(dp[i+1][j], comb[n][k]));
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<=n; ++i)
        inc(ans, dp[0][i]);
    return ans;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int n; ll l, r, z;
    cin >> n >> l >> r >> z;
    cout << sub(solve(n, r, z), solve(n, l-1, z)) << '\n';
}