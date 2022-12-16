#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

struct node {
    int df, ma, mb, mab, mbc, mabc;
    //node() :df(0), ma(0), mb(0), mab(-1e9), mbc(-1e9), mabc(-1e9) {}
};

node t[1<<19];

struct segtree {
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
    }
    void pulll(int i) {
        node& l = t[i<<1];
        node& r = t[i<<1|1];
        node& p = t[i];
        p.df = l.df+r.df;
        p.ma = max(l.ma, l.df+r.ma);
        p.mb = max(l.mb, -2*l.df+r.mb);
        //cerr << "  mab " << l.mab << " " << -l.df+r.mab << " " << l.ma+r.mb-2*l.df << " :: " << l.ma << " " << r.mb << " " << l.df<< "\n";
        p.mab = max(max(l.mab, -l.df+r.mab), l.ma+r.mb-2*l.df);
        p.mbc = max(max(l.mbc, -l.df+r.mbc), l.mb+r.ma+l.df);
        p.mabc = max(max(l.mabc, r.mabc), max(l.mab+r.ma+l.df, l.ma+r.mbc-l.df));
        //cerr << " " << i << ": " << p.df << " " << p.ma << " " << p.mb << " " << p.mab << " " << p.mbc << " " << p.mabc << " " << "\n";
    }
    void assign(int i, char c) {
        //cerr << " assigning " << c << " to " << i << "\n";
        i+= n;
        if(c == ')') {
            t[i].df = -1;
        } else {
            t[i].df = 1;
        }
        for(i/=2; i>0; i/=2) {
            pulll(i);
        }
    }
    int query() {
        return t[1].mabc;
    }
};

const int NMAX = 200100;

int n,q;
char s[NMAX];
segtree st(NMAX);

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    cin >> s;
    for(int i=0; s[i]; ++i) {
        st.assign(i, s[i]);
    }
    cout << st.query() << "\n";
    for(int i=0; i<q; ++i) {
        int a, b;
        cin >> a >> b;
        swap(s[--a], s[--b]);
        //cerr << s << "\n";
        st.assign(a, s[a]);
        st.assign(b, s[b]);
        cout << st.query() << "\n";
    }
    return 0;
}