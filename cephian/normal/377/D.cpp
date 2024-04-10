#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

pii operator+(const pii& a, const pii& b) {
	return make_pair(a.first+b.first, a.second + b.second);
}

pii& operator+=(pii& a, const pii& b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

//range ADD update, range MAX query
template <class T>
struct segt {
	int N,h;
	vector<T> t,d;
	segt();
	segt(int N):N(N),t(2*N),d(N){h = 32 - __builtin_clz(N);}

	T NONE = make_pair(-1e9, -1e9);
	inline static T combine(const T a, const T b) {return max(a,b);}

	inline void apply(int p, T value) {
		t[p] += value;
		if(p < N) d[p] += value;
	}

	inline void build(int p) {
		while(p > 1) {
			p >>= 1;
			t[p] = combine(t[p<<1], t[p<<1|1]) + d[p];
		}
	}

	inline void push(int p) {
		for(int i,s = h; s > 0; --s) {
			if(d[i = p >> s] != make_pair(0, 0)) {
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = make_pair(0,0);
			}
		}
	}

	//[l,r] range update
	inline void update(int l, int r, T value) {
		int l0 = (l += N), r0 = (r += N+1)-1;
		for(; l < r; l >>= 1, r >>= 1) {
			if(l&1) apply(l++, value);
			if(r&1) apply(--r, value);
		}
		build(l0), build(r0);
	}

	// [l,r] range query
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

const int M = 3e5+5;
const int N = 1e5+5;
const int NINF = -1e9;

int l[N], v[N], r[N];
int opi[M] = {};

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	segt<pair<int,int>> S(M);
	for(int i = 0; i < M; ++i) {
		S.update(i, i, make_pair(0, i));
	}

	vector<tuple<int,int,int>> Q;
	for(int i = 0; i < n; ++i) {
		cin >> l[i] >> v[i] >> r[i];
		Q.emplace_back(v[i], 0, i);
		Q.emplace_back(r[i], 1, i);
	}
	sort(Q.begin(), Q.end());
	int ans = 0;
	int vl=0, vr=0;
	for(int i = 0; i < (int)Q.size(); ++i) {
		int loc, t, j;
		tie(loc, t, j) = Q[i];
		int val = S.query(v[j], v[j]).first;
		if(t == 0) {
			S.update(l[j], v[j], make_pair(1, 0));
			++opi[v[j]];
			auto mx = S.query(0, M-1);
			if(mx.first > ans) {
				ans = mx.first;
				vl = mx.second;
				vr = v[j];
			}
		} else {
			S.update(l[j], v[j], make_pair(-1, 0));
			--opi[v[j]];
			if(opi[v[j]] == 0)
				S.update(v[j], v[j], make_pair(NINF, 0));
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; ++i) {
		if(vl <= v[i] && v[i] <= vr && l[i] <= vl && vr <= r[i])
			cout << i+1 << ' ';
	}
	cout << '\n';
}