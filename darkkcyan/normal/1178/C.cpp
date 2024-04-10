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

const llong rem = 998244353;
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    llong w, h; cin >> w >> h;
    llong ans = 4;
    rep(i, w - 1 + h - 1) (ans *= 2) %= rem;
    cout << ans;

    return 0;
}