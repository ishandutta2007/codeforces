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
const int mod = 998244353, x = 864197532, N = 1004, logN = 18, K = 500, C = 100;

void solve() {
    int n, q, l, r;
    string s;
    cin >> n >> q >> s;
    while (q--) {
        cin >> l >> r, r--, l--;
        int ll = l - 1, rr = r + 1;
        while (ll >= 0 && s[ll] != s[l]) ll--;
        while (rr < n && s[rr] != s[r]) rr++;
        if (ll == -1 && rr == n) cout << "NO\n";
        else cout << "YES\n";
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}