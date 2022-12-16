#include <bits/stdc++.h>
#define nl "\n"


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/**
 * @609F@ Mosquitos and Frogs
 * Segtree.  ith element = farthest position reached by ith frog
 * Segtree stores max xpos in the segment
 * Binary search to find leftmost frog that satisfies this.
 */

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}

inline void read(int& x) {
	static char c; x=0; int sgn=1;
	for(c=get();c<'0' || c>'9';c=get()) if(c=='-') sgn=-1;
	for(;c>='0' && c<='9';c=get()) x = (int) c-'0'+x*10;
	x*=sgn;
}

struct segtree {
	vector<int> t;
	int h, n;
	segtree(vector<int> v) {
		h = sizeof(size_t)*8 - __builtin_clz(v.size()-1);
		n = 1<<h;
		t = vector<int>(n<<1, 0);
		for(int i=0;i<v.size();++i)
			t[i+n] = v[i];
		for(int i=n-1;i>0;--i)
			t[i] = max(t[i<<1],t[i<<1|1]);
	}
	void set(int i, int v) {
		t[i+n] = v;
		for(i=(i+n)/2;i>0;i>>=1) t[i] = max(t[i<<1],t[i<<1|1]);
	}
	int search(int goal) {
		int pos = 1;
		if(t[pos] < goal) return -1;
		while(pos < n) {
			pos *=2;
			if(t[pos] >= goal)
				continue;
			pos++;
		}
		return pos-n;
	}
	// asdf
};

struct frogg {
	int x, t, ind, far;
	bool operator< (const frogg& o) const {
		return x < o.x;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, M;
	read(N);
	read(M);
	vector<frogg> frogs(N);
	vector<int> frogx(N), frogt(N), mcount(N, 0), farthest(N), revind(N);
	for(int i=0;i<N;++i) {
		int a, b, c, d;
		read(a);
		read(b);
		frogs[i] = {a, b, i, a+b};
	} 
	sort(frogs.begin(), frogs.end());
	for(int i=0;i<N;++i) {
		frogx[i] = frogs[i].x;
		frogt[i] = frogs[i].t;
		farthest[i] = frogs[i].far;
		revind[frogs[i].ind] = i;
	}
	segtree st(farthest);

	map<int, vector<int>> leftovers;

	int p, b;
	for(int i=0;i<M;++i) {
		read(p);
		read(b);
		int mn = st.search(p);
		if(mn == -1) {
			if(leftovers.count(p) == 0)
				leftovers[p] = vector<int>();
			leftovers[p].push_back(b);
		}
		else {
			if(frogx[mn] > p) {
				if(leftovers.count(p) == 0)
					leftovers[p] = vector<int>();
				leftovers[p].push_back(b);
				continue;
			}
			frogt[mn] += b;
			++mcount[mn];
			for(auto it = leftovers.lower_bound(frogx[mn]+frogt[mn]-b);
					it != leftovers.end() && it->first <= frogx[mn]+frogt[mn];
					it = leftovers.erase(it))
			{
				for(auto pp : it->second) {
					frogt[mn] += pp;
					++mcount[mn];
				}

			}
			st.set(mn, frogx[mn] + frogt[mn]);
		}
	}

	for(int i=0;i<N;++i) {
		cout << mcount[revind[i]] << " " << frogt[revind[i]] << nl;
	}
	

	return 0;
}