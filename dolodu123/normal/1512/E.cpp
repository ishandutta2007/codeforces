#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 10000001, K = 111;

void solve() {
    int n, l, r, s;
    cin >> n >> l >> r >> s, --l;
    int m = r - l;
    vector <int> a(m);
    iota(all(a), 1);
    s -= m * (m + 1) / 2;
    if (s < 0) {
        cout << -1 << endl;
        return;
    }
    int now = m - 1;
    while (s > 0) {
        a[now]++;
        s--;
        now--;
        if (now == -1) now += m;
    }
    if (a.back() > n) {
        cout << -1 << endl;
        return;
    }
    vector <bool> vis(n, false);
    for (int i = 0; i < m; ++i) vis[a[i]] = true;
    now = 1;
    for (int i = 0; i < n; ++i) {
        while (vis[now]) now++;
        if (l <= i && i < r) cout << a[i - l] << ' ';
        else cout << now++ << ' ';
    }
    cout << endl;
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