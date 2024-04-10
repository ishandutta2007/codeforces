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
        int n; cin >> n;
        vector<llong> a(n);
        for (auto& i: a) cin >> i;
        bool ok = false;
        rep(i, n - 1) {
            if (abs(a[i + 1] - a[i]) > 1) {
                cout << "YES\n";
                cout << i + 1 << ' ' << i + 2 << '\n';
                ok = true;
                break;
            }
        }
        if (!ok) cout << "NO\n";
    }

    return 0;
}