#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005
#define MOD 998244353

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int dp[MAXN][MAXN] = {{0}};
int derange[MAXN];
int derangepow[MAXN];
int fac[MAXN];
int n;
int grid[MAXN][MAXN];

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cin >> grid[i][j];
    }
    derange[0] = 1;
    derange[1] = 0;
    for(int i = 2; i<MAXN; i++){
        derange[i] = (1ll*(i-1)*(derange[i-1]+derange[i-2]))%MOD;
    }
    derangepow[0] = 1;
    for(int i = 1; i<MAXN; i++) derangepow[i] = (1ll*derangepow[i-1]*derange[n])%MOD;
    fac[0] = 1;
    for(int i = 1; i<MAXN; i++) fac[i] = (1ll*fac[i-1]*i)%MOD;
    for(int i = 0; i<MAXN; i++){
        dp[i][0] = derange[i];
        for(int j = 1; j<MAXN; j++){
            dp[i][j] = (1ll*j*dp[i-1][j-1]+1ll*(i-j)*dp[i-1][j])%MOD;
        }
    }
    int ans = 0;
    FenwickTree f(n+5);
    for(int i = 0; i<n; i++) f.add(grid[0][i], 1);
    for(int i = 0; i<n; i++){
        ans += ((1ll*f.sum(0, grid[0][i]-1)*fac[n-1-i]%MOD)*derangepow[n-1])%MOD;
        if(ans < 0) ans += MOD;
        if(ans >= MOD) ans -= MOD;
        f.add(grid[0][i], -1);
    }
    for(int i = 1; i<n; i++){
        FenwickTree f1(n+5);
        FenwickTree f2(n+5);
        int dif[n+1];
        int arr1[n+1];
        int arr2[n+1];
        dif[n] = 0;
        for(int i = 1; i<=n; i++) arr1[i] = 0, arr2[i] = 0;
        for(int j = n-1; j>=0; j--){
            dif[j] = dif[j+1];
            if(arr2[grid[i-1][j]]) arr2[grid[i-1][j]] = 0, --dif[j];
            else arr1[grid[i-1][j]] = 1;
            if(arr1[grid[i][j]]) arr1[grid[i][j]] = 0, --dif[j];
            else arr2[grid[i][j]] = 1;
            ++dif[j];
        }
        // for(int j = 0; j<n; j++) cout << dif[j] << " ";
        // cout << endl;
        for(int j = 1; j<=n; j++) arr1[j] = 1;
        for(int j = 0; j<n; j++){
            f1.add(grid[i-1][j], 1);
            f2.add(grid[i-1][j], 1);
        }
        for(int j = 0; j<n; j++){
            bool flag = false;
            if(f2.sum(grid[i-1][j], grid[i-1][j])){
                f2.add(grid[i-1][j], -1);
                flag = true;
            }
            if(f1.sum(grid[i-1][j], grid[i-1][j])) f1.add(grid[i-1][j], -1);
            arr1[grid[i-1][j]] = 0;
            int tot = f2.sum(0, grid[i][j]-1);
            int good = f1.sum(0, grid[i][j]-1);
            int bad = tot-good;
            if(arr1[grid[i][j]]){
                if(bad) ans += (1ll*bad*dp[n-1-j][dif[j+1]-1]%MOD)*derangepow[n-1-i]%MOD;
                if(ans < 0) ans += MOD;
                if(ans >= MOD) ans -= MOD;
                // cout << i+1 << " " << j+1 << " " << ans << endl;
                if(good) ans += (1ll*good*dp[n-1-j][dif[j+1]]%MOD)*derangepow[n-1-i]%MOD;
                if(ans < 0) ans += MOD;
                if(ans >= MOD) ans -= MOD;
                // cout << i+1 << " " << j+1 << " " << ans << " " << derangepow[n-1-j] << endl;
            }
            else{
                if(bad) ans += (1ll*bad*dp[n-1-j][dif[j+1]]%MOD)*derangepow[n-1-i]%MOD;
                if(ans < 0) ans += MOD;
                if(ans >= MOD) ans -= MOD;
                // cout << i+1 << " " << j+1 << " " << ans << endl;
                if(good) ans += (1ll*good*dp[n-1-j][dif[j+1]+1]%MOD)*derangepow[n-1-i]%MOD;
                if(ans < 0) ans += MOD;
                if(ans >= MOD) ans -= MOD;
                // cout << i+1 << " " << j+1 << " " << ans << endl;
            }
            if(flag) f2.add(grid[i-1][j], 1);
            if(f2.sum(grid[i][j], grid[i][j])) f2.add(grid[i][j], -1);
            if(f1.sum(grid[i][j], grid[i][j])) f1.add(grid[i][j], -1);
        }
    }
    cout << ans << endl;
}