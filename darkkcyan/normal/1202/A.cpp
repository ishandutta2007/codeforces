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
    rep1(testcase, ntest) {
        string x, y;
        cin >> ws >> x >> ws >> y;
        set<int> p1x;
        for (int i = len(x), f = 0; i--; ++f) {
            if (x[i] == '1') p1x.insert(f);
        }

        int pf1y = 0;
        for (int i = len(y); i--; ++pf1y) {
            if (y[i] == '1') break;
        }

        // clog << testcase << ' ' << pf1y << endl;

        auto t = p1x.lower_bound(pf1y);
        assert(t != p1x.end());
        cout << *t - pf1y << '\n';
    }

    return 0;
}