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

const llong mod = (llong)1e9 + 7;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        int x; cin >> x;
        string s; cin >> s;
        deque<int> right;
        for (auto c: s) right.push_back(c - '0');

        llong ans = len(right);

        llong cur_right_length = len(right);
        
        while (x--) {
            int cur = right[0];
            right.pop_front();
            --cur_right_length;
            // clog << cur << ' ' << cur_right_length << ' ' << ans << endl;
            ans += (cur - 1) * cur_right_length;
            if (ans >= mod) ans %= mod;
            cur_right_length *= cur;
            if (cur_right_length >= mod) cur_right_length %= mod;

            int len_arr = len(right);
            rep(i, cur - 1) {
                rep(f, len_arr) {
                    if (len(right) >= x + 10) {
                        break;
                    }
                    right.push_back(right[f]);
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}