#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 250000 + 7;
ll x;
ll y;
ll p;
ll r;
int n;

struct P {
        ll dist;
        ll m;
        ll p;
        ll r;
};

bool operator < (P a, P b) {
        return a.dist < b.dist;

}

P a[N];
ll t[4 * N];
int sol;
vector<int> q;

void build(int v, int tl, int tr) {
        if (tl == tr) {
                t[v] = a[tl].m;
        } else {
                int tm = (tl + tr) / 2;
                build(2 * v, tl, tm);
                build(2 * v + 1, tm + 1, tr);
                t[v] = min(t[2 * v], t[2 * v + 1]);
        }
}

void del(int v, int tl, int tr, int l, int r, ll p) {
        if (tr < l || r < tl) {
                return;
        }
        if (l <= tl && tr <= r) {
                if (t[v] > p) {
                        return;
                }
                if (tl == tr) {
                        sol++;
                        t[v] = (ll) 1e18;
                        q.push_back(tl);
                        return;
                }
        }
        int tm = (tl + tr) / 2;
        del(2 * v, tl, tm, l, r, p);
        del(2 * v + 1, tm + 1, tr, l, r, p);
        t[v] = min(t[2 * v], t[2 * v + 1]);
}

int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> x >> y >> p >> r >> n;
        r *= r;
        for (int i = 1; i <= n; i++) {
                ll x0, y0;
                cin >> x0 >> y0 >> a[i].m >> a[i].p >> a[i].r;
                a[i].dist = (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y);
                a[i].r *= a[i].r;
        }
        sort(a + 1, a + n + 1);
        build(1, 1, n);
        while (1) {
                int lo = 1, hi = n, ans = 0;
                while (lo <= hi) {
                        int m = (lo + hi) / 2;
                        if (a[m].dist <= r) {
                                ans = m;
                                lo = m + 1;
                        } else {
                                hi = m - 1;
                        }
                }
                del(1, 1, n, 1, ans, p);
                if (q.empty()) {
                        break;
                }
                int i = q.back();
                q.pop_back();
                r = a[i].r;
                p = a[i].p;
        }
        cout << sol << "\n";
}