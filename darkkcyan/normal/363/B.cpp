#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<llong> a(n);
    for (auto& i: a) cin >> i;

    int l = 0, r = 0;
    llong s = 0;
    pair<llong, int> ans = {LLONG_MAX, -1};
    for (; l <= n - k; ++l) {
        while (r <= n and r - l < k) s += a[r++];
        if (r - l < k) break;
        ans = min(ans, {s, l});
        s -= a[l];
    }
    cout << ans.yy + 1;

    return 0;
}