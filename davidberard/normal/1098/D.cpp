#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const int N = 500500;

int xi[N];
char op[N];
int ind[N];
int partner[N];
int n;

ll t[1<<20], d[1<<20];

struct segtree {
    //vector<ll> t; // min value
    //vector<ll> d; // amount to add
    int n, h, ss;

    segtree(int sz) {
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        ss = sz;
        //t = vector<ll>(n*2, 0);
        //d = vector<ll>(n*2, 0);
    }

    inline void apply(int i, ll x) {
        d[i] += x;
        t[i] += x;
        //cerr << " apply " << i << " to " << x << endl;
    }

    inline bool pulll(int x) {
        static int old;
        old = t[x];
        t[x] = min(t[x<<1], t[x<<1|1])+d[x];
        return old != t[x];
        //cerr << "pull " << x << " to " << t[x] << " " << d[x] << " " << t[x<<1] << " " << t[x<<1|1] << endl;
    }

    inline void pull(int x) {
        for (x/=2; x && pulll(x); x/=2);
    }

    inline void pushh(int x) {
        if (d[x]) {
            apply(x<<1, d[x]);
            apply(x<<1|1, d[x]);
            d[x] = 0;
        }
    }

    inline void push(int x) {
        for (int i=h; i>0; --i) {
            pushh(x>>i);
        }
    }

    inline void push2(int a, int b) {
        int l = 31-__builtin_clz((a^b)&1);
        for (int i=h; i>l; --i) {
            pushh(a>>i);
        }
        for (int i=l; i>0; --i) {
            pushh(a>>i); pushh(b>>i);
        }
    }

    inline void add(int l, ll x) {
        int r = ss;
        push2(n+l, n+r-l);
        bool cl = 0, cr = 0;
        for(l+=n, r+=n; l<r; l/=2, r/=2) {
            if (cl) pulll(l-1);
            if (cr) pulll(r);
            if (l%2) {
                apply(l++, x);
                cl = 1;
            }
            if (r%2) {
                apply(--r, x);
                cr = 1;
            }
        }
        for (l--; r>0; l/=2, r/=2) {
            if (cl) pulll(l);
            if (cr && (!cl || l != r)) pulll(r);
        }
    }

    inline void add_single(int i, ll x) {
        push(i+n);
        t[i+n] += x;
        d[i+n] += x;
        pull(i+n);
    }

    int count(int ll, int rr, int i) {
        //cerr << "!count! " << ll << " " << rr << " " << i << endl;
        if (t[i] >= 0) return 0;
        if (i >= n) {
            return t[i] < 0;
        }
        pushh(i);
        return (
            count(ll, (ll+rr)/2, i*2) +
            count((ll+rr)/2, rr, i*2+1)
        );
    }

    inline int query() {
        return count(0, n, 1);
    }
};

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if (S == T) {
        T = (S=buf) + fread(buf, 1, 100000, stdin);
        if (S == T) return EOF;
    }
    return *S++;
}

inline void read(int &x) {
    static char c; x = 0;
    for (c = get(); c < '0' || c > '9'; c = get());
    for (; c >='0' && c <='9'; c = get()) x = x*10 + c - '0';
}

void readc(char &c) {
    for (c=get(); c == ' ' || c == '\r' || c == '\t'; c=get());
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n);
    unordered_map<int, vector<int>> mp;
    vector<pii> vals;
    for (int i=0; i<n; ++i) {
        readc(op[i]);
        read(xi[i]);
        if (op[i] == '+') {
            mp[xi[i]].push_back(i);
            vals.emplace_back(xi[i], i);
        } else {
            partner[mp[xi[i]].back()] = i+1;
            mp[xi[i]].pop_back();
        }
    }
    sort(vals.begin(), vals.end());
    int cs = 0;
    for (int i=0; i<vals.size(); ++i) {
        ind[vals[i].second] = i;
        if (partner[vals[i].second]) {
            ind[partner[vals[i].second]-1] = i;
        }
    }

    segtree st(n);

    int inside = 0;

    for (int i=0; i<n; ++i) {
        if (op[i] == '+') {
            st.add(ind[i]+1, xi[i]*2);
            st.add_single(ind[i], -xi[i]);
            ++inside;
        } else {
            st.add(ind[i]+1, -xi[i]*2);
            st.add_single(ind[i], xi[i]);
            --inside;
        }
        cout << inside-st.query() << '\n';
    }
    return 0;
}