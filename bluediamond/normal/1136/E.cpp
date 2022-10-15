/// Lazy Fenwick Tree LOL :)
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = (ll) 5e5 + 7;
const ll INF = (ll) 1e18;
ll n;
ll a[N];
ll k[N];
ll t[N];
ll b[N];

struct kek {
        ll mx, sum;
};

kek __merge(kek a, kek b) {
        return {max(a.mx, b.mx), a.sum + b.sum};
}

ll prefix[N];

kek tree[4 * N];
bool full[4 * N];
ll lazy[N];

void splay(ll node, ll tl, ll tr) {
        if (full[node] && tl < tr && 2 * node + 1 < 4 * N) {
                full[node] = 0;
                full[2 * node] = full[2 * node + 1] = 1;
                lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
                ll tm = (tl + tr) / 2;
                tree[2 * node] = {lazy[2 * node], lazy[2 * node] * (ll) (tm - tl + 1)};
                tree[2 * node + 1] = {lazy[2 * node + 1], lazy[2 * node + 1] * (ll) (tr - (tm + 1) + 1)};
                lazy[node] = 0;
        }
}

void upd(ll node, ll tl, ll tr, ll l, ll r, ll value) {
        if (r < tl || tr < l) {
                return;
        }
        if (l <= tl && tr <= r) {
                full[node] = 1;
                lazy[node] = value;
                tree[node] = {value, value * (ll) (tr - tl + 1)};
        } else {
                splay(node, tl, tr);
                ll tm = (tl + tr) / 2;
                upd(2 * node, tl, tm, l, r, value);
                upd(2 * node + 1, tm + 1, tr, l, r, value);
                tree[node] = __merge(tree[2 * node], tree[2 * node + 1]);
        }
}

kek get(ll node, ll tl, ll tr, ll l, ll r) {
        if (r < tl || tr < l) {
                return {-INF, 0LL};
        }
        if (l <= tl && tr <= r) {
                return tree[node];
        } else {
                ll tm = (tl + tr) / 2;
                splay(node, tl, tr);
                return __merge(get(2 * node, tl, tm, l, r), get(2 * node + 1, tm + 1, tr, l, r));
        }
}

ll get_sum(ll l, ll r) {
        return get(1, 1, n, l, r).sum + prefix[r] - prefix[l - 1];
}


int main() {
      //  freopen ("panarama", "r", stdin);
        ios::sync_with_stdio(false);
        cin.tie(0);

        cin >> n;
        for (ll i = 1; i <= n; i++) {
                cin >> a[i];
        }
        ll cur = 0LL;
        for (ll i = 1; i <= n - 1; i++) {
                cin >> k[i];
                cur += k[i];
                t[i] = cur;
        }

        for (ll i = 1; i <= n; i++) {
                b[i] = a[i] - t[i - 1];
                prefix[i] = prefix[i - 1] + t[i - 1];
        }

        for (ll i = 1; i <= n; i++) {
                upd(1, 1, n, i, i, b[i]);
        }

        ll q;
        cin >> q;
        for (ll tq = 1; tq <= q; tq++) {
                string type;
                cin >> type;
                if (type == "+") {
                        ll p, x;
                        cin >> p >> x;
                        ll value = get(1, 1, n, p, p).mx + (ll) x;
                        ll lo = p + 1, hi = n;
                        ll fi_upd = p, ls_upd = p;
                        while (lo <= hi) {
                                ll mid = (lo + hi) / 2;
                                ll it = get(1, 1, n, p + 1, mid).mx;
                                if (it < value) {
                                        lo = mid + 1;
                                        ls_upd = mid;
                                } else {
                                        hi = mid - 1;
                                }
                        }
                        if (1 <= fi_upd && fi_upd <= ls_upd && ls_upd <= n) {
                                upd(1, 1, n, fi_upd, ls_upd, value);
                        }

                } else {
                        ll l, r;
                        cin >> l >> r;
                        cout << get_sum(l, r) << "\n";
                }
        }

        return 0;
}