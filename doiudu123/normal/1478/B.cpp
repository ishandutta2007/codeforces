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
const int mod = 998244353, abc = 864197532, N = 500087, logN = 20, K = 333;

void solve() {
    int q, d, x;
    cin >> q >> d;
    vector <bool> is(100, false);
    is[0] = true;
    for (int i = 1; i < 100; ++i) {
        if (i / 10 == d || i % 10 == d) is[i] = true;
        for (int j = 0; j < i; ++j) {
            if (is[j] && is[i - j]) {
                is[i] = true;
            }
        }
    }
    while (q--) {
        cin >> x;
        bool ans = false;
        if (x < 100) {
            ans = is[x];
        } else {
            ans = true;
        }
        cout << (ans ? "YES\n" : "NO\n");
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