#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/* State stores, for a non-decreasing (abreviated "increasing") subsequence
 *  -> total =  longest total subsequence which is increasing
 *  -> lstart = longest starting with 4 on the  leftmost element
 *  -> lend =   longest starting with 7 on the  leftmost element
 *  -> rstart = longest starting with 4 on the rightmost element
 *  -> rend =   longest starting with 7 on the rightmost element
 *
 * For non-increasing, swap 4 and 7 (e.g. "lstart" = the start of a subsequence,
 *   which is 4 for increasing, 7 for decreasing). The reason for the "start"
 *   and "end" instead of just "4" and "7" is to allow for easy "flip" operations
 *   which only require swapping the increasing and decreasing state stores
 */
struct state {
	int total, rtotal, ss, se, es, ee, size;
	state() : total(0), rtotal(0), ss(0), es(0), se(0), ee(0), size(0) {}
	inline static state build (const char& c) {
		state s; s.total = 1, s.rtotal = 1, s.size = 1;
		if(c == '4') {
			s.ss = 1;
		} else {
			s.ee = 1;
		}
		return s;
	}
	void flip() {
		swap(total, rtotal);
		swap(ss, ee);
		swap(se, es);
	}
};

inline state merge(const state& l, const state& r) {
	state s;
	s.size = l.size + r.size;
	s.total = max(l.total, r.total);
	s.total = max(s.total, l.ss + max(max(r.ss, r.se), r.ee));
	s.total = max(s.total, max(l.se, l.ee) + r.ee);

	s.rtotal = max(l.rtotal, r.rtotal);
	s.rtotal = max(s.rtotal, l.ee + max(max(r.ee, r.es), r.ss));
	s.rtotal = max(s.rtotal, max(l.es, l.ss) + r.ss);

	s.ss = l.ss + r.ss;
	s.se = max(max(l.ss+r.se, l.ss+r.ee), l.se + r.ee);
	s.es = max(max(l.ee+r.es, l.ee+r.ss), l.es + r.ss);
	s.ee = l.ee + r.ee;
	return s;
}

ostream& operator << (ostream& os, const state& s) {
	os << "(";
	os << s.total << "," << s.ss << "," << s.se << "," << s.ee << "," << s.size;
	os << ")";
	return os;
}

struct segtree {
	vector<state> t;
	vector<int> d;
	int h, n;
	segtree( const string& s ) {
		int sz = s.size();
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1 << h;
		d = vector<int>(n<<1, 0);
		t = vector<state>(n<<1);
		for(int i=0;i<s.size();++i) {
			t[i+n] = state::build(s[i]);
		}
		for(int i=n-1;i>0;--i) {
			t[i] = merge(t[i<<1], t[i<<1|1]);
		}
	}

	void build(int x) {
		for(x/=2; x>0;x/=2) {
			//cerr << "X = " << x << "\n";
			t[x] = merge(t[x<<1], t[x<<1|1]);
			//cerr << "  INC " << t_inc[x<<1] << " + " << t_inc[x<<1|1] << " = " << t_inc[x] << "\n";
			//cerr << "  DEC " << t_dec[x<<1] << " + " << t_dec[x<<1|1] << " = " << t_dec[x] << "\n";
		}
	}

	void apply(int x) {
		d[x] ++;
		//cerr << "  apply " << x << " vs " << t_inc.size() << ", " << t_dec.size() << "\n";
		t[x].flip();
	}

	void push(int x) {
		for(int s=h;s>0;--s) {
			int i = x>>s;
			////cerr << "TRYING " << i << "-> " << i*2 << ", " << i*2+1 << " of " << t_inc.size() << "\n";
			if(d[i]%2) {
				d[i] = 0;
				apply(i<<1  );
				apply(i<<1|1);
			}
		}
	}

	void flip(int l, int r) {
		int l0 = l+n;
		int r0 = r+n;
		//push(l0), push(r0-1);
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			if(l%2) apply(l++);
			if(r%2) apply(--r);
		}
		//cerr << "Ready to push and build" << "\n";
		push(l0), push(r0-1);
		//cerr << "pushed, gotta build" << "\n";
		build(l0), build(r0-1);
		//cerr << ".." << "\n";
	}

	int query() {
		return t[1].total;
	}
};

char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(S, 1, 100000, stdin);
		if(S == T) return EOF;
	}
	return *S++;
}

void read(string& s) {
	static char tbuf[1000100];
	char c;
	for(c = get(); c == '\n' || c == ' '; c=get());
	int i = 0;
	for(; c != '\n' && c != ' ';c=get(),++i) tbuf[i] = c;
	tbuf[i] = 0;
	s.assign(tbuf);
}

void read(int& x) {
	char c;
	x = 0;
	for(c = get(); c<'0' || c>'9'; c=get());
	for(; c>='0' && c <= '9'; c=get()) x = x*10+c-'0';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q; read(N); read(Q);
    string s; read(s);
    segtree st(s);
    for(int qq=0;qq<Q;++qq) {
        string op; read(op);
        if(op[0] == 'c') {
            cout << st.query() << "\n";
        } else {
            int l, r; read(l); read(r);
            st.flip(l-1, r);
        }
    }
	return 0;
}