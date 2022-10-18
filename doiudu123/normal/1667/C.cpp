#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 5e5 + 7, logN = 20, K = 111, M = 4e7;

vv <bool> upd(vv <bool> vis, int i, int j, int n) {
    for (int k = 0; k < n; ++k)
        vis[i][k] = vis[k][j] = true;
    for (int d = -n; d <= n; ++d) {
        int ni = i + d, nj = j + d;
        if (0 <= ni && ni < n && 0 <= nj && nj < n)
            vis[ni][nj] = true;
    }
    return vis;
}

vector <pii> mov;

int bf(vv <bool> vis, int n, int k) {
    if (mov.size() > k)
        return 11;
    int mn = 1 << 30, cnt = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (!vis[i][j])
        cnt = 1;
    if (!cnt) {
        return 0;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (!vis[i][j]) {
        vv <bool> nxt = upd(vis, i, j, n);
        mov.eb(i, j);
        mn = min(bf(nxt, n, k) + 1, mn);
        mov.pop_back();
    }
    return mn;
}

/*
*XXXXXXXX
XX**XXXXX
X*XXXXXXX
X*XXXXXOO
XXXXXXXXO
XXXXXXXXX
XXXXXXXXX
XXXXOXXXX
XXXXOOXXX

*XXXXXXX
XX**XXXX
X*XXXXXX
X*XXXXXX
XXXX*XXO
XXXXXXXX
XXXXXXXX
XXXXOXXX

*XXXXXXX
XX*XXXXX
XXXX*XXX
X*XXXXXX
XXX*XXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
*/

int main () {
    owo;
    int n;
    cin >> n;
    
    int cnt = 0;
    for (int i = 1; ; ++i) {
        if (i >= 2 * (n - i) - 1) {
            cnt = i;
            break;
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < (cnt + 1) / 2; ++i)
        cout << i + 1 << ' ' << 2 * i + 1 << '\n';
    for (int i = 1; i < cnt / 2 + 1; ++i)
        cout << n - cnt + i << ' ' << 2 * i << '\n';
}