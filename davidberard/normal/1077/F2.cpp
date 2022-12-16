#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int NMAX = 5050;

ll dd[NMAX][10000];
int dcnt;

struct segtree {
    ll *d;
    //vector<ll> d;
    int n, h;
    segtree(int sz)
    {
        h = sizeof(int)*8 - __builtin_clz(sz);
        n = 1<<h;
        if(n*2 > 10000)
        {
            d = (ll *) malloc(sizeof(ll)*n*2);
            memset(d, -1, sizeof(ll)*n*2);
        } else {
            d = dd[dcnt++];
        }
    }
    void set(int l, int r, ll mv)
    {
        assert(l >= 0 && r < n);
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
    memset(dd, -1, sizeof dd);
    int N, K, x;
    cin >> N >> K >> x;
    vector<int> a(N+1);
    for(int i=1;i<=N;++i)
    {
        cin >> a[i];
    }
    a[0] = 0;
    if(x > N) {
        cout << "Impossible" << endl;
        return 0;
    }
    int sts = N+6-x;
    vector<segtree> dp;
    for(int i=0;i<x+5;++i) dp.push_back(segtree(sts));
    dp[0].set(0, 1, 0);
    for(int j=0;j<=N;++j)
    {
        for(int i=min(x, j);i>=0;--i)
        {
            if(j-i >= sts) continue;
            ll vv = dp[i].get(j-i);
            if(vv < 0) continue;
            dp[i+1].set(j-i, min(j+K-i, sts), vv+a[j]);
            //cerr << " Place " << a[j] << " at " << j << ", v " << i << " set to " << vv+a[j] << " up to index " << min(j+K+1,N+2) << endl;
        }
    }
    if(dp[x+1].get(N-x) == -1)
    {
        cout << "-1\n";
        return 0;
    }
    cout << dp[x+1].get(N-x) << endl;
    return 0;
}