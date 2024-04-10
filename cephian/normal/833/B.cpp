#include <bits/stdc++.h>
using namespace std;

template <class T>
struct segt {
	int N,h;
	vector<T> t,d;
	segt(){};

	const static T NONE = numeric_limits<T>::lowest();
	inline static T combine(const T a, const T b) {return max(a,b);}

	inline void init(int n) {
		N = n;
		t.resize(2*N), d.resize(N);
		h = 32-__builtin_clz(N);
	}

	inline void apply(int p, T value) {
		t[p] += value;
		if(p < N) d[p] += value;
	}

	inline void build(int p) {
		while(p > 1) p >>= 1, t[p] = combine(t[p<<1], t[p<<1|1]) + d[p];
	}

	inline void push(int p) {
		for(int i,s = h; s > 0; --s) {
			if(d[i = p >> s]) {
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = 0;
			}
		}
	}

	inline void update(int l, int r, T value) {
		int l0 = (l += N), r0 = (r += N+1)-1;
		for(; l < r; l >>= 1, r >>= 1) {
			if(l&1) apply(l++, value);
			if(r&1) apply(--r, value);
		}
		build(l0), build(r0);
	}

	inline T query(int l, int r) {
		push(l += N);
		push((r += N+1) - 1);
		T res = NONE;
		for (; l < r; l >>= 1, r >>= 1) {
			if(l&1) res = combine(res, t[l++]);
			if(r&1) res = combine(t[--r], res);
		}
		return res;
	}
};

const int N = 35005, K = 55;
segt<int> segs[K];
int a[N], lst[N];

int main() {	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int j = 0; j <= k; ++j)
		segs[j].init(n+1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",a+i);
		for(int j = 0; j < k; ++j)
			segs[j].update(lst[a[i]],i-1,1);
		for(int j = 1; j <= k; ++j) {
			segs[j].update(i,i,segs[j-1].query(0,i-1));
		}
		lst[a[i]] = i;
	}
	printf("%d\n",segs[k].query(n,n));
}