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

struct BIT_Pre {
    int n;
    vector <int> bit;
    BIT_Pre (int _n) : n(_n) {
        bit.assign(n, -1 << 30);
    }
    void add (int p, int a) {
        for (int i = p + 3; i < n; i += (i & -i)) bit[i] = max(bit[i], a);
    }
    int query (int p) {
        int mx = -1 << 30;
        for (int i = p + 3; i > 0; i -= (i & -i)) mx = max(mx, bit[i]);
        return mx;
    }
};

struct BIT_Suf {
    int n;
    vector <int> bit;
    BIT_Suf (int _n) : n(_n) {
        bit.assign(n, -1 << 30);
    }
    void add (int p, int a) {
        for (int i = p + 3; i > 0; i -= (i & -i)) bit[i] = max(bit[i], a);
    }
    int query (int p) {
        int mx = -1 << 30;
        for (int i = p + 3; i < n; i += (i & -i)) mx = max(mx, bit[i]);
        return mx;
    }
};

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <lli> a = {0};
        for (int i = 0, x; i < n; ++i)
            cin >> x, a.pb(a.back() + x);
        vector <int> dp(n + 1, -1 << 30);
        dp[0] = 0;
        BIT_Pre bit1(n + 5); BIT_Suf bit2(n + 5);
        vector <lli> v = a;
        sort(all(v)), v.resize(unique(all(v)) - v.begin());
        map <int, int> same;
        int p = lower_bound(all(v), 0) - v.begin();
        bit1.add(p, 0), bit2.add(p, 0), same[p] = 0;
        for (int i = 1; i <= n; ++i) {
            int p = lower_bound(all(v), a[i]) - v.begin();
            // pre[j] < pre[i]
            dp[i] = max(dp[i], bit1.query(p - 1) + i);
            // pre[j] = pre[i]
            if (same.count(p))
                dp[i] = max(dp[i], same[p]);
            // pre[j] > pre[i]
            dp[i] = max(dp[i], bit2.query(p + 1) - i);
            bit1.add(p, dp[i] - i);
            bit2.add(p, dp[i] + i);
            if (same.count(p))
                same[p] = max(same[p], dp[i]);
            else
                same[p] = dp[i];
        }
        cout << dp[n] << '\n';
    }
}