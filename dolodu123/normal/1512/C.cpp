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
const int mod = 1e9 + 7, abc = 864197532, N = 300001, K = 111;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = a + b;
        bool fail = false;
        for (int i = 0; i < n - i - 1; ++i) {
            int j = n - i - 1;
            if (s[i] == '?' && s[j] == '?') continue;
            if (s[i] == '?') {
                s[i] = s[j];
            } else if (s[j] == '?') {
                s[j] = s[i];
            } else if (s[i] != s[j]) {
                fail = true;
            }
            if (s[j] == '1') b -= 2;
            else a -= 2;
        }
        for (int i = 0; i < n - i - 1; ++i) if (s[i] == '?') {
            int j = n - i - 1;
            if (a >= 2) s[i] = s[j] = '0', a -= 2;
            else if (b >= 2) s[i] = s[j] = '1', b -= 2;
            else fail = true;
        }
        if (n & 1) {
            int i = n >> 1;
            if (s[i] == '?') {
                if (a >= 1) s[i] = '0';
                else if (b >= 1) s[i] = '1';
                else fail = true;
            } else {
                if (s[i] == '0') a--;
                else b--;
            }
        }
        if (a < 0 || b < 0) fail = true;
        if (fail) cout << -1 << endl;
        else cout << s << endl;
    }
}