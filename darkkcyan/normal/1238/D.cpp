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

#define maxn 301010
int n;
string a;
int s[maxn];
int nxt[maxn][2];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a;
    rep(i, n) s[i] = a[i] - 'A';
    nxt[n][0] = nxt[n][1] = n;
    for (int i = n; i--; ) {
        memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
        if (i != n -1) 
            nxt[i][s[i + 1]] = i + 1;
    }

    llong ans = 0;
    rep(i, n) {
        int f = nxt[i][!s[i]];
        llong u = f - i - 1;
        llong v = n - max(min(f + 1, n), nxt[i][s[i]]);
        // clog << i << ' ' << f << ' ' <<  u << ' ' << v << endl;
        ans += u + v;
    }
    cout << ans;

    return 0;
}