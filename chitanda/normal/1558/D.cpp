#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 998244353;

const int maxn = 200005, maxm = maxn << 1;
int T;
int n, m;
int x[maxn], y[maxn];

int w[maxn];

int tot;
int sum[maxn << 2];
int ls[maxn << 2], rs[maxn << 2];

ll fac[maxm], inv[maxm], sinv[maxm];

int new_node(int len) {
    ++tot;
    ls[tot] = rs[tot] = 0;
    sum[tot] = len;
    return tot;
}

int insert(int t, int l, int r, int v) {
    --sum[t];
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    if (v <= (ls[t] ? sum[ls[t]] : mid - l + 1)) {
        if (!ls[t]) ls[t] = new_node(mid - l + 1);
        return insert(ls[t], l, mid, v);
    } else {
        if (!rs[t]) rs[t] = new_node(r - mid);
        v -= ls[t] ? sum[ls[t]] : mid - l + 1;
        return insert(rs[t], mid + 1, r, v);
    }
}

int C(int n, int m) { return fac[n + m] * sinv[n] % M * sinv[m] % M; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fac[0] = fac[1] = inv[0] = inv[1] = sinv[0] = sinv[1] = 1;
    for (int i = 2; i <= 400000; ++i) {
        fac[i] = fac[i - 1] * i % M;
        inv[i] = (M - M / i) * inv[M % i] % M;
        sinv[i] = sinv[i - 1] * inv[i] % M;
    }

    cin >> T;
    while (T--) {
        cin >> n >> m;

        tot = 0;
        new_node(n);
        for (int i = 0, j = 0; i < m; ++i) {
            cin >> x[i] >> y[i];
        }
        for (int i = m - 1; i >= 0; --i) {
            w[i] = insert(1, 1, n, y[i]);
        }

        map<int, int> tag;
        for (int i = 0; i < m; ++i) {
            tag[w[i] - 1] = 0;
            tag[w[i]] = 1;
        }

        int cnt = 0;
        for (auto v : tag) {
            if (v.se) ++cnt;
        }

        // cout << "cnt : " << cnt << "\n";
        cout << C(n, n - 1 - cnt) << "\n";
    }
    return 0;
}