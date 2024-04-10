#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int NMAX = 5050;

struct segtree {
    vector<ll> d;
    int n, h;
    segtree(int sz)
    {
        h = sizeof(int)*8 - __builtin_clz(sz);
        n = 1<<h;
        d = vector<ll>(n<<1, -1);
    }
    void set(int l, int r, ll mv)
    {
        for(l+=n,r+=n;l<r;l/=2,r/=2)
        {
            if(l%2) {
                d[l] = max(d[l], mv);
                ++l;
            }
            if(r%2) {
                --r;
                d[r] = max(d[r], mv);
            }
        }
    }
    ll get(int x)
    {
        ll ans = -1;
        for(x+=n;x>0;x/=2)
        {
            ans = max(d[x], ans);
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N, K, x;
    cin >> N >> K >> x;
    vector<int> a(N+1);
    for(int i=1;i<=N;++i)
    {
        cin >> a[i];
    }
    a[0] = 0;
    vector<segtree> dp(x+5, segtree(N+5));
    dp[0].set(0, 1, 0);
    for(int j=0;j<=N;++j)
    {
        for(int i=x;i>=0;--i)
        {
            ll vv = dp[i].get(j);
            if(vv < 0) continue;
            dp[i+1].set(j, min(j+K+1, N+2), vv+a[j]);
            //cerr << " Place " << a[j] << " at " << j << ", v " << i << " set to " << vv+a[j] << " up to index " << min(j+K+1,N+2) << endl;
        }
    }
    if(dp[x+1].get(N+1) == -1)
    {
        cout << "-1\n";
        return 0;
    }
    cout << dp[x+1].get(N+1) << endl;
    return 0;
}