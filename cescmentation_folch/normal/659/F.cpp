#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppll;
typedef priority_queue<ppll> pql;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef queue<pll> qp;

vvi V;
vvi B;
vi P;
vi G;
ll n, m, k;

ll pare(ll x) {
    if (P[x] == -1) return x;
    return P[x] = pare(P[x]);
}

ll pos(ll x, ll y) {
    return x*m + y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    pql Q;
    V = vvi(n, vi(m, 0));
    B = vvi(n, vi(m)); 
    P = vi(n*m, -1);
    G = vi(n*m, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ll k;
            cin >> k;
            B[i][j] = k;
            Q.push(ppll(k, pll(i, j)));
        }
    }
    ll kx = -1;
    ll ky = -1;
    ll kval = -1;
    while (!Q.empty()) {
        ppll tt = Q.top();
        Q.pop();
        ll val = tt.first;
        pll ttp = tt.second;
        V[ttp.first][ttp.second] = 1;
        ll x = ttp.first;
        ll y = ttp.second;
        if (x > 0 and V[x - 1][y]) {
            if (pare(pos(x, y)) != pare(pos(x - 1, y))) {
                G[pare(pos(x, y))] += G[pare(pos(x - 1, y))];
                P[pare(pos(x - 1, y))] = pare(pos(x, y));
            }
        }
        if (x < n - 1 and V[x + 1][y]) {
            if (pare(pos(x, y)) != pare(pos(x + 1, y))) {
                G[pare(pos(x, y))] += G[pare(pos(x + 1, y))];
                P[pare(pos(x + 1, y))] = pare(pos(x, y));
            }
        }
        if (y < m - 1 and V[x][y + 1]) {
            if (pare(pos(x, y)) != pare(pos(x, y + 1))) {
                G[pare(pos(x, y))] += G[pare(pos(x, y + 1))];
                P[pare(pos(x, y + 1))] = pare(pos(x, y));
            }
        }
        if (y > 0 and V[x][y - 1]) {
            if (pare(pos(x, y)) != pare(pos(x, y - 1))) {
                G[pare(pos(x, y))] += G[pare(pos(x, y - 1))];
                P[pare(pos(x, y - 1))] = pare(pos(x, y));
            }
        }

        if (k%val == 0 and val*G[pare(pos(x, y))] >= k) {
            kx = x;
            ky = y;
            kval = val;
            break;
        }
    }
    if (kval == -1) {
        cout << "NO" << endl;
        return 0;
    }
    qp Qr;
    Qr.push(pll(kx, ky));
    ll tt = k/kval;
    while (!Qr.empty()) {
        ll x = Qr.front().first;
        ll y = Qr.front().second;
        Qr.pop();
        if (V[x][y] == 2) continue;
        V[x][y] = 2;
        --tt;
        if (tt == 0) break;
        if (x > 0 and V[x - 1][y] < 2 and B[x - 1][y] >= kval) {
            Qr.push(pll(x - 1, y));
        }
        if (x < n - 1 and V[x + 1][y] < 2 and B[x + 1][y] >= kval) {
            Qr.push(pll(x + 1, y));
        }
        if (y < m - 1 and V[x][y + 1] < 2 and B[x][y + 1] >= kval) {
            Qr.push(pll(x, y + 1));
        }
        if (y > 0 and V[x][y - 1] < 2 and B[x][y - 1] >= kval) {
            Qr.push(pll(x, y - 1));
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j) cout << ' ';
            if (V[i][j] == 2) cout << kval;
            else cout << 0;
        }
        cout << endl;
    }
}