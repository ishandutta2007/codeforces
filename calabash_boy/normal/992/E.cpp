//
// Created by calabash_boy on 18-6-19.
//
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define debug(x) std::cout << #x << ": " << x << '\n';
typedef long long ll;

const int N = 1e6;

struct node {
    ll max = 0, push = 0;
    node() {}
    node(ll _cur, ll _push = 0) {
        max = _cur;
        push = _push;
    }
}tree[N];
ll a[N];
void build(int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = node(a[tl]);
        return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    tree[v].max = max(tree[v * 2].max, tree[v * 2 + 1].max);
}
void push(int v) {
    if (v * 2 < N) {
        tree[v * 2].push += tree[v].push;
        tree[v * 2].max += tree[v].push;
    }
    if (v * 2 + 1 < N) {
        tree[v * 2 + 1].push += tree[v].push;
        tree[v * 2 + 1].max += tree[v].push;
    }
    tree[v].push = 0;
}
void update(int v, int tl, int tr, int l, int r, ll x) {
    push(v);
    if (l > r)return;
    if (tl == l && tr == r) {
        tree[v].push += x;
        tree[v].max += x;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), x);
    update(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, x);
    tree[v].max = max(tree[v * 2].max, tree[v * 2 + 1].max);
}
int query(int v, int tl, int tr) {
    push(v);
    if (tree[v].max < 0)return -2;
    if (tl == tr && tree[v].max == 0) return tl;
    if (tl == tr)return -2;
    int tm = (tl + tr) / 2;
    int answ = query(v * 2, tl, tm);
    if (answ == -2) {
        answ = query(v * 2 + 1, tm + 1, tr);
    }
    tree[v].max = max(tree[v * 2].max, tree[v * 2 + 1].max);
    return answ;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    int n, q;
    cin >> n >> q;
    vector<ll> curA(n);
    ll sum = 0;
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        curA[i] = x;
        a[i] = x - sum;
        sum += x;
    }
    build(1, 0, n - 1);
    for (int i=0;i<q;i++){
        ll ai, b;
        cin >> ai >> b;
        --ai;
        ll delta = b - curA[ai];
        curA[ai] = b;
        update(1, 0, n - 1, ai, ai, delta);
        update(1, 0, n - 1, ai + 1, n - 1, -delta);
        cout << query(1, 0, n - 1) + 1 << '\n';
    }
}