#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e6 + 7;

namespace bit {
    int bit[N];
    void add(int pos, int val) {
        assert(pos);
        for(; pos < N; pos += pos & -pos)
            bit[pos] += val;
    }
    int qry(int pos) {
        int res = 0;
        for(; pos; pos -= pos & -pos)
            res += bit[pos];
        return res;
    }
    int bs(int l, int k) {
        k += qry(l - 1);
        int pos = 0, sum = 0;
        for(int i = 19; i >= 0; i--)
            if(pos + (1 << i) < N && sum + bit[pos + (1 << i)] < k) {
                pos += 1 << i;
                sum += bit[pos];
            }
        return ++pos;
    }
}

int a[N];
vi G[N];
V<array<int, 3>> qq[N];
int ans[N], cnt[N];
unordered_set<int> who[N];

void add(int x) {
    if(cnt[x]) {
        bit::add(cnt[x], -1);
        who[cnt[x]].erase(x);
    }
    cnt[x]++;
    bit::add(cnt[x], 1);
    who[cnt[x]].insert(x);
}
void del(int x) {
    bit::add(cnt[x], -1);
    who[cnt[x]].erase(x);
    cnt[x]--;
    if(cnt[x]) {
        bit::add(cnt[x], 1);
        who[cnt[x]].insert(x);
    }
}
int qry(int l, int k) {
    if(bit::qry(N - 1) - bit::qry(l - 1) < k)
        return -1;
    int pos = bit::bs(l, k);
    assert(bit::qry(pos) - bit::qry(l - 1) >= k);
    assert(who[pos].size());
    return *who[pos].begin();
}

void dfs(int u) {
    add(a[u]);
    for(auto [l, k, i] : qq[u]) {
        ans[i] = qry(l, k);
    }
    for(int v:G[u])
        dfs(v);
    del(a[u]);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        G[p].PB(i);
    }
    for(int i = 0; i < q; i++) {
        int v, l, k;
        cin >> v >> l >> k;
        qq[v].PB({l, k, i});
    }
    dfs(1);
    for(int i = 0; i < q; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        qq[i].clear();
    }
}

signed main()
{
    IO_OP;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

}