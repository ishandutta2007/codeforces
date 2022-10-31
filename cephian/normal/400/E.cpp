#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

//range SET update, point VALUE query
template <class T>
struct segt {
	int N,ctr=1;
	vector<T> t,v;
	
	segt(int N):N(N),t(2*N),v(2*N){}
	//set range [l,r]
	inline void update(int l, int r, T c) {
		for(l+=N,r+=N+1;l<r;l>>=1,r>>=1) {
			if(l&1) t[l]=ctr,v[l++]=c;
			if(r&1) t[--r]=ctr,v[r]=c;
		}
		++ctr;
	}

	//query value at i
	inline int query(int i) const {
		T lv = -1;
		int lt = -1;
		for(i += N; i > 0; i >>= 1)
			if(t[i]>lt) lt=t[i],lv=v[i];
		return lv;
	}
};

inline ll seg(ll a, ll b) {
	return (b-a+1) * (b-a+2) / 2;
}

struct solver {
	segt<int> st, ed;
	vector<bool> arr;
	solver(int n):st(n), ed(n), arr(n) { }

	ll set(int i, bool x) {
		if(arr[i] == x) return 0;
		ll ret = 0;
		if(x) {
			int a = i, b = i;
			if(i > 0 && arr[i-1]) {
				a = st.query(i-1);
				ret -= seg(a, i-1);
			}
			if(i < (int)arr.size()-1 && arr[i+1]) {
				b = ed.query(i+1);
				ret -= seg(i+1, b);
			}
			st.update(a, b, a);
			ed.update(a, b, b);
			ret += seg(a, b);
		} else {
			int a = st.query(i);
			int b = ed.query(i);
			ret -= seg(a, b);
			ed.update(a, i-1, i-1);
			st.update(i+1, b, i+1);
			ret += seg(a, i-1);
			ret += seg(i+1, b);
		}
		arr[i] = x;
		return ret;
	}
};


const int B = 20;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<solver> work(B, solver(n));
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for(int j = 0; j < B; ++j) {
			if(a&(1<<j)) {
				ans += (1LL<<j) * work[j].set(i, 1);
			}
		}
	}
	while(m--) {
		int p, v;
		cin >> p >> v;
		--p;
		for(int j = 0; j < B; ++j) {
			bool x = (v&(1<<j)) != 0;
			ans += (1LL<<j) * work[j].set(p, x);
		}
		cout << ans << '\n';
	}
}