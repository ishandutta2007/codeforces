#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 

bool home = true;
using namespace std;

typedef long long ll;

bool is_sm(ll n, ll k, ll lim) {
	/*
	
	is the real position <= lim?
	
	*/
	assert(k > 0);
	map<ll, ll> lft, rgh;
	pair<ll, ll> seg = { 2, n - 1 };
	lft[0] = 0;
	rgh[0] = 0;
	while (1) {
		
		ll len_lft = lft.rbegin()->first;
		ll len_rgh = rgh.rbegin()->first;
		ll len_seg = seg.second - seg.first + 1;

		ll dist_lft = (len_lft + 1) / 2;
		ll dist_rgh = (len_rgh + 1) / 2;
		ll dist_seg = (len_seg + 1) / 2;
		ll max_dist = max({ dist_lft, dist_rgh, dist_seg });
		
		ll cnt_lft = lft[len_lft];
		ll cnt_rgh = rgh[len_rgh];

		if (dist_lft == max_dist) {
			if (cnt_lft >= k) return 1;
			k -= cnt_lft;
			lft[len_lft / 2] += cnt_lft;
			lft[(len_lft - 1) / 2] += cnt_lft;
			lft.erase(prev(lft.end()));
			continue;
		}

		if (dist_seg == max_dist) {
			ll mid = (seg.first + seg.second) / 2;
			if (k == 1) {
				return mid <= lim;
			}
			k--;

			ll l1 = seg.first, r1 = mid - 1;

			ll l2 = mid + 1, r2 = seg.second;

			seg = { 0, -1 };

			if (r1 <= lim) lft[r1 - l1 + 1]++;
			else seg = { l1, r1 };
			if (l2 > lim) rgh[r2 - l2 + 1]++;
			else seg = { l2, r2 };

			continue;
		}
		
		if (dist_rgh == max_dist) {
			if (cnt_rgh >= k) return 0;
			k -= cnt_rgh;
			rgh[len_rgh / 2] += cnt_rgh;
			rgh[(len_rgh - 1) / 2] += cnt_rgh;
			rgh.erase(prev(rgh.end()));	
			continue;
		}
		
		assert(0);
	}
}

ll solve(ll n, ll k) {

	assert(1 <= k && k <= n);
	if (k == 1) return 1;
	if (k == 2) return n;
	k -= 2;
	ll sol = -1, l = 2, r = n - 1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (is_sm(n, k, mid)) {
			sol = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	ll n, k;
	cin >> n >> k;
	cout << solve(n, k) << "\n";


}