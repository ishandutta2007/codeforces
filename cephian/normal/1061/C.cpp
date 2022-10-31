#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int S = 1e6+5;
ll good[S] = {};
vector<int> divs[S];
const int M = 1e9+7;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	for(int i = S-1; i >= 1; --i) {
		for(int j = i; j < S; j += i) {
			divs[j].push_back(i);
		}
	}
	int n;
	cin >> n;
	good[0] = 1;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for(int j : divs[a]) {
			good[j] = (good[j-1] + good[j]) % M;
		}
	}
	ll ans = 0;
	for(ll i = 1; i < S; ++i) {
		ans += good[i];
		ans %= M;
	}
	cout << ans << "\n";
}