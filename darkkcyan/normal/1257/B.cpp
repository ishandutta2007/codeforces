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
        llong x, y; cin >> x >> y;
        if (x == y) {
            cout << "YES\n";
            continue;
        }
        if (x == 1) {
            cout << "NO\n";
            continue;
        }
        if (x <= 3 and y > 3) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }

    return 0;
}