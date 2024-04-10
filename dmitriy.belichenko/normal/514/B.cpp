#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
mt19937 rng(239);
bool used[1005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    vector<pair<long long, long long>> pts(n);
    int ans = 0;
    for (auto &x : pts) cin >> x.first >> x.second;
    for (int i = 0; i < n; i++) {
        auto prv = pts[i];
        if (!used[i]) {
            ans ++;
            used[i] = true;
            for (int j = i + 1; j < n; j++) {
                auto cur = pts[j];
                long long left = (prv.first - x0) * (cur.second - y0);
                long long right = (cur.first - x0) * (prv.second - y0);
                used[j] |= (left == right);
            }
        }
    }
    cout << ans << "\n";
}