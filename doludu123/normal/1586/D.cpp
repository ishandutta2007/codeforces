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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1000001, logN = 20, K = 15;

int ask(vector <int> a) {
    cout << "? ";
    for (int i : a)
        cout << i << ' ';
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> ans(n);
    for (int i = 2; i <= n; ++i) {
        vector <int> a(n, 1);
        a[n - 1] = i;
        if (!ask(a)) {
            // x + i = n + 2
            // x = n + 2 - i
            ans[n - 1] = n + 2 - i;
            break;
        }
    }
    if (!ans[n - 1])
        ans[n - 1] = 1;
    for (int i = 1; i < ans[n - 1]; ++i) {
        vector <int> a(n, ans[n - 1] - i + 1);
        a[n - 1] = 1;
        int x = ask(a) - 1;
        ans[x] = i;
    }
    for (int i = ans[n - 1] + 1; i <= n; ++i) {
        vector <int> a(n, 1);
        a[n - 1] = i + 1 - ans[n - 1];
        int x = ask(a) - 1;
        ans[x] = i;
    }
    cout << "! ";
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}