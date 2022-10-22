#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct fenwick {
    static const int dim = 1 << 18;
    vector<int> tree = vector<int>(dim, 0);
    void add(int x) {
        for (; x < dim; x += x & -x) tree[x]++;
    }
    void set(int x) {
        for (; x < dim; x += x & -x) tree[x] = 0;
    }
    int sum(int x) {
        int res = 0;
        for (; x; x -= x & -x) res += tree[x];
        return res;
    }
} fen;
void solve() {
    int N;
    cin >> N;
    int tot = 0;
    for (int i = 1; i < N + 5; i++) fen.set(i);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        tot += i - fen.sum(a - 1);
        fen.add(a);
    }
    cout << tot << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
}