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
    int n, k;
    string s, t;
    cin >> n >> k >> s >> t;
    vector <int> a(26, 0), b(26, 0);
    fop (i,0,n) a[s[i]-  'a']++, b[t[i] - 'a']++;
    vector <int> c(26, 0), d(26, 0);
    fop (i,0,26) {
        while (a[i] >= k) c[i]++, a[i] -= k;
        while (b[i] >= k) d[i]++, b[i] -= k;
    }
    fop (i,0,26) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    FOP (i,25,0) c[i] += c[i + 1], d[i] += d[i + 1];
    fop (i,0,26) {
        if (c[i] > d[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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