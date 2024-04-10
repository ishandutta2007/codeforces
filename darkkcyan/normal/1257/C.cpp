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
int n;
int pos[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    while (ntest--) {
        cin >> n;
        rep(i, n + 1) pos[i] = -1;
        int ans = INT_MAX;
        rep(i, n) {
            int u; cin >> u;
            int cur = -1;
            if (pos[u] != -1) {
                cur = i - pos[u] + 1;
                if (cur != 1) ans = min(ans, cur);
            }
            if (pos[u] == -1 or cur != 1) pos[u] = i;
        }
        if (ans == INT_MAX) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}