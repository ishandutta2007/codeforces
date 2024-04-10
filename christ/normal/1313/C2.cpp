#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 500005;

vector<long long> arr(MAXN);

struct node
{
    int i;
    long long mi = INT_MAX;
    long long sum = 0;
    long long lazy = 0;
};

node st[MAXN * 7];

node build(int l, int r, int v)
{
    if (l == r)
    {
        st[v].i = l;
        st[v].mi = arr[l];
        st[v].sum = arr[l];
        return st[v];
    }
    int m = l+r>>1;
    node ll = build(l, m, v<<1);
    node rr = build(m+1, r, v<<1|1);
    if (ll.mi < rr.mi)
        st[v].mi = ll.mi, st[v].i = ll.i;
    else
        st[v].mi = rr.mi, st[v].i = rr.i;
    st[v].sum = ll.sum + rr.sum;
    return st[v];
}

void pushdown(int l, int r, int v)
{
    if (st[v].lazy)
    {
        st[v].sum = (r - l + 1) * st[v].lazy;
        st[v].mi = st[v].lazy;
        st[v].i = l;
        if (l != r)
            st[v<<1].lazy = st[v].lazy, st[v<<1|1].lazy = st[v].lazy;
        st[v].lazy = 0;
    }
}

node query(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return {0, INT_MAX, 0, 0};
    pushdown(l, r, v);
    if (l >= li && r <= ri)
        return st[v];
    int m = l+r>>1;
    node ll = query(l, m, v<<1, li, ri);
    node rr = query(m+1, r, v<<1|1, li, ri);
    return node{
        ll.mi < rr.mi ? ll.i : rr.i,
        ll.mi < rr.mi ? ll.mi : rr.mi,
        ll.sum + rr.sum,
        0
    };
}

node update(int l, int r, int v, int li, int ri, long long val)
{
    pushdown(l, r, v);
    if (l > ri || r < li)
        return st[v];
    if (l >= li && r <= ri)
    {
        st[v].lazy = val;
        pushdown(l, r, v);
        return st[v];
    }
    int m = l+r>>1;
    node ll = update(l, m, v<<1, li, ri, val);
    node rr = update(m+1, r, v<<1|1, li, ri, val);
    return st[v] = node{
        ll.mi < rr.mi ? ll.i : rr.i,
        ll.mi < rr.mi ? ll.mi : rr.mi,
        ll.sum + rr.sum,
        0
    };
}

void conq(int l, int r)
{
    if (r < l)
        return;
    int i = query(1, n, 1, l, r).i;
    conq(l, i-1), conq(i+1, r);
    if (query(1, n, 1, l, i).sum + (r - i) * arr[i] > query(1, n, 1, i, r).sum + (i - l) * arr[i])
        update(1, n, 1, i, r, arr[i]);
    else
        update(1, n, 1, l, i, arr[i]);
}

int main()
{
    arr[0] = LONG_MAX;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    build(1, n, 1);
    conq(1, n);
    for (int x = 1; x <= n; x++)
        printf("%lli ", query(1, n, 1, x, x).sum);
}