#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
 
using namespace std;
 
vector<int> profit(6);
 
const int N = 1000007;
ll kekos[N];
 
const ll INF = 1e18;
ll dp[N];
ll dp2[N];
 
const int CNT = 1;
 
void calc_dp() {
	
	for (int i = 0; i < N; ++i) dp[i] = kekos[i];
 
	int deg = 1;
 
	for (int pos = 0; pos < 6; ++pos) {
 
		for (int was = 0; was < N; ++was) dp2[was] = -INF;
 
		for (int was = 0; was < N; ++was) {

			for (int stay = 0; stay < 10; ++stay) {
				ll cur = 0;
				if (stay % 3 == 0) cur = (ll) (stay / 3) * profit[pos];
				if (was + stay * deg < N) {
					dp2[was + stay * deg] = max(dp2[was + stay * deg], dp[was] + cur);
				}
			}

		}

		for (int was = 0; was < N; ++was) dp[was] = dp2[was];
 
		deg *= 10;
	}
 
}
 
int read() {
	int q;
	cin >> q;
 
	int x;
	cin >> x;
 
	return x;
 
}
 
vector<pair<ll, int> > transform(vector<pair<ll, int> > cur) {
 
	vector<pair<ll, int> > res;
	while (cur.size()) {
		if (cur.back().y >= 10) {
			int cnt = cur.back().y / 10;
			ll profit = cur.back().x * 10;
			res.pb(mp(profit, cnt));
			cur.back().y %= 10;
		}
		else {
 
			ll pr = 0;
			int cnt = 0;
 
			while (cur.size() && cur.back().y + cnt < 10) {
				pr += (ll) cur.back().x * cur.back().y;
				cnt += cur.back().y;
				cur.pop_back();
			}
 
			if (!cur.size()) break;
			pr += (ll) (10 - cnt) * cur.back().x;
 
			cur.back().y -= (10 - cnt);
			if (cur.back().y == 0) cur.pop_back();
 
			res.pb(mp(pr, 1));
 
		}
	}
 
	return res;
 
}
 
ll cheapest_good(int n, int k) {
 
	ll ans = 0;
 
	vector<pair<ll, int> > cur;
	for (int i = 0; i < 6; ++i) {
		cur.pb(mp(profit[i], 3*k));
 
		sort(all(cur));
		int need = n%10;
 
		while (need > 0) {
			if (!cur.size()) return -INF;
			if (cur.back().y > need) {
				ans += (ll) need * cur.back().x;
				cur.back().y -= need;
				need = 0;
			}
 
			else {
				ans += (ll) cur.back().y * cur.back().x;
				need -= cur.back().y;
				cur.pop_back();
			}
		}
 
		n /= 10;
 
		cur = transform(cur);
 
	}
 
	return ans;
 
}

ll cheapest(int n, int k) {
 
	if (n % 3 != 0) return -INF;
	return cheapest_good(n / 3, k);
 
}

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int k;
	cin >> k;
 
	for (int i = 0; i < 6; ++i) cin >> profit[i];

	for (int i = 0; i < N; ++i) kekos[i] = cheapest(i, k - 1);
	calc_dp();
 
	int q;
	cin >> q;

	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;

		cout << dp[x] << '\n';


	}
 
 
 
 
}