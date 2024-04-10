#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 5005;
ll dp[N][N];
ll a[N];

template <class T>
struct sliding_max {
	int n, ctr = 0;
	deque<pair<T,int>> Q;
	void init(int window) {n = window;}
	sliding_max(int window) {init(window);}

	void add(T a) {
		while(Q.size() && Q.back().first <= a) {
			Q.pop_back();
		}
		Q.emplace_back(a, ++ctr);
	}

	T max() {
		assert(!Q.empty());
		while(Q.front().second <= ctr - n) {
			Q.pop_front();
		}
		return Q.front().first;
	}
};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, k, x;
	cin >> n >> k >> x;

	for(int i = 1; i <= n; ++i)
		cin >> a[i];

	const ll INF = (1LL<<60);

	fill(dp[0], dp[0]+N, -INF);
	dp[0][0] = 0;

	for(int chose = 1; chose <= x; ++chose) {
		sliding_max<ll> sm(k);
		sm.add((chose == 1) ? 0 : -INF);
		for(int l = 1; l <= n; ++l) {
			dp[chose][l] = sm.max() + a[l];
			sm.add(dp[chose-1][l]);
		}
	}
	ll ans = -INF;
	for(int l = n-k+1; l <= n; ++l)
		ans = max(ans, dp[x][l]);
	
	if(ans < 0) cout << "-1\n";
	else cout << ans << "\n";
}