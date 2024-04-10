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
const int mod = 998244353, N = 1000005, logN = 20, K = 111, M = 4e7, C = 350;

int cc = 0;

int W[N] = {2000, 1997, 2000}, n;

int query(int w) {
    cout << "? " << w << endl;
    cc++;
    #ifdef Doludu
    int now = 0, ans = 1;
    for (int i = 0; i < n; ++i) {
        if (W[i] > w)
            return 0;
    }
    now = W[0];
    for (int i = 1; i < n; ++i) {
        if (now + 1 + W[i] <= w)
            now += 1 + W[i];
        else
            ans++, now = W[i];
    }
    return ans;
    #else
    cin >> w;
    return w;
    #endif
}

int main () {
    cin >> n;
    int l = 0, r = 1e9;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (query(m) == 1)
            r = m;
        else
            l = m;
    }
    int sum = r - (n - 1);
    int ans = r;
    for (int i = 2; i <= n; ++i) {
        int tot = sum + n - i;
        int x = (tot + i - 1) / i;
        int y = query(x);
        if (y)
            ans = min(ans, y * x);
    }
    cout << "! " << ans << '\n';
    test(cc);
}