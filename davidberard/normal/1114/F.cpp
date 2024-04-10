#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const ll mod = 1000000007;

ll pri[64];
ll ipri[64];
ll fac[350];
ll facf[350][64];
int p;

inline ll modpow(ll b, ll p) {
	ll a = 1;
	while(p) {
		if(p&1) a = (a*b)%mod;
		b=b*b%mod;
		p >>= 1;
	}
	return a;
}

inline ll modppow(ll b, ll lp) {
	if(b <= 300) return facf[b][lp];
	while(lp) {
		b=b*b%mod;
		lp--;
	}
	return b;
}

void setup() {
	for(int i=2;i<=300;++i) {
		bool bad = false;
		for(int j=2;j*j<=i;++j) {
			if(i%j == 0) {
				bad = true; break;
			}
		}
		if(!bad) {
			pri[p] = i;
			ipri[p] = modpow(i, mod-2);
			++p;
		}
	}
	for(int i=0;i<64;++i) {
		facf[0][i] = 0;
		facf[1][i] = 1;
	}
	for(int i=1;i<=300;++i) {
		for(int j=0;j<p;++j) {
			if(i%pri[j] == 0) {
				fac[i] |= (1LL<<j);
			}
		}
		facf[i][0] = i;
		for(int j=1;j<64;++j) {
			facf[i][j] = facf[i][j-1]*facf[i][j-1]%mod;
		}
	}
}

struct node {
	ll prod;
	ll have;
	node() : prod(1), have(0) {}
	node(ll a, ll b) : prod(a), have(b) {}
	inline node operator+ (const node& o) const {
		node a;
		a.prod = o.prod*prod%mod;
		a.have = have|o.have;
		return a;
	}
	inline void operator+= (const node& o) {
		prod = o.prod*prod%mod;
		have |= o.have;
	}
	inline void mult(int v, int lp) {
		have |= fac[v];
		if(v > 300) {
			prod = prod*modpow(v, lp)%mod;
		} else {
			prod = prod*facf[v][lp]%mod;
		}
	}
};

struct segtree {
	vector<node> t;
	vector<node> d;
	vector<node> e;
	int h, n;
	segtree() {}
	segtree(int sz) {
		h = 32 - __builtin_clz(sz);
		n = 1<<h;
		t = vector<node>(n<<1);
		d = vector<node>(n<<1);
		e = vector<node>(n<<1);
	}
	inline void apply(int x, int v) {
		d[x].mult(v, 0);
		e[x].mult(v, h-31+__builtin_clz(x));
		t[x].mult(v, h-31+__builtin_clz(x));
	}
	inline void apply(int x, node v) {
		d[x] += v;
		v.prod = modppow(v.prod, h-31+__builtin_clz(x));
		e[x] += v;
		t[x] += v;
	}
	inline void pushh(int x) {
		if(d[x].have) {
			////cerr << " pushh " << x << " (" << n << ")" << " pushing " << d[x].prod << endl;
			apply(x<<1, d[x]);
			apply(x<<1|1, d[x]);
			d[x].have = 0; d[x].prod = 1;
			e[x].have = 0; e[x].prod = 1;
		}
	}
	inline void push(int i) {
		i+=n;
		for(int l=h;l>0;--l) {
			pushh(i>>l);
		}
	}
	inline void pulll(int x) {
		t[x] = t[x<<1]+t[x<<1|1];
		t[x] += e[x];
	}
	node& operator[] (const int i) {
		return t[i+n];
	}
	void build() {
		for(int i=n-1;i>0;--i) {
			pulll(i);
		}
	}
	void mult(int l, int r, int v) {
		push(l);
		push(r-1);
		bool cl=0, cr=0;
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			//cerr << " -- - " << l << " " << r << endl;
			if(cl) {
				pulll(l-1);
			}
			if(cr) {
				pulll(r);
			}
			if(l&1) {
				apply(l++, v);
				cl = 1;
			}
			if(r&1) {
				apply(--r, v);
				cr = 1;
			}
		}
		for(--l; r>0; l/=2, r/=2) {
			if(cl) pulll(l);
			if(cr && (!cl || l!=r)) pulll(r);
		}
	}
	ll query(int l, int r) {
		push(l);
		push(r-1);
		node c;
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			if(l%2) c += t[l++];
			if(r%2) c += t[--r];
		}
		ll ans = c.prod;
		//////cerr << " c.prod " << c.prod << endl;
		for(int i=0;i<p;++i) {
			if(c.have&(1LL<<i)) {
				//////////cerr << " have " << pri[i] << endl;
				ans =(ans*(pri[i]-1)%mod)*ipri[i]%mod;
			}
		}
		return ans;
	}
};

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S==T) {
        T=(S=buf)+fread(buf, 1, 100000, stdin);
        if(S==T) return EOF;
    }
    return *S++;
}
char cc;
inline void read(int& x) {
    x=0;
    for(cc=get();cc < '0' || cc > '9';cc=get());
    for(;cc >='0' && cc <='9';cc=get()) x = x*10+cc-'0';
   /* for(;c != '\n' && c != EOF && (c < '0' || c > '9') && c != '-';c=get());
    x*=s; */
}
inline void read(char& c) {
	for(cc=get();cc == ' ' || c == '\n';c=get());
	c = cc;
}

int n, q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	setup();
	read(n); read(q);
	segtree st(n+1);
	for(int i=1;i<=n;++i) {
		int a;
		read(a);
		st[i].mult(a, 0);
	}
	st.build();
	////////cerr << "!! " << endl;
	for(int i=1;i<=q;++i) {
		char s;
		read(s);
		if(s == 'T') {
			int l, r;
			read(l); read(r);
			cout << st.query(l, r+1) << "\n";
		} else {
			int l, r, v;
			read(l); read(r); read(v);
			st.mult(l, r+1, v);
		}
	}
	return 0;
}