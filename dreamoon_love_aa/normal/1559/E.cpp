#include<iostream>
#include<algorithm>
#include<vector>
#define SZ(X) ((int)(X).size())
using namespace std;
const int MOD = 998'244'353;
const int MAX_N = 50;
const int MAX_M = 100000;
int n, m;
int l[MAX_N + 1], r[MAX_N + 1];
void sub(int &x, int v) {
    x -= v;
    if(x < 0) { x += MOD; }
}
void add(int &x, int v) {
    x += v;
    if(x >= MOD) { x -= MOD; }
}
int f(int gg) {
    vector<int> dp(MAX_M / gg + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        int ll = (l[i] - 1) / gg;
        int rr = r[i] / gg;
        if(ll >= rr) {
            return 0;
        }
        ll++;
        for(int j = 1; j < SZ(dp); j++) {
            add(dp[j], dp[j - 1]);
        }
        for(int j = SZ(dp) - 1; j >= 0; j--) {
            dp[j] = j >= ll ? dp[j - ll] : 0;
            if(j > rr) sub(dp[j], dp[j - rr - 1]);
        }
    }
    int an = 0;
    for(int i = 0; i <= m / gg; i++) {
        add(an, dp[i]);
    }
    return an;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    vector<int> dp(MAX_M + 1);
    for(int i = MAX_M; i > 0; i--) {
        dp[i] = f(i);
        for(int j = i + i; j <= MAX_M; j += i) {
            sub(dp[i], dp[j]);
        }
    }
    cout << dp[1] << '\n';
}
int main() {
    solve();
    return 0;
}