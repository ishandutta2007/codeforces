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
const int mod = 1e9 + 7, abc = 864197532, Doludu = 123, N = 601, logN = 18;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        int xorr = 0;
        for (int i = 0; i < n; ++i) cin >> a[i], xorr ^= a[i];
        if (xorr == 0) cout << "YES\n";
        else {
            int cur = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                cur ^= a[i];
                if (cur == xorr) cnt++, cur = 0;
            }
            if (cnt >= 3) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}