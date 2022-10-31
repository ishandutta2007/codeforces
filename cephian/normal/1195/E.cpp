#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

// a MIN sliding window
template <class T>
struct sliding_window {
	int ctr = 0, K = -1;
	int f = 0, b = 0, sz = 0;
	vector<pair<T, int>> data;
	void init(int k){
		data.resize(k+1);
		K = k;
		b = 1;
	}
	sliding_window(int k){init(k);}
	sliding_window() {}

	// add an element and return the result for current window
	T add(T nxt) {
		assert(K != -1);
		// flip to below >= for MAX
		while(sz && nxt <= data[f].first) {
			if(--f == -1) f = K;
			--sz;
		}
		if(++f == K+1) f = 0;
		data[f].first = nxt;
		data[f].second = ctr;
		++sz;
		if(data[b].second + K == ctr) {
			if(++b == K+1) b = 0;
			--sz;
		}
		++ctr;
		return data[b].first;
	}
};

const int N = 3005;
int r[N][N];

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, a, b, g, x, y, z;
	cin >> n >> m >> a >> b >> g >> x >> y >> z;
	for(int i = 0; i < n; ++i) {
		sliding_window<int> sw(b);
		for(int j = 0; j < m; ++j) {
			r[i][j] = sw.add(g);
			g = (g * ll(x) + y) % z;
		}
	}
	ll sum = 0;
	for(int j = 0; j < m; ++j) {
		sliding_window<int> sw(a);
		for(int i = 0; i < n; ++i) {
			r[i][j] = sw.add(r[i][j]);
			if(i >= a-1 && j >= b-1)
				sum += r[i][j];
		}
	}
	cout << sum << '\n';
}