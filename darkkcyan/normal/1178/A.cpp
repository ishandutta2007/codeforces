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
    int n; cin >>n;
    vector<llong> a(n);
    for (auto& i: a) cin >> i;
    llong s = a[0], sa = a[0];
    vector<int> ans(1, 0);
    rep1(i, n - 1) {
        s += a[i];
        if (a[i] * 2 <= a[0]) {
            sa += a[i];
            ans.push_back(i);
        }
    }

    if (s / 2 >= sa) cout << 0;
    else {
        cout << len(ans) << '\n';
        for (auto i: ans) cout << i + 1 << ' ';
    }

    return 0;
}