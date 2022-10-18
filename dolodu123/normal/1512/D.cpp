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
    int n;
    cin >> n;
    vector <lli> a(n + 2), pre = {0};
    for (int i = 0; i < n + 2; ++i) cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n + 2; ++i) pre.pb(pre.back() + a[i]);
    for (int i = 0; i <= n; ++i) {
        if (pre[n + 1] - a[i] == a[n + 1]) {
            for (int j = 0; j <= n; ++j) if (j ^ i) {
                cout << a[j] << ' ';
            }
            cout << endl;
            return;
        }
    }
    if (pre[n] == a[n]) {
        for (int j = 0; j < n; ++j) cout << a[j] << ' ';
        cout << endl;
        return;
    }
    cout << -1 << endl;
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