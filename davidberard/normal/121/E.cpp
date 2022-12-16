#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define nl endl
#ifdef ONLINE_JUDGE
#define nl '\n'
#endif

int NMAX = 100100;
int nxt[10100];
int tpow[] = {1, 10, 100, 1000, 10000};

void buildnxt() {
	vector<int> gv;
	for(int i=1;i<5;++i) {
		for(int j=0;j<(1<<i);++j) {
			int val = 0;
			for(int k=0;k<i;++k) {
				val += (((1<<k)&j) ? 7 : 4)*tpow[k];
			}
			gv.push_back(val);
		}
	}
	for(int i=0;i<gv.size()-1;++i) {
		for(int j=gv[i]+1;j<gv[i+1];++j) {
			nxt[j] = gv[i];
		}
		nxt[gv[i]] = gv[i+1];
	}
	nxt[0] = 4;
	nxt[1] = 0;
	nxt[2] = 0;
	nxt[3] = 0;
	nxt[7777] = 10010;
	for(int i=7778;i<10010;++i) {
		nxt[i] = 7777;
	}
}

struct state {
	int val;
	int mindiff;
	int cnt;
	state() : val(0), mindiff(1e5), cnt(0) {}
	state(int a, int b, int c) : val(a), mindiff(b), cnt(c) {}
	state operator+(const state& o) const {
		int md, ct;
		if(mindiff == o.mindiff) {
			return state(0, mindiff, o.cnt+cnt);
		}
		else if(mindiff < o.mindiff) {
			return state(0, mindiff, cnt);
		}
		return state(0, o.mindiff, o.cnt);
	}
	void add(int amt) {
		mindiff += amt;
	}
};

struct segtree {
	vector<state> t;
	vector<int> d;
	int n,h;
	segtree() {}
	segtree(int sz) {
		h = 32 - __builtin_clz(sz);
		n = 1 << h;
		t = vector<state>(n<<1);
		d = vector<int>(n<<1, 0);
	}
	void print() const {
        /*
		for(int i=0;i<n*2;++i) {
			////cerr << " ({" << t[i].val << "," << t[i].mindiff << "," << t[i].cnt << "}," << d[i] << ")\t";
		}
		////cerr << endl;
        */
	}
	void build() {
		for(int i=n-1;i>0;--i) {
			t[i] = t[i<<1]+t[i<<1|1];
			//////cerr << " " << i << ": " << t[i].mindiff << " " << t[i].cnt << endl;
		}
	}
	void set(int i, int v) {
		t[i+n].val = v;
		t[i+n].cnt = 1;
		if(nxt[v] > v) {
			t[i+n].mindiff = 0;
		} else {
			t[i+n].mindiff = nxt[nxt[v]]-v;
		}
		//////cerr << " " << i << " " << t[i+n].mindiff << " " << t[i+n].cnt << endl;
	}
	void pushh(int x) {
		if(d[x] == 0) return;
		d[x<<1] += d[x];
		t[x<<1].add(-d[x]);
		d[x<<1|1] += d[x];
		t[x<<1|1].add(-d[x]);
		d[x] = 0;
	}
	void push(int i) {
		i+=n;
		for(int l=h;l>0;l--) {
			pushh(i>>l);
		}
	}
	void pulll(int x) {
		assert(d[x] == 0);
		t[x] = t[x<<1]+t[x<<1|1];
        //t[x].add(-d[x]);
	}
	void pull(int i) {
		for(i=(i+n)/2;i>0;i/=2) {
			pulll(i);
		}
	}
	state query(int l, int r) {
		state ans;
		int l0=l, r0=r;
		push(l0);
		push(r0-1);
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
			if(l&1) {
				ans = ans + t[l++];
			}
			if(r&1) {
				ans = ans + t[--r];
			}
		}
		return ans;
	}
	void upd(int x) {
        //////cerr << "try upd " << x << " with mindiff " << t[x].mindiff << endl;
		if(t[x].mindiff != 0) return;
        //////cerr << " .. upd " << x << endl;
		if(x >= n) {
            //////cerr << " .. x " << endl;
            t[x].val += d[x];
            ////cerr << " want to change t[x].val to " << nxt[t[x].val] << " from " << t[x].val << ", dx was " << d[x] << endl;
			d[x] = 0;
			assert(nxt[t[x].val] > t[x].val);
			t[x].mindiff = nxt[t[x].val]-t[x].val;
			////cerr << " " << t[x].mindiff << " " << t[x].val << endl;
			return;
		}
		pushh(x);
		upd(x<<1);
		upd(x<<1|1);
		pulll(x);
	}
	void upd(int l, int r) {
		push(l);
		push(r-1);
		push(l-1);
		push(r);
		int l0 = l, r0 = r;
        //////cerr << "   GOING TO UPD " << l << " " << r << endl;
        bool cl=false, cr=false;
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
            if(cl) {
				pulll(l-1);
            }
            if(cr) {
                pulll(r);
            }
			if(l&1) {
                //////cerr << ".. " << l << " .." << endl;
				upd(l++);
                cl=true;
			}
			if(r&1) {
                //////cerr << ".. " << r-1 << " .." << endl;
                upd(--r);
                cr=true;
            }
		}
		pull(l0-1);
		pull(r0);
	}
	void apply(int l, int r, int dd) {
		int l0=l, r0=r;
		push(l0);
		push(r0-1);
		push(l0-1);
		push(r0);
		bool cl = false, cr = false;
		for(l+=n,r+=n;l<r;l/=2,r/=2) {
			if(cl) {
				print();
				pulll(l-1);
			}
			if(cr) {
				print();
				pulll(r);
			}
			if(l&1) {
				d[l] += dd;
				t[l].mindiff -= dd;
				assert(t[l].mindiff >= 0);
				++l;
				cl = true;
			}
			if(r&1) {
				--r;
				d[r] += dd;
				t[r].mindiff -= dd;
				assert(t[r].mindiff >= 0);
				cr = true;
			}
		}
		for(--l;r>0;l/=2,r/=2) {
			if(cl) pulll(l);
			if(cr && (!cl || (r != l))) pulll(r);
		}
	}
};

int N, M;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	buildnxt();
	cin >> N >> M;
	segtree st(N+1);
	for(int i=1;i<=N;++i) {
		int u;
		cin >> u;
		st.set(i, u);
	}
	st.build();
	////////cerr << "built" << endl;
	string s;
	for(int i=0;i<M;++i) {
		int l, r, d;
		cin >> s;
		if(s[0] == 'c') {
			int l, r;
			cin >> l >> r;
			state a = st.query(l, r+1);
			cout << (a.mindiff ? 0 : a.cnt) << nl;
		} else {
			cin >> l >> r >> d;
			//cerr << "about to delt  " << l << " " << r << endl;
			st.print();
			while(d > 0) {
				st.print();
                st.upd(l, r+1);
				state a = st.query(l, r+1);
				if(a.mindiff) {
					int nd = min(a.mindiff, d);
					//cerr << " increment by " << nd << endl;
					st.apply(l, r+1, nd);
                    st.print();
					d -= nd;
				} else {
                    assert(false);
                }
			}
            st.print();
		}
	}
	return 0;
}