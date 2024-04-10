/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) a.begin(), a.end()

const int N = 1000;

// x -   , y - 
pair<int,int> dp[N][N][2]; // 0 - , 1 - 

int main() {
	memset(dp, -1, sizeof(dp));
	dp[0][0][0] = dp[0][0][1] = {0, 1};

	function<pair<int,int>(int, int, int)> go = [&](int x, int y, int can) {
		auto &ans = dp[x][y][can];
		if (ans.first != -1)
			return ans;
		ans = {0, 1e9};
		auto relax = [&](pair<int, int> &p, pair<int, int> x) {
			if (p.first < x.first || (p.first == x.first && p.second > x.second))
				p = x;
		};
		if (can || !x) {
			auto tmp = go(y, x, 0);
			relax(ans, {tmp.second, tmp.first + can});
		}
		if (x) {
			auto tmp = go(y, x - 1, 1);
			relax(ans, {tmp.second, tmp.first});
		}
		// printf("dp[%d,%d,%d] = <%d,%d>\n", x, y, can, ans.first, ans.second);
		return ans;
	};
		
	function<pair<int,int>(int, int)> cheat_go = [&](int x, int y) {
		pair<int,int> ans;
		if (x == 0 || y == 0) 
			ans = {x, y};
		else
			ans = {x - 1, y};
		return ans;
	};

	ios_base::sync_with_stdio(0), cin.tie(0);

	// const int C = 10;
	// forn(x, C) {
	// 	forn(y, C) {
	// 		auto ans = go(x, y, 0);
	// 		auto ans2 = cheat_go(x, y);
	// 		printf("[%d,%d]", ans.first, ans.second);
	// 		printf("[%d,%d] ", ans2.first, ans2.second);
	// 		fflush(stdout);
	// 		if (x != 0 || y != 0)
	// 			assert(ans == ans2);
	// 	}
	// 	puts("");
	// 	fflush(stdout);
	// }
	int tn;
	cin >> tn;
	while (tn--) {
		int x, y;
		cin >> x >> y;
		auto ans = cheat_go(x, y);
		cout << ans.first << " " << ans.second << "\n";
	}
}