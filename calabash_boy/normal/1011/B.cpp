#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B> inline ostream& operator << (ostream&os, const pair<A, B> &v) {
    return os << v.first << ' ' << v.second;
}
template <typename T> inline ostream& operator << (ostream&os, const vector<T> &v) {
    for (auto it = v.begin(); it != v.end(); os << (*it++)) if (it != v.cbegin()) os << ' ';
    return os;
}
#ifdef Wavator
#define debug(...) cerr << #__VA_ARGS__ << "[", _debug(__VA_ARGS__)
#else
#define debug(...) 98

#endif
void _debug(){}
template <typename H, typename...T>
void _debug(H head, T...tail) {
    cerr << head; sizeof...(tail)? cerr << ' ': cerr << "]" << flush;
    _debug(tail...);
}
#define rep(i, a, b) for (int (i) = (a); (i) < (b); ++(i))
#define per(i, a, b) for (int (i) = (b) - 1; (i) >= (a); --(i))
#define REP(i, a, b) for (int (i) = (a); (i) <= (b); ++(i))
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int oo = 0x3f3f3f3f;
const ll mod = (ll)1e9 + 7;
void Main();
int main() {
#ifdef Wavator
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Main();
    return 0;
}


void Main() {
    int n, m;
    cin >> n >> m;
    vector<int> cnt(1000, 0);
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        cnt[x]++;
    }
    int ans;
    for (ans = m / n; ans >= 1; --ans) {
        int temp = 0;
        for (int i = 1; i <= 100; i++) {
            temp += cnt[i] / ans;
        }
        if (temp >= n)
            break;
    }
    cout << ans << endl;
}