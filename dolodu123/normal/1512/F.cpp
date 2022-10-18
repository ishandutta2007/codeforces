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
    int n, c;
    cin >> n >> c;
    vector <lli> a(n), b(n - 1);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) cin >> b[i];
    lli now = 0, day = 0, ans = 1ll << 60;
    for (int i = 0; i < n; ++i) {
        if (now >= c) ans = min(ans, day);
        else ans = min(ans, day + (c - now + a[i] - 1) / a[i]);
        if (i < n - 1) {
            int addday = (b[i] - now + a[i] - 1) / a[i];
            day += addday + 1;
            now += addday * a[i];
            now -= b[i];
        }
    }
    cout << ans << endl;
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