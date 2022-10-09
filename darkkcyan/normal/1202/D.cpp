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

llong closest(llong n) {
    return (llong)floor((1 + sqrt(1 + 8 * n)) / 2);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        llong n; cin >> n;
        map<llong, int> cnt7;
        while (n > 50) {
            llong x = closest(n);
            cnt7[x] ++;
            n -= x * (x - 1) / 2;
        }
        cnt7[2ll] += (int)n;
        cout << '1';
        int cnt3 = 0;
        for (auto i: cnt7) {
            for (; cnt3 < i.xx; ++cnt3) cout << '3';
            cout << string(i.yy, '7');
        }
        cout << '\n';
    }

    return 0;
}