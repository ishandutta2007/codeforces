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

#define maxn 2222
int n;
int a[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];

    set<int> has;
    int ans = n;
    rep(l, n) {
        int r = n;
        while (r--) {
            if (has.count(a[r])) break;
            has.insert(a[r]);
        }
        // clog << l << ' ' << r << endl;
        ans = min(ans, r - l + 1);
        for (; ++r < n; ) has.erase(a[r]);
        if (has.count(a[l])) break;
        has.insert(a[l]);
    }
    cout << ans;

    return 0;
}