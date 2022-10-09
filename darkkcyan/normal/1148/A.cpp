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

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    llong a, b, c; cin >> a >> b >> c;
    auto t = [](llong u, llong v) { 
        llong ans = min(u, v);
        u -= ans, v -= ans;
        ans *= 2;
        if (u) ++ans;
        return ans;
    };
    cout << max(t(b, a), t(a, b)) + c * 2;

    return 0;
}