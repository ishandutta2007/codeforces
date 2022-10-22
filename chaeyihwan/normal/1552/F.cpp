#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod = 998244353;

ll tree[800002], lazy[800002];
void propagate(int i, int l, int r)
{
    tree[i] += lazy[i];
    tree[i] %= mod;
    if(l != r)
    {
        lazy[i*2] = (lazy[i] + lazy[i*2])%mod;
        lazy[i*2+1] = (lazy[i] + lazy[i*2+1])%mod;
    }
    lazy[i] = 0;
}

void update(int i, int l, int r, int s, int e, ll v)
{
    if(e < s) return;
    propagate(i, l, r);
    if(e < l || r < s) return;
    if(s <= l && r <= e)
    {
        lazy[i] = (lazy[i] + v)%mod;
        propagate(i, l, r);
        return;
    }
    int m = (l + r)/2;
    update(i*2, l, m, s, e, v);
    update(i*2+1, m+1, r, s, e, v);
    tree[i] = (tree[i*2] + tree[i*2+1])%mod;
}

ll query(int i, int l, int r, int s, int e)
{
    propagate(i, l, r);
    if(e < s) return 0;
    if(e < l || r < s) return 0;
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return (query(i*2, l, m, s, e) + query(i*2+1, m+1, r, s, e))%mod;
}
int x[200002], y[200002], s[200002], w[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;

    for(int i=1;i<=n;i++) cin >> x[i] >> y[i] >> s[i];
    for(int i=1;i<=n;i++) w[i] = lower_bound(x+1, x+n+1, y[i]) - x;
    for(int i=1;i<=n;i++) update(1, 1, n, i, i, s[i]);
    for(int i=n;i>=1;i--)
    {
        ll x = query(1, 1, n, i, i);
        update(1, 1, n, w[i], i-1, x);
    }

    ll ans = x[n] + 1;

    for(int i=1;i<=n;i++)
    {
        ans += query(1, 1, n, i, i) * (x[i] - y[i]);
        ans %= mod;
    }

    cout << ans;
}