#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_V = 1 << 18;
int cnt[MAX_V], dp[MAX_V];;
void solve() {
    fill(cnt, cnt + MAX_V, 0);
    fill(dp, dp + MAX_V, 0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int an = 0;
    for(int i = 1; i < MAX_V; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j == 0) {
                dp[i] = max(dp[i], dp[j]);
                dp[i] = max(dp[i], dp[i / j]);
            }
        }
        dp[i] += cnt[i];
        an = max(an, dp[i]);
    }
    cout << n - an << '\n';
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}