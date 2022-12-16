#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

int n;

const int NMAX = 500400;

ll t[NMAX*4];
ll dd[NMAX*4];

struct segtree {
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
    }
    inline void apply(int x, ll v) {
        t[x] += v;
        dd[x] += v;
    }
    inline void pulll(int x) {
        t[x] = max(t[x<<1], t[x<<1|1])+dd[x];
    }
    inline void pull(int x) {
        for(x=(x+n)/2; x>0; x/=2) {
            pulll(x);
        }
    }
    inline void pushh(int x) {
        if(dd[x]) {
            apply(x<<1, dd[x]);
            apply(x<<1|1, dd[x]);
            dd[x] = 0;
        }
    }
    inline void push(int i) {
        for(int l=h;l>0;--l) {
            pushh(i>>l);
        }
    }
    void build() {
        for(int i=n-1;i>0;--i) {
            pulll(i);
        }
    }
    void apply(int l, int r, ll x) { // add
        bool cl = 0, cr = 0;
        l += n, r+= n;
        push(l); push(r);
        for(; l<r; l/=2, r/=2) {
            if(cl) pulll(l-1);
            if(cr) pulll(r);
            if(l%2) {
                apply(l++, x);
                cl = 1;
            }
            if(r%2) {
                apply(--r, x);
                cr = 1;
            }
        }
        for(l--; r>0; l/=2, r/=2) {
            if(cl) pulll(l);
            if(cr && (!cl || l != r)) pulll(r);
        }
    }
    ll query(int l, int r) {
        ll ans = -1;
        l +=n;
        r +=n;
        push(l); push(r);
        for(; l<r; l/=2, r/=2) {
            if(l%2) ans = max(ans, t[l++]);
            if(r%2) ans = max(ans, t[--r]);
        }
        return ans;
    }
};

vector<int> d;
segtree st(NMAX);
int at[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    d = vector<int>(n+1, 0);
    ll sum = 0;
    for(int i=1; i<=n; ++i) {
        cin >> d[i];
        sum += d[i];
    }
    sort(d.begin()+1, d.end());
    reverse(d.begin()+1, d.end());
    ll pfx = 0;
    for(int i=1; i<=n; ++i) {
        pfx += d[i];
        st.push(st.n+i);
        t[i+st.n] += pfx-(ll)i*(i-1);
        st.pull(i);
        if(d[i] < i) {
            st.apply(d[i], i, -d[i]);
        }
        at[min(d[i], i)]++;
    }
    ll cur = n-at[0];
    for(int i=1; i<=n; ++i) {
        cur -= at[i];
        st.push(st.n+i);
        t[i+st.n] += -cur*i;
        st.pull(i);
    }


    vector<int> ans;
    for(int i=0; i<=n; ++i) {
        if(i != 0) {
            if(d[i] == 0) break;
            // become friends with person i
            st.apply(i, n+1, -1);
            st.apply(d[i], i, 1);
        }

        if(st.query(1, n+1) <= 0 && (sum+i)%2 == 0) {
            ans.push_back(i);
        }
    }

    if(ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    for(auto& x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}