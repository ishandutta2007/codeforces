#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MOD = 998244353;

ll Ap[35];
ll k, A, h, n;

ll s[10];

ll d[10][35], ans[35];

void go(int lv) {
    if (lv == 0) {
        if (d[0][0] == s[0]) {
            ans[d[0][0]] = 1;
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " \n"[i == n];
            exit(0);
        }
        return;
    }
    int p = (1<<(lv - 1)) + 1;
    int cnt = (1<<(lv - 1));
    for (int I = 0; I < (1<<cnt); I++) {
        int tt = 0;
        for (int i = 0; i < cnt; i++) {
            ll w = d[lv][2 * i + !((I>>i)&1)];
            ll l = d[lv][2 * i + ((I>>i)&1)];
            tt += l;
            ans[l] = p;
            d[lv - 1][i] = w;
        }
        if (tt == s[lv])
            go(lv - 1);
    }
}

int cnt[15], p[15], lb[15], ub[15];

void dfs(int lv, ll cur) {
    if (lv == -1) {
        if (cur % MOD != 0)
            return;
        ll tt = 0;
        for (int i = k; i >= 0; i--)
            tt += s[i];
        if (tt != (1 + n) * n / 2)
            return;
        go(k);
        return;
    }
    cur -= lb[lv] * Ap[p[lv]];
    for (int i = lb[lv]; i <= ub[lv]; i++) {
        s[lv] = i;
        dfs(lv - 1, cur);
        cur -= Ap[p[lv]];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> A >> h;
    n = (1<<k);
    Ap[0] = 1;
    for (int i = 1; i <= (1<<k); i++)
        Ap[i] = Ap[i - 1] * A % MOD;
    for (int i = 0; i < n; i++)
        d[k][i] = i + 1;
    for (int lv = k; lv >= 0; lv--) {
        cnt[lv] = (lv == 0 ? 1 : (1<<(lv - 1)));
        p[lv] = (lv == 0 ? 1 : (1<<(lv - 1)) + 1);
        lb[lv] = (1 + 1 + (n / cnt[lv]) * (cnt[lv] - 1)) * cnt[lv] / 2;
        ub[lv] = lb[lv] + (n / cnt[lv] - 1) * cnt[lv];
    }
    dfs(k, h); 
    cout << -1 << endl;
}