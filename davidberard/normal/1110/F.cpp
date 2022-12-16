#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

const ll LLINF = 0x3f3f3f3f3f3f3f3f;

struct segtree {
    vector<ll> t;
    vector<ll> d;
    int n, h;
    segtree() {}
    segtree(int sz) {
        h = 32-__builtin_clz(sz);
        n = 1<<h;
        t=vector<ll>(n<<1, LLINF);
        d=vector<ll>(n<<1, 0);
    }
    ll& operator[](const int i) {
        return t[i+n];
    }
    void build() {
        for(int x=n-1;x>0;--x) {
            t[x] = min(t[x<<1], t[x<<1|1]);
        }
    }
    void pushh(int x) {
        //cerr << " clear d[" << x << "]" << endl;
        if(d[x] == 0) return;
        apply(x<<1, d[x]);
        apply(x<<1|1, d[x]);
        d[x] = 0;
    }
    void push(int x) {
        x += n;
        for(int l=h;l>0;--l) {
            pushh(x>>l);
        }
    }
    ll query(int l, int r) {
        //cerr << "  query " << l << " " << r << endl;
        ll ans = LLINF;
        push(l);
        push(r-1);
        for(l+=n,r+=n;l<r;l/=2,r/=2) {
            if(l&1) ans = min(ans, t[l++]);
            if(r&1) ans = min(ans, t[--r]);
        }
        //cerr << "  query " << l << " " << r << " returned " << ans << endl;
        return ans;
    }
    void calc(int x) {
        //cerr << " calc at " << x << endl;
        assert(d[x] == 0);
        t[x] = min(t[x<<1],t[x<<1|1]);
    }
    void apply(int x, ll v) {
        //cerr << " change d[" << x << "] = " << v << endl;
        d[x] += v;
        t[x] += v;
    }
    void incr(int l, int r, ll v) {
        //cerr << "  incr " << l << " " << r << " " << v << endl;
        int l0 = l, r0 = r;
        push(l0);
        push(r0-1);
        bool cl = false, cr = false;
        for(l+=n,r+=n;l<r;l/=2,r/=2) {
            if(cl) calc(l-1);
            if(cr) calc(r);
            if(l&1) apply(l++, v), cl=true;
            if(r&1) apply(--r, v), cr=true;
        }
        for(--l;r > 0; l >>= 1, r >>= 1) {
            if(cl) calc(l);
            if(cr && (!cl || l != r)) calc(r);
        }
    }
};

char get() {
    static char buf[1000000], *S=buf, *T=buf;
    if(S==T) {
        T = (S=buf)+fread(buf, 1, 1000000, stdin);
        if(S==T)return EOF;
    }
    return *S++;
}

void read(ll& x) {
    static char c; x = 0;
    for(c=get();c<'0'||c>'9';c=get());
    for(;c>='0'&&c<='9';c=get()) x = x*10+c-'0';
}

const int NMAX = 500500;

int L[NMAX], R[NMAX], mx[NMAX];
vector<int> fr[NMAX];
ll p[NMAX], w[NMAX], ans[NMAX];
vector<int> ch[NMAX];
ll N, Q;

int dfs(int u) {
    int ans = u;
    for(auto& v : ch[u]) {
        ans = max(ans, dfs(v));
    }
    mx[u] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(N);
    read(Q);
    for(int i=2;i<=N;++i) {
        read(p[i]);
        read(w[i]);
        ch[p[i]].push_back(i);
    }
    for(int i=1;i<=Q;++i) {
        ll u, l, r;
        read(u);
        read(l);
        read(r);
        L[i] = l;
        R[i] = r;
        fr[u].push_back(i);
    }
    ll ww = 0;
    stack<int> stk;
    stk.push(1);
    segtree st(N+1);
    for(int i=2;i<=N;++i) {
        while(stk.top() != p[i]) {
            ww -= w[stk.top()];
            stk.pop();
        }
        stk.push(i);
        ww += w[i];
        if(ch[i].size() == 0) {
            st[i] = ww;
        }
    }
    st.build();
    dfs(1);
    for(auto& j : fr[1]) {
        ans[j] = st.query(L[j], R[j]+1);
    }
    stk = stack<int>();
    stk.push(1);
    for(int i=2;i<=N;++i) {
        while(stk.top() != p[i]) {
            int u = stk.top();
            stk.pop();
            st.incr(u, mx[u]+1, w[u]);
            st.incr(1, u, -w[u]);
            st.incr(mx[u]+1, N+1, -w[u]);
        }
        stk.push(i);
        st.incr(i, mx[i]+1, -w[i]);
        st.incr(1, i, w[i]);
        st.incr(mx[i]+1, N+1, w[i]);
        for(auto& j : fr[i]) {
            ans[j] = st.query(L[j], R[j]+1);
        }
    }
    for(int i=1;i<=Q;++i)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}