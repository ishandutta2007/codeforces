#include <bits/stdc++.h>
#define nl "\n"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline char get(void) {
        static char buf[100000], *S = buf, *T = buf;
            if (S == T) {
                        T = (S = buf) + fread(buf, 1, 100000, stdin);
                                if (S == T) return EOF;
                                    }
                                        return *S++;
}
inline void read(int &x) {
        static char c; x = 0; int sgn = 0;
            for (c = get(); c < '0' || c > '9'; c = get()) if (c == '-') sgn = 1;
                for (; c >= '0' && c <= '9'; c = get()) x = x * 10 + c - '0';
                    if (sgn) x = -x;
}

struct segtree{
	vector<int> t;
	int n, h;
	segtree(const vector<int>& a) {
		int sz = a.size();
		h = sizeof(int)*8 - __builtin_clz(sz-1);
		n = 1<<h;
		t = vector<int> (n<<1);
		for(int i=0;i<sz;++i)
			t[i+n] = a[i];
		for(int i=n-1;i>0;--i) {
			t[i] = __gcd(t[i<<1], t[i<<1|1]);
			//cerr << i << ": " << t[i] << endl;
		}
	}

	void set(int pos, int val) {
		t[pos+n] = val;
		for(pos=(pos+n)/2;pos>0;pos/=2) t[pos] = __gcd(t[pos<<1], t[pos<<1|1]);
	}

	bool isAlmostSpecial(int sg, int guess) {
		//cerr << "ias " << sg << " val " << t[sg]  <<", guess " << guess;
		//cerr;if(sg < n)
			//cerr << ": " << t[sg<<1] << " " << t[sg<<1|1];
		//cerr << endl;
		if (t[sg]%guess == 0 || sg >= n)
			return true;
		//cerr << "continue" << endl;

		if(t[sg<<1]%guess == 0) {
			//cerr << 'a' << endl;
			return isAlmostSpecial(sg<<1|1, guess);
		}
		else if(t[sg<<1|1]%guess == 0) {
			//cerr << 'b' << endl;
			return isAlmostSpecial(sg<<1, guess);
		}
		return false;
	}

	bool isAlmost(int l, int r, int guess) {
		int bad = -1;
		int cnt = 0;
		//cerr << "n=" <<  n << endl;
		for(l+=n, r+=n; l<r;l>>=1, r>>=1) {
			if(l%2 && t[l++]%guess != 0) {
				if(bad != -1) return false;
				bad = l-1;
				//cerr << "SET TO " << bad << " L " << " L=" << l << endl;
			}
			if(r%2 && t[--r]%guess != 0) {
				if(bad != -1) return false;
				bad = r;
				//cerr << "SET TO " << bad << " R " << endl;
			}
		}
		if(bad == -1) return true;
		return isAlmostSpecial(bad, guess);
	}


};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N;
	read(N);
	vector<int> a(N);
	for(int &ii: a) read(ii);
	segtree st(a);
	int Q;
	read(Q);
	int type, l, r, x, i;
	for(int q=0;q<Q;++q) {
		read(type);
		if(type == 1) {
			read(l);read(r);read(x);
			--l;
			if(st.isAlmost(l, r, x)) cout << "YES" << nl;
			else cout << "NO" << nl;
		} else if(type == 2) {
			read(i);read(x);
			st.set(i-1, x);
		}

	}



	return 0;
}