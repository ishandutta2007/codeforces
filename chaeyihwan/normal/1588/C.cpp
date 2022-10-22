#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")
using namespace std;
typedef long long ll;
const ll INF = 1e16;

ll a[300002];
struct node
{
    ll s, M, m;
    node() : node(0, 0, 0) {}
    node(ll _s, ll _M, ll _m) : s(_s), M(_M), m(_m) {}
};
node tree[1200002];

node add(node x, node y)
{
    node ret;
    ret.M = min(x.M, x.s + y.M);
    ret.m = max(x.m, x.s + y.m);
    ret.s = x.s + y.s;
    return ret;
}

void init(int i, int l, int r)
{
    if(l == r)
    {
        if(l%2 == 1) tree[i] = node(a[l], a[l], -INF);
        else tree[i] = node(a[l], INF, a[l]);
        return;
    }
    int m = (l + r)/2;
    init(i*2, l, m);
    init(i*2+1, m+1, r);
    tree[i] = add(tree[i*2], tree[i*2+1]);
}

node query(int i, int l, int r, int s, int e)
{
    if(e < l || r < s) return node(0, INF, -INF);
    if(s <=l && r <= e) return tree[i];
    int mid = (l + r)/2;
    return add(query(i*2, l, mid, s, e), query(i*2+1, mid+1, r, s, e));
}

int nxt[300002];
ll dp[300002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=2;i<=n;i+=2) a[i] = -a[i];
        init(1, 1, n);
        for(int i=1;i<=n;i++)
        {
            if(a[i] == 0)
            {
                nxt[i] = i;
                continue;
            }

            int l = i+1, r = n+1;
            while(l < r)
            {
                int mid = (l + r)/2;
                node nd = query(1, 1, n, i, mid);
                if(nd.M > 0 && nd.m < 0) l = mid + 1;
                else r = mid;
            }
            if(l == n + 1) nxt[i] = n+1;
            node nd = query(1, 1, n, i, l);
            if(nd.s == 0 && nd.M >= 0 && nd.m <= 0) nxt[i] = l;
            else nxt[i] = n+1;
        }

        ll ans = 0;
        for(int i=1;i<=n;i++) dp[i] = 1;
        for(int i=1;i<=n;i++)
        {
            if(nxt[i] <= n)
            {
                ans += dp[i];
                dp[nxt[i]+1] += dp[i];
            }
        }
        cout << ans << "\n";
    }
}