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

map <string, int> m1;

bool ok(string s) {
    for (int i = 1; i < s.length(); ++i) if (s[i] == s[i - 1])
        return false;
    return true;
}

int solve(string s) {
    if (s == "")
        return 0;
    if (m1.count(s))
        return m1[s];
    int n = s.length();
    int mn = 1 << 30;
    for (int i = 0; i < n; ++i) for (int len = 1; i + len <= n; ++len) {
        if (ok(s.substr(i, len))) {
            string t = s.substr(0, i) + s.substr(i + len);
            mn = min(mn, solve(t) + 1);
        }
    }
    return m1[s] = mn;
}

int solve2(string s) {
    int f[2] = {0, 0};
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1])
            f[s[i - 1] - '0']++;
    }
    return max(f[0], f[1]) + 1;
}

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector <int> pre0(n, 0), pre1(n, 0);
    for (int i = 1; i < n; ++i)
        pre0[i] = pre0[i - 1] + (s[i] == '0' && s[i - 1] == '0');
    for (int i = 1; i < n; ++i)
        pre1[i] = pre1[i - 1] + (s[i] == '1' && s[i - 1] == '1');
    while (q--) {
        int l, r;
        cin >> l >> r, --l, --r;
        cout << max(pre1[r] - pre1[l], pre0[r] - pre0[l]) + 1 << '\n';
    }
}