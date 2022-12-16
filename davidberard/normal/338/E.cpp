#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct segtree {
    vector<int> t, s;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<int>(n<<1, 0);
        s = vector<int>(n<<1, 0);
    }
    int& operator[] (const int& i) { return t[i+n]; }
    inline void pulll(int x) {
        s[x] = s[x<<1]+s[x<<1|1];
        t[x] = min(t[x<<1], s[x<<1]+t[x<<1|1]);
    }
    void build() {
        for(int i=n-1;i>0;--i) {
            pulll(i);
        }
    }
    void apply(int i, int v) {
        i+=n;
        t[i] += v;
        s[i] += v;
        for(i/=2; i>0; i/=2) {
            pulll(i);
        }
    }
    bool good() {
        return t[1] >= 0;
    }
};

int n, len, h, siz;

const int NMAX = 150150;

int a[NMAX], b[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> len >> h;
    map<int, int> mp;
    for(int i=0;i<len;++i) {
        cin >> b[i];
        mp[b[i]] = -1;
    }
    for(int i=0;i<n;++i) {
        cin >> a[i];
        mp[h-a[i]] = -1;
    }
    for(auto& p : mp) {
        p.second = siz++;
    }
    segtree st(siz);
    for(int i=0;i<len;++i) {
        st.apply(mp[b[i]], -1);
    }
    for(int i=0;i<len-1;++i) {
        st.apply(mp[h-a[i]], 1);
    }
    int ans = 0;
    for(int i=0;i+len<=n;++i) {
        st.apply(mp[h-a[i+len-1]], 1);
        ans += st.good();
        st.apply(mp[h-a[i]], -1);
    }
    cout << ans << endl;
    return 0;
}