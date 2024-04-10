#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXC = 1000000;

struct node {
    ll mx = 0, lazy = 0;
    node operator+(const node &a) const {
        node rt;
        rt.mx = max(mx, a.mx);
        return rt;
    }
} seg[4 * MAXC + 50];

void give_tag(int rt, ll v) {
    seg[rt].mx += v;
    seg[rt].lazy += v;
}

void down(int rt) {
    if (seg[rt].lazy) {
        give_tag(rt << 1, seg[rt].lazy);
        give_tag(rt << 1 | 1, seg[rt].lazy);
        seg[rt].lazy = 0;
    }
}

void modify(int L, int R, int l, int r, int rt, ll v) {
    if (L <= l && R >= r) return give_tag(rt, v);
    down(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) modify(L, R, l, mid, rt << 1, v);
    if (R > mid) modify(L, R, mid + 1, r, rt << 1 | 1, v);
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && R >= r) return seg[rt].mx;
    down(rt);
    int mid = (l + r) >> 1;
    if (R <= mid) return query(L, R, l, mid, rt << 1);
    if (L > mid) return query(L, R, mid + 1, r, rt << 1 | 1);
    return max(query(L, R, l, mid, rt << 1), query(L, R, mid + 1, r, rt << 1 | 1)); 
}

ll bit[MAXC + 5], bit_all;

void bit_modify(int x, ll v) {
    for (bit_all += v; x <= MAXC; x += x & -x)
        bit[x] += v;
}

ll bit_query(int x) {
    ll rt = 0;
    for (; x; x -= x & -x)
        rt += bit[x];
    return rt;
}

pll qry[300005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        if (c == '?') {
            ll t;
            cin >> t;
            ll res = query(1, t, 1, MAXC, 1) - (bit_all - bit_query(t));
            cout << max(0LL, res - t) << "\n";
        }
        else if (c == '+') {
            ll t, d;
            cin >> t >> d;
            modify(1, t, 1, MAXC, 1, d);
            modify(t, t, 1, MAXC, 1, t);
            bit_modify(t, d);
            qry[i] = pll(t, d);
        }
        else {
            int idx;
            cin >> idx;
            modify(1, qry[idx].X, 1, MAXC, 1, -qry[idx].Y);
            modify(qry[idx].X, qry[idx].X, 1, MAXC, 1, -qry[idx].X);
            bit_modify(qry[idx].X, -qry[idx].Y);
        }
    }
}