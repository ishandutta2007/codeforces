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
#define m_tup make_tuple
#define em_bac emplace_back
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

#define maxn 101010
int n;
llong disk_size;
llong bit_per_int;
map<llong, int> a;

int n_bit(int x) {
    return x == 0 ? 0 : 1 + n_bit(x / 2);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> disk_size;
    disk_size *= 8;
    bit_per_int = disk_size / n;

    rep(i, n) {
        int intensity; cin >> intensity;
        a[intensity]++;
    }

    llong max_window = bit_per_int > 30 ? LLONG_MAX : 1ll << bit_per_int;
    auto left = a.begin(), right = a.begin();
    llong s = 0;
    for (int i = 0; i < max_window - 1 and right != a.end(); ++i, ++right)
        s += right->second;

    llong ans = n - s;
    for (; right != a.end(); ++right, ++left) {
        s += right->second;
        ans = min(ans, n - s);
        s -= left->second;
    }

    cout << ans;


    return 0;
}