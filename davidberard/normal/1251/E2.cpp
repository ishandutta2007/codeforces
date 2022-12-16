#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
const int INF = 0x3f3f3f3f;

struct segtree {
    vector<pii> t;
    int n, h;
    segtree () {}
    segtree (vector<int>& v) {
        int sz = v.size();
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<pii>(n*2, pii(INF, -1));
        for (int i=0; i<v.size(); ++i) {
            t[i+n] = pii(v[i], i);
        }
        for (int i=n-1; i; --i) {
            t[i] = min(t[i<<1], t[i<<1|1]);
        }
    }
    pii query(int l, int r) {
        pii ans(INF, -1);
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l%2) ans = min(ans, t[l++]);
            if (r%2) ans = min(ans, t[--r]);
        }
        return ans;
    }
    void assign(int i, int v) {
        i +=n;
        t[i] = pii(v, i-n);
        for (i/=2; i; i/=2) {
            t[i] = min(t[i<<1], t[i<<1|1]);
        }
    }
};

int n;
segtree st;
vector<pii> mp;
vector<int> f;

ll solve() {
    cin >> n;
    f = vector<int>(n+1, 0);
    mp = vector<pii>();
    for (int i=0; i<n; ++i) {
        int m, p;
        cin >> m >> p;
        mp.emplace_back(m, p);
    }
    sort(mp.begin(), mp.end());
    vector<int> vals;
    for(int i=0; i<n; ++i) {
        vals.push_back(mp[i].second);
    }
    st = segtree(vals);

    int jj = 0;
    for (int i=0; jj<n && i<=n; ++i) {
        while (jj < n && mp[jj].first <= i) {
            f[i] ++;
            ++jj;
        }
    }
    for (int i=1; i<=n; ++i) {
        f[i] += f[i-1];
    }

    ll ans = 0;
    int extra = 0;
    for (int i=n-1; i >= 0; --i) {
        int need = i-f[i]+1-extra;
        //cerr << " at " << i << " need " << need << endl;
        while (need > 0) {
            extra ++;
            pii gg = st.query(f[i], vals.size());
            assert(gg.second != -1);
            ans += gg.first;
            st.assign(gg.second, INF);
            need = i-f[i]+1-extra;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    for (int tt=1; tt<=TT; ++tt) {
        cout << solve() << "\n";
    }
    return 0;
}