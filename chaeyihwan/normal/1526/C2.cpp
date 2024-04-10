#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200002];
ll tree[800002], lazy[800002];
void propagate(int i, int l, int r)
{
    tree[i] += lazy[i];
    if(l != r)
    {
        lazy[i*2] += lazy[i];
        lazy[i*2+1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int l, int r, int s, int e, ll v)
{
    propagate(i, l, r);
    if(e < l || r < s) return;
    if(s <= l && r <= e)
    {
        lazy[i] += v;
        propagate(i, l, r);
        return;
    }
    int m = (l + r)/2;
    update(i*2, l, m, s, e, v);
    update(i*2+1, m+1, r, s, e, v);
    tree[i] = min(tree[i*2], tree[i*2+1]);
}

ll query(int i, int l, int r, int s, int e)
{
    propagate(i, l, r);
    if(e < l || r < s) return 1000000000000000;
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return min(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

struct num
{
    ll v; int i;
    num() : num(0, 0) {}
    num(ll _v, int _i) : v(_v), i(_i) {}
    bool operator < (const num &O) const
    {
        if(v != O.v) return v < O.v;
        return i < O.i;
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    priority_queue<num> pq;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        pq.push(num(a[i], i));
    }
    int ans = 0;
    while(!pq.empty())
    {
        ll v = pq.top().v;
        int i = pq.top().i;
        pq.pop();

        if(query(1, 1, n, i, n) + v >= 0)
        {
            ans++;
            update(1, 1, n, i, n, v);
        }
    }

    cout << ans;
}