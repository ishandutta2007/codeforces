#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 5001;
long long dp[MAX_N][MAX_N]; // dp[l][r]  [l, r] 
int x[MAX_N]; // 
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }
    std::sort(x + 1, x + n + 1);
    for(int r = 1; r <= n; r++) {
        for(int l = r; l > 0; l--) { 
            dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + x[r] - x[l];
        }
    }
    cout << dp[1][n] << endl;
}
int main() {
    solve();
    return 0;
}