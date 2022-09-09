#include<iostream>
#include<algorithm>
using namespace std;
const int MAX_N = 1 << 20;
int dp[MAX_N];
int x[MAX_N], y[MAX_N], t[MAX_N];
void solve() {
    int r, n;
    cin >> r >> n;
    x[0] = y[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        dp[i] = -MAX_N;
        for(int j = i - 1; j >= 0 && i - j <= 2000; j--) {
            if(t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + MAX_N) << '\n';
}
int main() {
    solve();
    return 0;
}