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

#define maxn 201010
#define maxlg 18
struct SUM_BIT {
    llong data[maxn];
    void upd(int i, llong val) {
        for(++i; i < maxn; i += i & -i) data[i] += val;
    }

    int lower_bound(llong s) {
        int ans = 0; 
        llong cur = 0;
        for (int i = 1 << maxlg >> 1; i > 0; i >>= 1) {
            if (ans + i >= maxn) continue;
            if (cur + data[ans + i] > s) continue;
            ans += i;
            cur += data[ans];
        }
        return ans;
    }
};

int n;
llong p[maxn];
int ans[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, n) cin >> p[i];

    SUM_BIT bit;
    rep1(i, n) bit.upd(i, i);
    for (int i = n; i--; ) {
        ans[i] = bit.lower_bound(p[i]);
        bit.upd(ans[i], -ans[i]);
    }

    rep(i, n) cout << ans[i] << ' ';

    return 0;
}