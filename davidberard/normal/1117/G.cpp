#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 1000100;
int l[NMAX], r[NMAX], a[NMAX];
ll ans[NMAX];
vector<int> lh[NMAX], rh[NMAX];
ll n, q;

struct segtree {
	vector<ll> t, d;
	int h, n;
	segtree() {}
	segtree(int sz) {
		h = 32 - __builtin_clz(sz);
		n = 1<<h;
		t = vector<ll>(n<<1, 0);
		d = vector<ll>(n<<1, 0);
	}
	void apply(int x, ll v) {
		d[x] += v;
		t[x] += v*(1<<(h-31+__builtin_clz(x)));
	}
	void pushh(int x) {
		if(d[x]) {
			apply(x<<1, d[x]);
			apply(x<<1|1, d[x]);
			d[x] = 0;
		}
	}
	void push(int i) {
		i+=n;
		for(int l=h;l>0;--l) {
			pushh(i>>l);
		}
	}
	void pulll(int x) {
		t[x] = t[x<<1]+t[x<<1|1] + d[x]*(1<<(h-31+__builtin_clz(x)));
	}
	void set(int l, int r) {
		if(l >= r) return;
		push(l);
		push(r-1);
		bool cl=0, cr = 0;
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			if(cl) {
				pulll(l-1);
			}
			if(cr) {
				pulll(r);
			}
			if(l%2) {
				apply(l++, 1);
				cl = 1;
			}
			if(r%2) {
				apply(--r, 1);
				cr = 1;
			}
		}
		for(--l;r>0;l/=2, r/=2) {
			if(cl) pulll(l);
			if(cr && (!cl || r != l)) pulll(r);
		}
	}
	ll query(int l, int r) {
		push(l);
		push(r-1);
		ll ans = 0;
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			if(l%2) {
				ans += t[l++];
			}
			if(r%2) {
				ans += t[--r];
			}
		}
		return ans;
	}
};

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S==T) {
        T = (S=buf) + fread(buf, 1, 100000, stdin);
        if(S==T)return EOF;
    }
    return *S++;
}

template <typename T>
inline void read(T& x) {
    static char c; x = 0;
    for(c=get();c<'0'||c>'9';c=get());
    for(;c>='0'&&c<='9';c=get()) x = x*10+c-'0';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	read(n); read(q);
	for(int i=1;i<=n;++i) {
		read(a[i]);
	}
	for(int i=1;i<=q;++i) {
		read(l[i]);
		lh[l[i]].push_back(i);
	}
	for(int i=1;i<=q;++i) {
		read(r[i]);
		rh[r[i]].push_back(i);
	}
	segtree st(n+2);
	a[0] = NMAX;
	vector<int> s(n+2); int sit = -1;
	s[++sit] = 0;
	for(int i=1;i<=n;++i) {
		while(a[s[sit]] < a[i]) --sit;
		//cerr << " " << s.top() << " -- " << i << endl;
		st.set(s[sit]+1, i);
		for(auto& j : rh[i]) {
			ans[j] += st.query(l[j], i);
		}
		s[++sit] = i;
	}
	st = segtree(n+1);
	a[n+1] = NMAX;
	s[sit] = n+1;
	for(int i=n;i>0;--i) {
		while(a[s[sit]] < a[i]) sit--;
		//cerr << " " << s.top() << " -- " << i << endl;
		st.set(i+1, s[sit]);
		for(auto& j : lh[i]) {
			ans[j] += st.query(i, r[j]+1);
		}
		s[++sit] = i;
	}

	for(int i=1;i<=q;++i) {
		cout << ans[i] + r[i] - l[i] + 1 << " ";
	}
	cout << endl;


	return 0;
}