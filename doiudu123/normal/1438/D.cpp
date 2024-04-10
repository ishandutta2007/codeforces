#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

struct op {
    int a, b, c;
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, xorr = 0;
    cin >> n;
    vector <int> a(n);
    fop (i,0,n) cin >> a[i], xorr ^= a[i];
    vector <op> ans;
    if (n & 1) {
        for (int i = 1; i < n; i += 2) {
            ans.pb({i - 1, i, i + 1});
            int x = a[i - 1] ^ a[i] ^ a[i + 1];
            a[i - 1] = a[i] = a[i + 1] = x;
        }
        for (int i = n - 2; i >= 0; i -= 2) {
            ans.pb({n - 1, i, i - 1});
            int x = a[n - 1] ^a[i] ^a[i - 1];
            a[n - 1] = a[i] = a[i - 1] = x;
        }
    } else {
        if (xorr) return cout << "NO\n", 0;
        for (int i = n - 4; i >= 2; i -= 2) {
            ans.pb({i, i + 1, i + 2});
            int x = a[i] ^ a[i + 1] ^ a[i + 2];
            a[i] = a[i + 1] = a[i + 2] = x;
            ans.pb({i + 3, i + 1, i + 2});
            x = a[i + 3] ^ a[i + 1] ^ a[i + 2];
            a[i + 3] = a[i + 1] = a[i + 2] = x;
        }
        ans.pb({0, 1, 2});
        int x = a[0] ^ a[1] ^ a[2];
        a[0] = a[1] = a[2] = x;
    }
    cout << "YES\n";
    cout << ans.size() << endl;
    for (auto A : ans) cout << A.a + 1 << ' ' << A.b + 1 << ' ' << A.c + 1 << endl;
}