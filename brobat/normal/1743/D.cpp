#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 5;
const int M = 1005;

bool compare(bitset<M> &a, bitset<M> &b) {
	// true if a > b.
	for(int i = M - 1; i >= 0; i--) {
		if(a[i] > b[i]) return true;
		if(a[i] < b[i]) return false;
	}
	return false;
}

bool compare(bitset<N> &a, bitset<N> &b) {
	// true if a > b.
	for(int i = N - 1; i >= 0; i--) {
		if(a[i] > b[i]) return true;
		if(a[i] < b[i]) return false;
	}
	return false;
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	#ifdef LOCAL
	cin >> t;
	#endif
	while(t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		if(n <= 1005) {
			bitset<M> f;
			f.reset();
			for(int i = 0; i < n; i++) {
				if(s[i] == '1') {
					f.set(M - i - 1);
				}
			}
			vector<bitset<M>> b(M, f);
			for(int i = 0; i < M; i++) {
				b[i] >>= i;
				b[i] |= f;
			}
			bitset<M> mx;
			mx.reset();
			for(int i = 0; i < M; i++) {
				if(compare(b[i], mx)) {
					mx = b[i];
				}
			}
			bool one = false;
			for(int i = 0; i < n; i++) {
				if(!one) {
					if(mx[M - i - 1]) {
						one = true;
					} else continue;
				}
				cout << mx[M - i - 1];
			}
			if(!one) cout << 0;
			cout << '\n';
			continue;
		}
		vector <int> z;
		int first = -1;
		for(int i = 0; i < n; i++) {
			if(s[i] == '0') z.push_back(i);
		}
		for(int i = 1; i < (int)z.size(); i++) {
			z[i] -= z.front();
		}
		first = z.front();
		z[0] = 0;
		int m = min(15, (int)z.size());
		vector<vector<int>> v(m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(s[i + z[j]] == '1') {
					v[j].push_back(i);
					// cout << j << ' ' << i << '\n';
				} else break;
			}
		}
		reverse(v.begin(), v.end());
		vector <int> cmp;
		for(int i = 0; i < m; i++) {
			if(!v[i].empty()) {
				cmp = v[i];
				break;
			}
		}
		cmp.clear();
		for(int i = 0; i < min(50, n); i++) cmp.push_back(i);
		bitset<N> f;
		f.reset();
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') {
				f.set(N - i - 1);
			}
		}
		bitset<N> ans = f;
		for(auto i : cmp) {
			bitset<N> temp = f;
			temp >>= i;
			// temp <<= i;
			// temp >>= first;
			temp |= f;
			if(compare(temp, ans)) {
				ans = temp;
			}
		}
		bool one = false;
		for(int i = 0; i < n; i++) {
			if(!one) {
				if(ans[N - i - 1]) {
					one = true;
				} else continue;
			}
			cout << ans[N - i - 1];
		}
		if(!one) cout << 0;
		cout << '\n';
	}
	
	return 0;
}