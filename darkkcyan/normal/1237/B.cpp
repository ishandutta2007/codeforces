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

const int maxn = 101010;
int n;
bool fined[maxn] = {0};
int a[maxn];
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, n) cin >> a[i];
    int u = 0;
    int ans = 0;
    rep(i, n) {
        int b; cin >> b;
        while (u < n and fined[a[u]]) ++u;
        // clog << b << ' ' << a[u] <<endl;
        if (u < n and a[u] != b) {
            fined[b] = 1;
            ++ans;
        } else {
            ++u;
        }
    }
    cout << ans;

    return 0;
}