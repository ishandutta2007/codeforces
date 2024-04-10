#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll a[50002], p[50002], f[50002];
ll tree[200002];

ll init(int i, int l, int r){
    if(l == r) return tree[i] = f[l];
    int m = (l + r)/2;
    return tree[i] = max(init(i*2, l, m), init(i*2+1, m+1, r));
}

ll query(int i, int l, int r, int s, int e){
    if(e < l || r < s) return -INF;
    if(s <= l && r <= e) return tree[i];
    int m = (l + r)/2;
    return max(query(i*2, l, m, s, e), query(i*2+1, m+1, r, s, e));
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        ll x; cin >> x;
        for(int i=1;i<=n;i++) p[i] = a[i] + p[i-1];
        for(int i=1;i<=n;i++) f[i] = p[i] - x * i;

        init(1, 0, n);

        int cnt = 0;
        for(int i=2,j=0;i<=n;i++)
        {
            ll L = query(1, 0, n, j, i-2);
            if(f[i] < L)
            {
                j = i;
                i++;
                cnt++;
            }
        }
        cout << n - cnt << "\n";
    }
}