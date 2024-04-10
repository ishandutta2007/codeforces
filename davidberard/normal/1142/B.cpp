#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int INF = 0x3f3f3f3f;

struct segtree {
    vector<int> t;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<int>(n<<1, INF);
    }
    void assign(int i, int v) {
        t[i+=n] = v;
        for(i/=2;i>0;i/=2) {
            t[i] = min(t[i<<1], t[i<<1|1]);
        }
    }
    int query(int l, int r) { 
        int ans = INF;
        for(l+=n, r+=n; l<r; l/=2, r/=2) {
            if(l%2) ans = min(ans, t[l++]);
            if(r%2) ans = min(ans, t[--r]);
        }
        return ans;
    }
};

const int NMAX = 200200, LMAX = 19;

int a[NMAX], p[NMAX], nxt[NMAX], n, m, q, nloc[NMAX];
int dp[NMAX][LMAX];

void build() {
    for(int l=1;l<LMAX;++l) {
        for(int i=0;i<=m;++i) {
            dp[i][l] = dp[dp[i][l-1]][l-1];
            //cerr << " dp " << i << " " << l << " = " << dp[i][l] << endl;
        }
    }
}

void swim(int& i, int h) {
    for(int l=0;l<LMAX;++l) {
        if(h&1) i = dp[i][l];
        h >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    for(int i=1;i<=n;++i) {
        cin >> p[i];
        nxt[p[i-1]] = p[i];
    }
    nxt[p[n]] = p[1];
    nxt[0] = 0;
    for(int i=1;i<=m;++i) {
        cin >> a[i];
    }
    for(int i=m;i>0;--i) {
        dp[i][0] = nloc[nxt[a[i]]];
        //cerr << " dp " << i << " 0 " << dp[i][0] << endl;
        nloc[a[i]] = i;
    }
    build();
    segtree st(NMAX);
    for(int i=1;i<=m;++i) {
        int j = i;
        swim(j, n-1);
        st.assign(i, (j > 0 ? j : INF));
        //cerr << "assigning" << i << " to " << j << endl;
    }
    string s;
    for(int i=0;i<q;++i) {
        int l, r;
        cin >> l >> r;
        if(st.query(l, r+1) <= r) {
            s += '1';
        } else {
            s += '0';
        }
    }
    cout << s << endl;
    return 0;
}