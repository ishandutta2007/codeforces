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
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--) {
        int n, r; cin >> n >> r;
        vector<int> a(n);
        for (auto& i: a) cin >> i;
        sort(a.begin(), a.end());
        n = (int)(unique(a.begin(), a.end()) - a.begin());
        int ans = 0;
        for (int i = n; i--; ) {
            int cur = a[i] - ans * r;
            if (cur <= 0) break;
            ++ans;
        }
        cout << ans << '\n';
    }


    return 0;
}