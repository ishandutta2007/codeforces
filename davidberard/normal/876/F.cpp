#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct segtree {
	vector<int> tbit, tmax;
	vector<int> dbit, dmax;
	int h, n;
	segtree(int sz) {
		h = sizeof(int)*8 - __builtin_clz(sz);
		n = 1 << h;
		tbit = vector<int>(n<<1, 0);
		tmax = vector<int>(n<<1, 0);
		dbit = vector<int>(n<<1, 0);
		dmax = vector<int>(n<<1, 0);
	}
	void apply(int x, int v, int w) {
		dbit[x] |= v;
		tbit[x] |= v;
		dmax[x] = max(dmax[x], w);
		tmax[x] = max(tmax[x], w);
	}
	void push_at(int s) {
		if(dbit[s] || dmax[s]) {
			apply(s<<1, dbit[s], dmax[s]);
			apply(s<<1|1, dbit[s], dmax[s]);
			dbit[s] = 0;
			dmax[s] = 0;
		}
	}
	void push(int x) {
		for(int p=h;p>0;--p) {
			int s = x>>p;
			push_at(s);
		}
	}
	void pull(int x) {
		for(x/=2;x>0;x/=2) {
			tmax[x] = max(tmax[x], max(tmax[x<<1], tmax[x<<1|1]));
			tbit[x] |= (tbit[x<<1] | tmax[x<<1|1]);
		}
	}
	/*
	void set_bit(int l, int r, int v) {
		int l0 = l+n, r0 = r+n;
		push(l0); push(r0-1);
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			if(l%2) apply_bit(l++, v);
			if(r%2) apply_bit(--r, v);
		}
		pull(l0); pull(r0-1);
	}
	*/
	void set_vals(int l, int r, int v) {
		int l0 = l+n, r0 = r+n;
		push(l0); push(r0-1);
		for(l+=n, r+=n;l<r;l/=2, r/=2) {
			if(l%2) {
				apply(l++, v, v);
			}
			if(r%2) {
				apply(--r, v, v);
			}
		}
		pull(l0); pull(r0-1);
	}
	pii find_max_above(int v) {
		if(tmax[1] <= v) return pii(-1, 0);
		int x = 1;
		while(x < n) {
			push_at(x);
			x*=2;
			if(tmax[x+1] <= v) continue;
			++x;
		}
		return pii(x-n, tmax[x]);
	}
	pii find_bit_above(int v) {
		if(tbit[1] <= v) return pii(-1, 0);
		int x = 1;
		while(x < n) {
			push_at(x);
			x*=2;
			if(tbit[x+1] <= v) continue;
			++x;
		}
		return pii(x-n, tbit[x]);
	}
	int query_bit(int x) {
		x += n;
		push(x);
		return tbit[x];
	}
	int query_max(int x) {
		x += n;
		push(x);
		return tmax[x];
	}

};

char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S == T) {
		T=(S=buf) + fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}

void read(int& x) {
	static char c;
	x = 0;
	for(c=get();c<'0' || c > '9';c=get());
	for(;c >= '0' && c <= '9';c=get()) x = 10*x + (c-'0');
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	//vector<pii> bits_seen; // location where bit is set, bit # which was set
	vector<int> bits_seen(32);
	vector<pii> max_found;

	int N;
	read(N);

	ll ans = 0;
	int set_bits = 0;
	int unset_bits = (1<<30)-1;

	segtree st(N);

	for(int i=0;i<N;++i) {
		int v;
		read(v);
		st.set_vals(0, i+1, v);
		int pos = i;
		//cerr; for(int j=0;j<=i;++j) {
			//cerr << st.query_max(j) << " ";
		//cerr; }
		//cerr << endl;
		//cerr; for(int j=0;j<=i;++j) {
			//cerr << st.query_bit(j) << " ";
		//cerr; }
		//cerr << endl;
		int max_at = v;
		while(pos >= 0) {
			int bi = pos, mi = pos;
			int M = max_at;
			if(M == -1) break;
			pii bpair = st.find_bit_above(M);
			int bf = bpair.first;
			int B = bpair.second;
			//////cerr << " bf = " << bf << endl;
			if(bf == -1) break;
			pii mpair = st.find_max_above(B-1);
			int mf = mpair.first;
			max_at = mpair.second;
			//cerr << "  pos = " << pos << ", M = " << M << ", mf = " << mf << " has value " << st.query_max(mf) << " which is above " << st.query_bit(bf)-1 << endl;
			//////cerr << " mf = " << mf << endl;
			//if(mf == -1) break;
			if(mf < min(bf, pos)) {
				ans += min(bf, pos)-mf;
				//cerr << "[" << mf+1 << " " << bf << "] to " << i << endl;
			}
			pos = mf;
		}
		//////cerr << " -- " << endl;
		/*
		for(int j=0;j<=i;++j) {
			cout << "(" << st.query_bit(j) << " " << st.query_max(j) << ") ";
		}
		cout << endl;
		*/
	}
	cout << ans << endl;


	


	return 0;
}