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
const int mod = 1e9 + 7, x = 864197532, N = 1004, logN = 18, K = 500, C = 100;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        lli n;
        cin >> n;
        vector <pii> f;
        lli tmp = n;
        for (lli i = 2; i * i <= n; ++i) if (n % i == 0) {
            f.eb(i, 0);
            while (n % i == 0) n /= i, f.back().Y++;
        }
        if (n > 1) f.eb(n, 1);
        sort(all(f), [](pii a, pii b) {
            return a.Y > b.Y;
        });
        cout << f[0].Y << endl;
        fop (i,0,f[0].Y - 1) cout << f[0].X << ' ', tmp /= f[0].X;
        cout << tmp << endl;
    }
}