#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x.size()))
#define all(x) x.begin(), x.end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using ll = long long;

const char nl = '\n';
const int MX = 2e5 + 10;


void solve() {
	int n;
	cin >> n;
	vector<int> vec(11);
	for(int i = 0; i < n; i++) {
		int b, d;
		cin >> b >> d;
		vec[d] = max(vec[d], b);
	}
	int ans = 0;
	for(int i = 1; i <= 10; i++) {
		if(!vec[i]) {
			cout << "MOREPROBLEMS\n";
			return;
		}
		ans += vec[i];
	}
	cout << ans << nl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int te = 1;
	cin >> te;
	while(te--) {
		solve();
	}
}