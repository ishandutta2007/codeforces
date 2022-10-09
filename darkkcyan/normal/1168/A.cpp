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
// mt19937 rand(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64

#define maxn 301010
int n, m;
int a[maxn];
bool ok(int n_op) {
    int last = 0;
    rep(i, n) {
        int step = (last - a[i] + m) % m;
        if (last > a[i]) {
            if (step > n_op) return false;
        }
        if (step > n_op) last = a[i];
    }
    return true;
}
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    rep(i, n) cin >> a[i];
    int l = 0, r = m;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}