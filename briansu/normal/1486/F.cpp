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

const int MAXn = 3e5 + 5, MAXlg = __lg(MAXn) + 2;
vector<int> v[MAXn];
pii qr[MAXn];

int p[MAXn][MAXlg], dph[MAXn], add[MAXn], sub[MAXn], in[MAXn], tit;
int cnt[MAXn], cnt2[MAXn];
map<pair<int, int>, int> mp;

vector<ll> addv, subv;

void dfs1(ll now, ll f) {
    p[now][0] = f;
    for (ll k : v[now]) if (k != f) {
        dph[k] = dph[now] + 1;
        dfs1(k, now);
    }
}

void dfs2(ll now, ll f) {
    // cerr << "now = " << now << ", " << add[now] << " " << sub[now] << " " << dph[now] << endl;
    in[now] = tit;
    addv.pb(add[now]);
    subv.pb(sub[now]);
    tit++;
    for (auto k : v[now])
        if (k != f)
            dfs2(k, now);
    addv.pb(-add[now]);
    subv.pb(-sub[now]);
    tit++;
}

int lca(int a, int b) {
    if (dph[a] < dph[b]) swap(a, b);
    for (int j = MAXlg - 1; j >= 0; j--)
        if (dph[p[a][j]] >= dph[b]) a = p[a][j];
    if (a == b) return a;
    for (int j = MAXlg - 1; j >= 0; j--)
        if (p[a][j] != p[b][j])
            a = p[a][j], b = p[b][j];
    return p[a][0];
}

int la(int a, int x) { // a, x step up
    assert(x >= 0);
    if (x == 0) return a;
    int mx = __lg(x) + 1;
    for (int j = mx; j >= 0; j--)
        if ((1<<j) <= x)
            x -= (1<<j), a = p[a][j];
    return a;
}

ll cal(vector<ll> &dt, int a, int b) {
    if (dph[a] > dph[b])
        swap(a, b);
    return dt[in[b]] - dt[in[a] - 1];
}

ll tt;

ll tt2;
bitset<100> vis[MAXn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs1(1, 1);
    for (int j = 1; j < MAXlg; j++)
        for (int i = 1; i <= n; i++)
            p[i][j] = p[p[i][j - 1]][j - 1];
    ll m;
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> qr[i].X >> qr[i].Y;
    for (int i = 1; i <= m; i++) {
        int a, b;
        a = qr[i].X, b = qr[i].Y;
        int c = lca(a, b);
        if (c == a || c == b) {
            if (dph[a] > dph[b]) swap(a, b);
            // chain, from a (top) to b (bottom)
            add[a]++;
            if (a != b) {
                int t = la(b, dph[b] - dph[a] - 1);
                // cerr << "a, b, t = " << a << " " << b << " " << t << endl;
                sub[t]++;
            }
        } else {
            add[c]++;
            int t;
            t = la(a, dph[a] - dph[c] - 1);
            sub[t]++;
            t = la(b, dph[b] - dph[c] - 1);
            sub[t]++;
        }
    }
    addv.pb(0), subv.pb(0);
    tit++;
    dfs2(1, 1);
    for (int i = 1; i < tit; i++)
        addv[i] += addv[i - 1], subv[i] += subv[i - 1];
    for (int i = 1; i <= m; i++) {
        ll svtt = tt;
        int a, b;
        a = qr[i].X, b = qr[i].Y;
        int c = lca(a, b);
        if (c == a || c == b) {
            if (dph[a] > dph[b]) swap(a, b);
            // chain, from a (top) to b (bottom)
            tt += cal(addv, a, b);
            cnt[a]++;
            if (a != b) {
                int t = la(b, dph[b] - dph[a] - 1);
                tt -= cal(subv, t, b);
                cnt2[t]++;
            }
            else tt--; // self
        } else {
            tt += cal(addv, c, b);
            cnt[c]++;
            int t, t2;
            t = la(a, dph[a] - dph[c] - 1);
            tt += cal(addv, t, a);
            tt -= cal(subv, t, a);
            cnt2[t]++;
            t2 = la(b, dph[b] - dph[c] - 1);
            tt -= cal(subv, t2, b);
            cnt2[t2]++;
            tt++; // self
            if (t > t2) swap(t, t2);
            mp[pii(t, t2)]++;
        }
        // cerr << "i = " << i << ", dlt_tt = " << tt - svtt << endl;
    }
    // cerr << "orig_tt = " << tt << endl;
    for (int i = 1; i <= n; i++) {
        // cerr << i << " " << cnt[i] << " " << cnt2[i] << endl;
        tt -= (ll)cnt[i] * (cnt[i] - 1) / 2;
        for (int k : v[i])
            if (k != p[i][0])
                tt += (ll)cnt2[k] * (cnt2[k] - 1) / 2;
        // cerr << "tt = " << tt << endl;
    }
    for (auto &t : mp)
        tt += (ll)t.Y * (t.Y - 1) / 2;
    cout << tt << endl;
    /* for (int i = 1; i <= m; i++) {
        int a = qr[i].X, b = qr[i].Y;
        int c = lca(a, b);
        while (a != c)
            vis[i][a] = 1, a = p[a][0];
        while (b != c)
            vis[i][b] = 1, b = p[b][0];
        vis[i][c] = 1;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j < i; j++) {
            tt2 += ((vis[i]&vis[j]).count() == 1);
        }
    // cerr << "tt2 = " << tt2 << endl;
    assert(tt == tt2); */
}