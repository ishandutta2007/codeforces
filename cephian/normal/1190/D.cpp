#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

//compressed fenwick tree, 0-indexed
template <class T>
struct cmp_bit {
	int N;
	unordered_map<ll,T> b{{0,0}};

	void init(ll n){N=n+1;}
	cmp_bit(){}
	cmp_bit(ll n){init(n);}

	inline void update(ll i, T v) {
		for(++i;i < N; i += i&-i)
			b[i] += v;
	}

	//sum of the first i values
	inline T prefix(ll i) {
		T a = 0;
		for(;i;i ^= i&-i)
			a += b[i];
		return a;
	}

	inline T query(ll l, ll r) {
		return prefix(r+1)-prefix(l);
	}
};

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;


	constexpr int MX = 2e9;
	cmp_bit<int> fen(MX);
	map<int, vector<int>> Q;

	for(int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		Q[y].push_back(x);
	}
	ll ans = 0;

	for(auto it = Q.rbegin(); it != Q.rend(); ++it) {
		sort(it->second.begin(), it->second.end());
		for(int x : it->second) {
			if(fen.query(x,x) == 0) {
				fen.update(x, 1);
			}
		}
		int prev = -1;
		for(int x : it->second) {
			ll as = fen.query(prev+1, x);
			ll bs = fen.query(x, MX);
			ans += as * bs;
			prev = x;
		}
	}
	cout << ans << '\n';
}