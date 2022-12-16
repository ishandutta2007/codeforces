#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template <typename T> struct RMQ {
	int h, n;
	vector<vector<T>> rmq;
	RMQ() {}
	RMQ(int n) : n(n) {
		h = 32 - __builtin_clz(n);
		rmq = vector<vector<T>>(n, vector<T>(h));
	}
	T& operator[] (const int i) {
		return rmq[i][0];
	}
	void build() {
		for(int l=0;l<h-1;++l) {
			for(int i=0;(i+(1<<(l+1)))<=n;++i) {
				rmq[i][l+1] = min(rmq[i][l], rmq[i+(1<<l)][l]);
			}
		}
	}
	T query(int l, int r) {
		int m = 31 - __builtin_clz(r-l);
		return min(rmq[l][m], rmq[r-(1<<m)][m]);
	}
};
struct LCA {
	RMQ<pii> rmq;
	vector<vector<int>> adj;
	vector<int> first, dep;
	int n;
	LCA() {}
	LCA(int n) : n(n), adj(n+1), rmq(2*n+2), first(n+1, 0), dep(n+1, 0) {

	}
	void add_edge(int u, int v) {
		assert(min(u, v) != 0);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	void dfs(int u, int p, int d, int& it) {
		dep[u] = d;
		first[u] = it;
		rmq[it++] = pii(d, u);
		for(auto& v : adj[u]) {
			if(v == p) continue;
			dfs(v, u, d+1, it);
			rmq[it++] = pii(d, u);
		}
	}
	void build(int u) {
		int it=1;
		dfs(u, 0, 1, it);
		rmq.build();
	}
	int query(int u, int v) {
        if(first[u] > first[v]) swap(u, v);
		return rmq.query(first[u], first[v]+1).second;
	}
};

LCA lca;
const int NMAX = 200300;
int P[NMAX];

struct node {
	int a, b;
	node() : a(0), b(0) {}
	node(int a, int b) : a(a), b(b) {}
	inline static bool fit(int x, int y) {
        ////cerr << "  about to query " << x << " " << y << endl;
		int l = lca.query(x, y);
        ////cerr << " fit " << x << " " << y << " " << l << endl;
		return (l == x || l == y);
	}
    /*
    inline static node trymerge(int c, int d, int e, int f) {
        int l = lca.query(c, d);
        if(c == d) {
            l = lca.query(c, e);
            d = l;
        }
        //cerr << "  try merging " << c << "-" << l << "-" << d << " with " << e << " " << f << ":: " << lca.dep.size() << endl;
        if(lca.dep[e] > lca.dep[f]) swap(e, f);
        //cerr << "   " << fit(d, f) << " " << fit(d, e) << " comp " << lca.query(l, e) << " " << l << endl;
        //cerr << "   " << fit(c, f) << " " << fit(c, e) << " comp " << lca.query(l, e) << " " << l << endl;
        if(fit(d, f) && fit(d, e) && lca.query(l, e) == l) {
            return node(c, (lca.dep[f] > lca.dep[d] ? f : d));
        }
        else if(fit(c, f) && fit(c, e) && lca.query(l, e) == l) {
            return node((lca.dep[f] > lca.dep[c] ? f : c), d);
        }
        return node();
    }
    inline static node trymerge(const node& c, const node& d){
        int n = lca.query(d.a, d.b);
        node m = trymerge(c.a, c.b, n, d.a);
        if(m.a == 0) return m;
        return trymerge(m.a, m.b, n, d.b);
    }
	node vmerge(const node& o) const {
        if(a == NMAX) return o;
        if(o.a == NMAX) return *this;
        if(a == 0 || o.a == 0) return node();
        //cerr << "  -- " << endl;
        node n = trymerge(*this, o);
        if(n.a != 0) return n;
        return trymerge(o, *this);
	}
    node merge(const node& o) const {
        node n = vmerge(o);
        //cerr << " merge (" << a << "," << b << ") with (" << o.a << "," << o.b << ") = (" << n.a << "," << n.b << ")" << endl;
        return n;
    }
    */
    static inline node imerge(int x, int y, int z) {
        if(x == 0 || y == 0 || z == 0) return node();
        if(x == NMAX) return node(z, z);
        if(z == NMAX) return node(x, y);
        int d1 = lca.dep[x]+lca.dep[y]-lca.dep[lca.query(x, y)]*2;
        int d2 = lca.dep[x]+lca.dep[z]-lca.dep[lca.query(x, z)]*2;
        int d3 = lca.dep[y]+lca.dep[z]-lca.dep[lca.query(y, z)]*2;
        //cerr << " d1 d2 d3 " << d1 << " " << d2 << " " << d3 << endl;
        if(d1 == d2+d3) return node(x, y);
        if(d2 == d3+d1) return node(x, z);
        if(d3 == d1+d2) return node(y, z);
        return node();
    }
    node merge(const node& o) const {
        node n = imerge(a, b, o.a);
        n = imerge(n.a, n.b, o.b);
        //cerr << " merge (" << a << "," << b << ") and (" << o.a << "," << o.b << ") = (" << n.a << "," << n.b << ")" << endl;
        return n;
    }
};

struct segtree {
	vector<node> t;
	int n, h;
	segtree() {}
	segtree(int sz) {
		h = sizeof(int)*8-__builtin_clz(sz);
		n = 1 << h;
		t = vector<node>(n<<1);
	}
	void insert(int x, node b) {
        ////cerr << " inserting into " << x << "node " << b.a << endl;
		t[x+=n]=b;
		for(x/=2;x>0;x/=2) {
			t[x] = t[x<<1].merge(t[x<<1|1]);
            ////cerr << "####" << t[x].a << " " << t[x].b << endl;
		}
	}
    void build() {
        for(int i=n-1;i>0;--i) {
            t[i] = t[i<<1].merge(t[i<<1|1]);
        }
    }
	int get() {
		node cur = node(NMAX, NMAX), nxt;
		int x=1;
		for(;x<n;) {
			nxt = cur.merge(t[x<<1]);
			if(nxt.a != 0 && nxt.b != 0) {
				x = x*2+1;
				cur = nxt;
			} else {
				x = x*2;
			}
		}
		return x-n;
	}
};

int N;

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S==T) {
        T=(S=buf)+fread(buf, 1, 100000, stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
inline void read(int& x) {
    static char c; x = 0;
    for(c=get();c<'0'||c>'9';c=get());
    for(;c>='0'&&c<='9';c=get()) x = x*10+c-'0';
}

int main () {
	ios_base::sync_with_stdio(0), cin.tie(0);
    read(N);
    lca = LCA(N+2);
    segtree st(N+2);
    for(int i=1;i<=N;++i) {
        read(P[i]);
    }
    for(int i=2;i<=N;++i) {
        int p;
        read(p);
        lca.add_edge(p, i);
    }
    lca.build(1);
    for(int i=1;i<=N;++i) {
        st.t[P[i]+st.n]= node(i,i);
    }
    st.build();
    int Q;
    read(Q);
    for(int q=0;q<Q;++q) {
        int t;
        read(t);
        if(t == 1) {
            int i, j;
            read(i);
            read(j);
            st.insert(P[j], node(i, i));
            st.insert(P[i], node(j, j));
            swap(P[i], P[j]);
        } else {
            cout << st.get() << "\n";
        }
    }
	return 0;
}