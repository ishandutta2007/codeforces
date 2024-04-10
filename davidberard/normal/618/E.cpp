#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pii;

const ld PI = 3.1415926535897932384626l;

/*
 * Segtree storing delta x, delta y for each segment
 * Ability to do "rotate" on segment (i.e. lazy rotate)
 * Range query gives you sum of deltas.
 *
 */

struct op {
    ld a, b, c, d, e, f;
    op() : a(0.l), b(1.l), c(0.l), d(0.l), e(0.l), f(1.l) {}
    static op rot(const ld& deg) {
        ld rad = deg*PI/180;
        op out;
        out.b = cos(rad);
        out.c = -sin(rad);
        out.e = sin(rad);
        out.f = cos(rad);
        return out;
    }
    static op len(const ld& deg, const ld& l) {
        ld rad = deg*PI/180;
        op out;
        out.a = l * cos(rad);
        out.d = l * sin(rad);
        //cerr << " LEN FOR " << deg << "," << l << ": ";
        //cerr; for (auto& x : out.vals) //cerr << x << " ";
        //cerr << endl;
        return out;
    }
    void clear() {
        a = 0.l;
        b = 1.l;
        c = 0.l;
        d = 0.l;
        e = 0.l;
        f = 1.l;
    }
    op operator* (op& o) const {
        op out;
        out.a = a+b*o.a+c*o.d;
        out.b = b*o.b+c*o.e;
        out.c = b*o.c+c*o.f;
        out.d = d+e*o.a+f*o.d;
        out.e = e*o.b+f*o.e;
        out.f = e*o.c+f*o.f;
        return out;
    }
    void print() const {
        //cerr; for (int i=0; i<9; ++i) //cerr << vals[i] << " ";
    }
};

struct pt {
    ld x, y;
    pt() : x(0), y(0) {}
    pt(ld a, ld b) : x(a), y(b) {}
    pt apply(op o) const {
        ld tx = o.a + x*o.b + y*o.c;
        ld ty = o.d + x*o.e + y*o.f;
        return pt(tx, ty);
    }
    pt operator+ (const pt& o) const {
        return pt(x+o.x, y+o.y);
    }
};

// based on [1, x, y]^T structure

struct segtree {
    vector<pt> t;
    vector<op> d;
    vector<char> dd;
    int n, h;
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<pt>(n*2);
        d = vector<op>(n*2);
        dd = vector<char>(n*2, 0);
        for (int i=0; i<sz; ++i) {
            t[i+n].x = 1.l;
        }
        for (int i=n-1; i>0; --i) {
            pulll(i);
        }
        //cerr; for (int i = 0; i < 2*n; ++i) //cerr << " init " << i << ": " << t[i].x << ", " << t[i].y << endl;
    }
    void apply(int x, op o) {
        //cerr << " for " << x << "::";
        //cerr << " was " << t[x].x << " " << t[x].y;
        dd[x] = 1;
        d[x] = o * d[x];
        t[x] = t[x].apply(o);
        //cerr << " is " << t[x].x << " " << t[x].y << " :: ";
        // o.print();
        //cerr << endl;
    }
    void pushh(int x) {
        if (dd[x]) {
            apply(x<<1, d[x]);
            apply(x<<1|1, d[x]);
            d[x].clear();
            dd[x] = 0;
        }
    }
    void push(int x) {
        for (int i=h; i>0; --i) {
            pushh(x>>i);
        }
    }
    void pulll(int x) {
        t[x] = (t[x<<1]+t[x<<1|1]);
        if (dd[x]) {
            t[x] = t[x].apply(d[x]);
        }
        //cerr << " pull " << x << " to " << t[x].x << " " << t[x].y << "(" << (t[x<<1]).x << " + " << t[x<<1|1].x << ", ..)"<< endl;
    }
    pt query(int l, int r) {
        push(l+n); push(r+n-1);
        pt ans(0, 0);
        for (l += n, r += n; l<r; l/=2, r/=2) {
            if (l%2) {
                ans = ans + t[l++];
            }
            if (r%2) {
                ans = ans + t[--r];
            }
        }
        return ans;
    }
    void update(int l, int r, op o) {
        push(l+n); push(r+n-1);
        bool cl=0, cr=0;
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (cl) {
                pulll(l-1);
            }
            if (cr) {
                pulll(r);
            }
            if (l%2) {
                apply(l++, o);
                cl = 1;
            }
            if (r%2) {
                apply(--r, o);
                cr = 1;
            }
        }
        for (--l; r; l/=2, r/=2) {
            if (cl) pulll(l);
            if (cr && (!cl || l != r)) pulll(r);
        }
    }
};

int n, m;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    cout << fixed <<setprecision(10) ;
    segtree st(n);
    for (int i=0; i<m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --y;
        if (x == 1) {
            st.push(y+st.n);
            ld deg = atan2(st.t[y+st.n].y, st.t[y+st.n].x)*180/PI;
            st.update(y, y+1, op::len(deg, z));
            pt a = st.t[1];
            cout << a.x << " " << a.y << "\n";
        } else {
            st.update(y, st.n, op::rot(-z));
            pt a = st.t[1];
            cout << a.x << " " << a.y << "\n";
        }
    }
    return 0;
}