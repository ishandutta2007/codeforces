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
    int ntest; cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        rep(i, n) {
            int u; cin >> u;
            a[i] = u - a[i];
        }
        int l = 0, r = n;
        while (l < n and a[l] == 0) ++l;
        while (r > 0 and a[r - 1] == 0) --r;
        if (l >= r) {
            cout << "YES\n";
            continue;
        }

        bool ok = true;
        for (int i = l; i < r; ++i) 
            if (a[i] <= 0 or (i != r - 1 and a[i] != a[i + 1])) {
                ok = false;
                break;
            }
        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}