
/*
	NOTE: This works in O(NlogN)
*/
#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 5e3 + 7, M = 1e9 + 7;

int inv(int i) {
	if(i == 1) return 1;
	else return M - (ll) M / i * inv(M % i) % M;
}

int s[N], ans_sleep = 0, ans_ways = 0, lnum[N], rnum[N];
array<int, 2> cur[N];
vi hs[N];

void upd(int sleep, int ways) {
	if(ans_sleep < sleep) ans_sleep = sleep, ans_ways = ways;
	else if(ans_sleep == sleep) ans_ways = (ans_ways + ways) % M;
}

array<int, 2> calc_ways(int f) {
	int can_left = upper_bound(ALL(hs[f]), lnum[f]) - hs[f].begin();
	int can_right = upper_bound(ALL(hs[f]), rnum[f]) - hs[f].begin();
	int ways1 = can_left + can_right, ways2 = (ll) min(can_left, can_right) * (max(can_left, can_right) - 1) % M;
	if(ways2 > 0) return {2, ways2};
	else if(ways1 > 0) return {1, ways1};
	else return {0, 1};
}

array<int, 2> calc_ways_right_only(int f) {
	int can_right = upper_bound(ALL(hs[f]), rnum[f]) - hs[f].begin();
	if(rnum[f] >= lnum[f]) can_right--; // remove the one forced to go from left
	if(can_right > 0) return {2, can_right};
	else return {1, 1};
	// note that the returned answer alreay includes the one from the left
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i], rnum[--s[i]]++;
	for(int i = 0; i < m; i++) {
		int f, h;
		cin >> f >> h;
		f--;
		hs[f].PB(h);
	}
	for(int i = 0; i < n; i++) sort(ALL(hs[i]));
	int sleep = 0, ways = 1;
	for(int i = 0; i < n; i++) {
		cur[i] = calc_ways(i);
		sleep += cur[i][0];
		ways = (ll) ways * cur[i][1] % M;
	}
	upd(sleep, ways); // all from right
	for(int i = 0; i < n; i++) { // make i the position of the right most cow from the left
		// remove s[i]
		sleep -= cur[s[i]][0];
		ways = (ll) ways * inv(cur[s[i]][1]) % M;
		lnum[s[i]]++, rnum[s[i]]--;

		// check if it is possible to make i the position of the right most cow from the left
		if(binary_search(ALL(hs[s[i]]), lnum[s[i]])) {
			auto res = calc_ways_right_only(s[i]);
			int nw_sleep = sleep + res[0];
			int nw_ways = (ll) ways * res[1] % M;
			upd(nw_sleep, nw_ways);
		}

		// put it back
		cur[s[i]] = calc_ways(s[i]);
		sleep += cur[s[i]][0];
		ways = (ll) ways * cur[s[i]][1] % M;
	}
	cout << ans_sleep << " " << ans_ways << endl;


}