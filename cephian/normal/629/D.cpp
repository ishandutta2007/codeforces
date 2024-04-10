#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

constexpr long double PI = atanl(1)*4;
constexpr int N = 1e5+5;

auto first_lesser(const set<pair<ll,ll>>& S, ll d) {
	// empty
	if(S.size() == 0) return S.end();
	// first thing too large
	if(S.begin()->first >= d) return S.end();
	return --S.lower_bound(make_pair(d, -1));
}

auto first_leq(const set<pair<ll,ll>>& S, ll d) {
	// empty
	if(S.size() == 0) return S.end();
	// first thing too large
	if(S.begin()->first > d) return S.end();
	return --S.upper_bound(make_pair(d, -1));
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	// last val, length
	set<pair<ll, ll>> dp;
	for(int i = 0; i < n; ++i) {
		ll r, h;
		cin >> r >> h;
		ll vol = r*r * h;
		auto it = first_lesser(dp, vol);
		pair<ll,ll> state(vol, vol);
		if(it != dp.end()) {
			state.second += it->second;
		}
		// are we obsolete?
		it = first_leq(dp, vol);
		if(it != dp.end() && it->second >= state.second) {
			// dont add
		} else {
			while(true) {
				it = dp.lower_bound(make_pair(vol, -1));
				if(it == dp.end() || it->second > state.second) {
					dp.insert(state);
					break;
				} else if(it->second <= state.second)
					dp.erase(it);
			}
		}
	}
	cout << setprecision(12) << fixed << PI * dp.rbegin()->second << '\n';
}