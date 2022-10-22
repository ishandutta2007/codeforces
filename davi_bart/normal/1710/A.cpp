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
    int N, M, K;
    cin >> N >> M >> K;
    int a = 0, b = 0;
    bool aa = 0, bb = 0;
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        if (x / N > 1) a += x / N;
        if (x / N > 2) aa = 1;
        if (x / M > 1) b += x / M;
        if (x / M > 2) bb = 1;
    }
    if (a % 2 != M % 2 && !aa) a = 0;
    if (b % 2 != N % 2 && !bb) b = 0;
    if (a >= M || b >= N)
        cout << "Yes\n";
    else
        cout << "No\n";
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}