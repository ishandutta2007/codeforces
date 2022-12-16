#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 100100;

int n;
int a[N*4];
int f[N*4];
int g[N*4];

struct segtree {
    vector<int> d;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        d = vector<int>(n*2, 0);
    }
    void apply(int l, int r, int x) {
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l%2) {
                d[l] = max(d[l], x);
                ++l;
            }
            if (r%2) {
                --r;
                d[r] = max(d[r], x);
            }
        }
    }
    int query(int i) {
        int ans = 0;
        for(i+=n; i; i/=2) {
            ans = max(ans, d[i]);
        }
        return ans;
    }
};

segtree st;



int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        a[i+n] = a[i];
        a[i+2*n] = a[i];
        a[i+3*n] = a[i];
    }
    st = segtree(n*4+4);

    for (int i=1; i<=4*n; ++i) {
        st.apply(0, i+1, a[i]);
        //cerr << "apply " << a[i] << endl;
        int lo = 1, hi = i;
        while (lo < hi) {
            int m = (lo+hi)/2;
            //cerr << "query " << m << " = " << st.query(m) << endl;
            if (st.query(m) > a[i]*2) {
                lo = m+1;
            } else {
                hi = m;
            }
        }
        f[i] = lo-1;
        g[i] = max(f[i], g[i-1]);
        //cerr << " g[" << i << "] = " << g[i] << " , f[" << i << "] = " << f[i] << endl;
    }

    for (int i=1; i<=n; ++i) {
        int lo = i+1;
        int hi = 4*n;
        while (lo < hi) {
            int m = (lo+hi)/2;
            if (g[m] < i) {
                lo = m+1;
            } else {
                hi = m;
            }
        }
        //cerr << " !! " << lo << endl;
        cout << (lo-i >= n*2 ? -1 : lo-i) << "\n";
    }
    return 0;
}