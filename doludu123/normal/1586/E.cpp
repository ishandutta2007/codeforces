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
const int mod = 998244353, N = 300001, logN = 20, K = 15;

int dsu[N];

int Find(int x) {
    if (dsu[x] == x)
        return x;
    return dsu[x] = Find(dsu[x]);
}

vector <int> adj[N];
map <pii, int> m1;

void add(int u, int v, int val) {
    if (u > v) 
        swap(u, v);
    m1[{u, v}] += val;
}

vector <int> ord;

bool dfs(int v, int pa, int t) {
    ord.pb(v + 1);
    if (v == t)
        return true;
    for (int u : adj[v]) if (u != pa) {
        add(u, v, 1);
        if (dfs(u, v, t))
            return true;
        add(u, v, -1);
    }
    ord.pop_back();
    return false;
}

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    iota(dsu, dsu + n, 0);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        if (Find(u) == Find(v))
            continue;
        adj[u].pb(v), adj[v].pb(u);
        dsu[Find(u)] = Find(v);
    }
    vector <vector <int>> ans;
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v, --u, --v;
        dfs(u, -1, v);
        ans.pb(ord);
        ord.clear();
    }
    bool is = true;
    vector <int> cnt(n, 0);
    for (auto A : m1) {
        if (A.Y % 2)
            is = false, cnt[A.X.X] ^= 1, cnt[A.X.Y] ^= 1;
    }
    if (is) {
        cout << "YES\n";
        for (auto A : ans) {
            cout << A.size() << endl;
            printv(all(A));
        }
    } else {
        cout << "NO\n";
        cout << accumulate(all(cnt), 0) / 2 << endl;
    }
}