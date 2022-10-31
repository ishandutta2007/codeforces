#include<bits/stdc++.h>
#define NN 100100
using namespace std;

using ll = long long;
using pii = pair <int, int>;

vector <pii> vec[NN];

int main() {
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			int c; scanf("%d", &c);
			vec[c].push_back(pii(i, j));
		}
	}
	ll ans = 0;
	for(int c = 1; c < NN; c ++) {
		vector <int> buf[2];
		for(auto p : vec[c]) {
			buf[0].push_back(p.first);
			buf[1].push_back(p.second);
		}
		for(int j = 0; j < 2; j ++) {
			sort(buf[j].begin(), buf[j].end());
			ll sum = 0;
			for(int k = 0; k < buf[j].size(); k ++) {
				ans += 1LL * k * buf[j][k];
				ans -= sum;
				sum += buf[j][k];
			}
		}
	}
	cout << ans << endl;
}