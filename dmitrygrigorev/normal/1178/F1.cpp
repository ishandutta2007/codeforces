#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int sum(int a, int b){
    if (a+b<0) return a+b+mod;
    if (a+b >= mod) return a+b-mod;
    return a+b;
}
int mult(int a, int b){
    return ((ll) a * (ll) b) %  (ll) mod;
}
int dp[501][501];
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    for (int i=0; i <= n; i++) dp[i][0] = 1;
    for (int len=1; len <= n; len++){
        for (int i=0; i+len <= n; i++){
            int A = i, B = i+len-1;
            int index = -1, mn = 1e9;
            for (int j=A; j <= B; j++) if (v[j] <= mn){
                mn = v[j];
                index = j;
            }
            int lsum = 0, rsum = 0;
            int len_left = index - i;
            for (int j=0; j <= len_left; j++){
                lsum = sum(lsum, mult(dp[i][j], dp[i+j][len_left-j]));
            }
            int len_right = B-index;
            for (int j=0; j <= len_right; j++){
                rsum = sum(rsum, mult(dp[index+1][j], dp[index+1+j][len_right-j]));
            }
            dp[i][len] = mult(lsum, rsum);
            //cout << i << " " << len << " " << dp[i][len] << endl;
        }
    }
    cout << dp[0][n];
}