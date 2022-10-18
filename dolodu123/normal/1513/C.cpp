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
const int mod = 1e9 + 7, abc = 864197532, N = 200087, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector <lli> a = {1};
    vector <int> cnt(10, 0);
    cnt[0] = 1;
    while (a.size() <= N) {
        vector <int> ncnt(10, 0);
        for (int i = 0; i < 9; ++i) {
            ncnt[i + 1] = cnt[i];
        }
        (ncnt[0] += cnt[9]) %= mod;
        (ncnt[1] += cnt[9]) %= mod;
        a.pb(accumulate(all(ncnt), 0ll) % mod);
        swap(cnt, ncnt);
    }
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n;
        cin >> s >> n;
        lli ans = 0;
        for (char c : s) {
            (ans += a[n + c - '0']) %= mod;
        }
        cout << ans << endl;
    }
}