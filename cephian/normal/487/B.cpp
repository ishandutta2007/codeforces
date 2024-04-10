#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

// O(n log n) space, O(1) query RMQ
struct rMq {
	vector<vector<int> > t;
	rMq(){}
	void init(int* a, int n) {
		t.resize(32-__builtin_clz(n),vector<int>(n));
		for(int i = 0; i < n; ++i)
			t[0][i] = a[i];
		for(int k = 1, p = 1; k < (int)t.size(); ++k, p<<=1)
			for(int i = 0; i < n; ++i)
				t[k][i] = (i+p<n)?max(t[k-1][i],t[k-1][i+p]):t[k-1][i];
	}
	rMq(int* a, int n) {init(a,n);}
	//inclusive max query
	inline int query(int l, int r) const {
		int p = 31-__builtin_clz(r-l+1);
		return max(t[p][l],t[p][r+1-(1<<p)]);
	}
};


// O(n log n) space, O(1) query RMQ
struct rmq {
	vector<vector<int> > t;
	rmq(){}
	void init(int* a, int n) {
		t.resize(32-__builtin_clz(n),vector<int>(n));
		for(int i = 0; i < n; ++i)
			t[0][i] = a[i];
		for(int k = 1, p = 1; k < (int)t.size(); ++k, p<<=1)
			for(int i = 0; i < n; ++i)
				t[k][i] = (i+p<n)?min(t[k-1][i],t[k-1][i+p]):t[k-1][i];
	}
	rmq(int* a, int n) {init(a,n);}
	//inclusive min query
	inline int query(int l, int r) const {
		int p = 31-__builtin_clz(r-l+1);
		return min(t[p][l],t[p][r+1-(1<<p)]);
	}
};

//point SET update, range MIN query
template <class T>
struct segt {
	int N;
	vector<T> t,m;
	segt(int N):N(N),t(2*N){}

	constexpr static T NONE = numeric_limits<T>::max(); //min()
	static inline T combine(T a, T b) {return min(a,b);}

	//update point i
	void update(int i, T val) {
		for(t[i+=N] = val;i>1;i>>=1)
			t[i>>1] = combine(t[i],t[i^1]);
	}

	//query range [l,r]
	T query(int l, int r) const {
		T ans = NONE;
		for(l+=N,r+=N+1;l<r;l>>=1,r>>=1) {
			if(l&1) ans = combine(ans,t[l++]);
			if(r&1) ans = combine(ans,t[--r]);
		}
		return ans;
	}
};

const int N = 1e5+5;
int a[N];
int dp[N];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, s, l;
	cin >> n >> s >> l;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	rMq mx(a, n+1);
	rmq mn(a, n+1);
	segt<ll> dp(n+1);
	dp.update(0, 0);
	for(int i = 1; i <= n; ++i) {
		const int r = i-l+1;

		int lo = 0, hi = i;
		while(hi-lo > 1) {
			int md = (hi+lo)/2;
			if(mx.query(md, i) - mn.query(md, i) <= s)
				hi = md;
			else lo = md;
		}
		const int l = hi;
		if(r < l) dp.update(i, 1LL<<50);
		else {
			dp.update(i, dp.query(l-1, r-1)+1);
		}
	}
	const ll ans = dp.query(n, n);
	if(ans >= (1LL<<50)) cout << "-1\n";
	else cout << ans << "\n";
}