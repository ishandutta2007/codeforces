#include<bits/stdc++.h>
const int N = 305;
const int mod = 1e9 + 7;
using namespace std;

map <int, int> mp;

int n, dp[N], fact[N], C[N][N], g[N];

void add(int&a, int b){
    a += b; if (a >= mod) a -= mod;
}

int main(){
    cin >> n;
    for (int i = 0; i < N; i++) for (int j = 0; j <= i; j++) C[i][j] = ((j == 0) ? 1 : (C[i-1][j] + C[i-1][j-1]) % mod);
    for (int i = 0; i < N; i++) fact[i] = ((i == 0) ? 1 : 1LL * fact[i-1] * i % mod);
    for (int i = 1; i <= n; i++){
        int x, y = 1; cin >> x;
        for (int j = 2; 1LL * j * j <= x; j++){
            int cnt = 0; while (x % j == 0) cnt ^= 1, x /= j;
            if (cnt) y *= j;
        }
        y *= x;
        mp[y]++;
    }
    n = 0;
    dp[0] = 1;
    for (auto& pr : mp){
        int x = pr.second;
        for (int i = 0; i < N; i++) g[i] = 0;
        for (int i = 0; i <= n; i++){
            for (int k = 1; k <= min(n+1, x); k++){
                for (int s = 0; s <= min(k, i); s++){
                    add(g[i-s+x-k], 1LL * C[i][s] * C[n+1-i][k-s] % mod * fact[x] % mod * C[x-1][k-1] % mod * dp[i] % mod);
                }
            }
        }
        for (int i = 0; i < N; i++) dp[i] = g[i]; n += x;
    }
    cout << dp[0];
}