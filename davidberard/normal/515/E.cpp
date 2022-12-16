#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll INF = 0x3f3f3f3f3f3f3f3fll;

template <typename T>
struct max2 {
    T f, s;
    max2() {}
    max2(T a, T b) : f(a), s(b) {}
    void insert(T x) {
        if(x > f) {
            swap(f, s);
            f = x;
        } else if(x > s) {
            s = x;
        }
    }
    max2 operator+ (const max2& o) const {
        max2 out = o;
        out.insert(f);
        out.insert(s);
        return out;
    }
    void print() {
        //cerr << "((" << f.first << "," << f.second <<"),(" << s.first << "," << s.second << ")";
    }
};

struct segtree {
    vector<max2<pii>> t;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32-__builtin_clz(sz);
        n = 1<<h;
        t = vector<max2<pii>>(n<<1, max2<pii>(pii(-INF, -INF), pii(-INF, -INF)));
    }
    void build() {
        for(int i=n-1;i>0;--i) {
            t[i] = t[i<<1] + t[i<<1|1];
        }
    }
    max2<pii> query(int l, int r) {
        max2<pii> ans(pii(-INF, -INF),pii(-INF, -INF));
        for(l+=n, r+=n; l<r; l/=2, r/=2) {
            if(l%2) ans = t[l++] + ans;
            if(r%2) ans = t[--r] + ans;
        }
        return ans;
    }
};

const int NMAX = 200200;

int n, m;

ll d[NMAX], pfx[NMAX], h[NMAX];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        cin >> d[i];
    }
    for(int i=1;i<=n;++i) {
        cin >> h[i];
    }
    for(int i=n+1;i<=n*2;++i) {
        d[i] = d[i-n];
        h[i] = h[i-n];
    }
    for(int i=2;i<=n*2;++i) {
        pfx[i] = pfx[i-1]+d[i-1];
    }
    segtree st(n*2+1);
    segtree st2(n*2+1);
    for(int i=1;i<=n*2;++i) {
        st.t[i+st.n].f = pii(pfx[i]+2*h[i], i);
        st2.t[i+st2.n].f = pii(-pfx[i]+2*h[i], i);
    }
    st.build();
    st2.build();
    for(int i=0;i<m;++i) {
        int a,b;
        cin >> a >> b;
        if(b >= a) {
            a += n;
        }
        //cerr << " " << b << " " << a << endl;
        max2<pii> l = st.query(b+1, a);
        max2<pii> r = st2.query(b+1, a);
        //cerr << "   ";
        l.print();
        //cerr << "   ";
        r.print();
        ll bst = -INF;
        if(l.f.second != r.f.second) {
            bst = max(bst, l.f.first+r.f.first);
        }
        if(l.f.second != r.s.second) {
            bst = max(bst, l.f.first+r.s.first);
        }
        if(l.s.second != r.f.second) {
            bst = max(bst, l.s.first+r.f.first);
        }
        if(l.s.second != r.s.second) {
            bst = max(bst, l.s.first+r.s.first);
        }
        cout << bst << "\n";
        //cerr << endl;
    }
    return 0;
}