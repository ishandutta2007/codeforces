#include <iostream>
#include "vector"
#include "algorithm"
#include "numeric"
#include "climits"
#include "iomanip"
#include "bitset"
#include "cmath"
#include "map"
#include "deque"
#include "array"
#include "set"
#define all(x) x.begin(), x.end()
using namespace std;
#define int long long
struct dsu{
    vector<int> p, sz;
    void make(int n) {
        p.assign(n, 0);
        sz.assign(n, 1);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
    }
    int getv(int v) {
        if (p[v] == v)
            return v;
        return p[v] = getv(p[v]);
    }
    void mrg(int a, int b) {
        a = getv(a);
        b = getv(b);
        if (a != b) {
            p[a] = b;
            sz[b] += sz[a];
        }
    }
};
void solve() {
    int n;
    cin >> n;vector<int> a(n), b(n);
    dsu ds;
    ds.make(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        ds.mrg(a[i]-1, b[i]-1);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (ds.p[i] == i and ds.sz[i] % 2)
            cnt++;
    }
    int nd = (n - cnt) / 2;
    int res = 0;
    for (int i = 0; i < nd; ++i) {
        res += (n - i * 2 - 1) * 2;
        //cerr << (n - i * 2 - 1) * 2 << endl;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}