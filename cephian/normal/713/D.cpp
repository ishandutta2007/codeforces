#include <bits/stdc++.h>
#pragma COMMENT(linger, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
 
// 2d min range query in O(n*m*log(n)*nlog(m) space, O(1) query
template <class T>
struct rmq_2d {
	vector<vector<vector<vector<T>>>> t;
	rmq_2d(){}
	void init(const int n, const int m) {
		const int logn = 32-__builtin_clz(n);
		const int logm = 32-__builtin_clz(m);
		t.resize(logn, vector<vector<vector<T>>>(logm, vector<vector<T>>(n, vector<T>(m))));
	}
	rmq_2d(int n, int m){init(n, m);}
 
	vector<T>& operator [](int i) {
		return t[0][0][i];
	}
 
	// change me for max query
	inline T combine(T a, T b) {
		return max(a, b);
	}
 
	void build() {
		const int logn = t.size();
		const int logm = t[0].size();
		const int n = t[0][0].size();
		const int m = t[0][0][0].size();
		for(int i = 0; i < logn; ++i) {
			for(int j = 0; j < logm; ++j) {
				if(i == 0 && j == 0) continue;
				for(int k = 0; k < n; ++k) {
					for(int l = 0; l < m; ++l) {
						if(j == 0)
							t[i][j][k][l] = combine(t[i-1][j][k][l], t[i-1][j][min(n-1, k+(1<<(i-1)))][l]);
						else
							t[i][j][k][l] = combine(t[i][j-1][k][l], t[i][j-1][k][min(m-1, l+(1<<(j-1)))]);
					}
				}
			}
		}
	}
 
	// inclusive min query
	T query(int a, int b, int c, int d) {
		const int i = 31-__builtin_clz(c-a+1);
		const int j = 31-__builtin_clz(d-b+1);
		const int dx = (1<<i)-1;
		const int dy = (1<<j)-1;
		T ans  = t[i][j][a][b];
		ans = combine(ans, t[i][j][c-dx][b]);
		ans = combine(ans, t[i][j][a][d-dy]);
		ans = combine(ans, t[i][j][c-dx][d-dy]);
		return ans;
	}
};
 
const int N = 1005;
 
int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, q;
	cin >> n >> m;
	rmq_2d<int> R(n, m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> R[i][j];	
			if(R[i][j] && i > 0 && j > 0)
				R[i][j] = 1+min(R[i-1][j], min(R[i][j-1], R[i-1][j-1]));
		}
	}
	cin >> q;
	R.build();
	for(int i = 0; i < q; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		--a, --b, --c, --d;
		int lo = 0, hi = min(d-b+1, c-a+1)+1;
		while(hi-lo > 1) {
			int md = (lo+hi)/2;
			if(R.query(a+md-1, b+md-1, c, d) >= md)
				lo = md;
			else hi = md;
		}
		cout << lo << '\n';
	}
 
}