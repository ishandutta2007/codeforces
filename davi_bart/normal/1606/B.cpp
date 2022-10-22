#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve() {
    int N, K;
    cin >> N >> K;
    int cur = 1;
    int ans = 0;
    while (cur < N) {
        if (cur <= K)
            cur *= 2;
        else {
            ans+=(N-cur+K-1)/K;
            break;
        }
        ans++;
    }
    cout<<ans<<endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}