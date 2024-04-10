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
        int n; string s;
        cin >> n >> s;
        string color(n, ' ');
        bool ok = 1;
        for (char mid = '0'; mid <= '9'; ++mid) {
            char last_a = '0', last_b = '0';
            ok = 1;
            rep(i, n) {
                if (s[i] > mid) {
                    if (last_b > s[i]) {
                        ok = 0;
                        break;
                    }
                    color[i] = '2';
                    last_b = s[i];
                } else if (s[i] < mid) {
                    if (last_a > s[i]) {
                        ok = 0;
                        break;
                    }
                    color[i] = '1';
                    last_a = s[i];
                } else {
                    if (last_b <= mid) {
                        last_b = s[i];
                        color[i] = '2';
                    } else if (last_a <= mid) {
                        last_a = s[i];
                        color[i] = '1';
                    } else {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) break;
        }
        if (!ok) cout << "-\n";
        else cout << color << '\n';
    }

    return 0;
}