#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;

const int MAXN = 500001;

vector <int> e[MAXN];

using arr = array<ll, 3>;


using Value = array<array<ll, 2>, 3>;
using a3 = array<ll, 3>;

Value d[MAXN];
int sz[MAXN];

vector<Value> vals;

Value def() {
    Value res;
    for (auto& v : res) {
        v.fill(0);
    }

    return res;
}

Value mrg(const Value& l, const Value& r) {
    Value res = def();
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i + j >= 3) {
                continue;
            }
            auto& v = res[i + j];
            v[0] += l[i][0] * r[j][0];
            v[1] += l[i][1] * r[j][0] + l[i][0] * r[j][1];
        }
    }

    return res;
}

void up(Value& val) {
    Value res = def();
    for (int i = 0; i < 3; ++i) {
        res[i][0] += val[i][1];
        if (i < 2) {
            res[i + 1][0] += val[i][0];
        }

        res[i][1] += val[i][0];
    }

    val = res;
}


void dfs(int v, int p) {
    auto it = find(e[v].begin(), e[v].end(), p);
    if (it != e[v].end()) {
        e[v].erase(it);
    }

    d[v] = def();
    d[v][0][0] = 1;
    sz[v] = 1;

    for (int u : e[v]) {
        dfs(u, v);
        sz[v] += sz[u];
        d[v] = mrg(d[v], d[u]);
    }

    up(d[v]);
}

ll ans = 0;
ll any;

int n;

void dfs2(int v, Value upval) {
    if (v != 1) {
        if (d[v][0][0] && upval[0][0]) {
            ans += ll{ sz[v] } *ll{ n - sz[v] };
        } else {
            ans += d[v][1][0] * upval[1][0];
        }   
    }

    int es = e[v].size();
    vector<Value> lvals(es + 1);
    vector<Value> rvals(es + 1);
    lvals[0] = upval;
    rvals[es] = def();

    rvals[es][0][0] = 1;

    for (int i = 0; i < es; ++i) {
        lvals[i + 1] = mrg(lvals[i], d[e[v][i]]);
    }

    for (int i = es - 1; i >= 0; --i) {
        rvals[i] = mrg(rvals[i + 1], d[e[v][i]]);
    }

    for (int i = 0; i < es; ++i) {
        Value cur = mrg(lvals[i], rvals[i + 1]);
        up(cur);
        dfs2(e[v][i], cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    if (n & 1) {
        cout << 0 << "\n";
        return 0;
    }

    any = ll(n) * ll(n - 1) / 2 - ll(n - 2);

    dfs(1, 1);

    Value dc = def();
    dc[0][0] = 1;
    dfs2(1, dc);

    cout << ans << "\n";
}