#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

#define free FREE

const int MOD = 1e9 + 7;
const int N = 3e5 + 7;

map<int, vector<int> > graph;
map<int, int> free;
vector<pair<int, int> > list;

int visit[N];
int n, m;

void erase(vector<int> &list, int v) {
	int bakS = list.size();
	list.erase(find(list.begin(), list.end(), v));
	assert(bakS == list.size() + 1);
}

int getv(int literal, int v) {
	return (literal > 0) ^ v ^ 1;
}

void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

void get_list(int s) {
	visit[s] = 1;
	for (int sign = -1; sign < 2; sign += 2) {
		int sv = s * sign;
		while (!graph[sv].empty()) {
			int to = graph[sv].back();
			graph[sv].pop_back();
			erase(graph[to], sv);
			list.emplace_back(sv, to);
			get_list(abs(to));
		}
	}
}

int get_free(int x) {
	return free[x] == 1;
}

vector<int> solve(int s) {
	list.clear();
	get_list(s);

	static int dp[N][2][2];
	vector<int> ret(2);

	// printf("solve %d\n", s);
	// for (int i = 0; i < list.size(); i++) {
	// 	printf("%d %d\n", list[i].first, list[i].second);
	// }

	for (int first_val = 0; first_val < 2; first_val ++) {
		for (int i = 0; i <= list.size(); i++) {
			dp[i][0][0] = dp[i][0][1] = 0;
			dp[i][1][0] = dp[i][1][1] = 0;
		}
		dp[0][get_free(first_val == 0 ? -s : s)][0] = 1;
		for (int i = 0; i < list.size(); i++) {
			for (int xor_v = 0; xor_v < 2; xor_v++) {
				for (int prev = 0; prev < 2; prev++) {
					for (int val2 = 0; val2 < 2; val2++) {
						int v1 = abs(list[i].first) == s ?
							getv(list[i].first, first_val) : getv(list[i].first, prev);
						int v2 = getv(list[i].second, val2);
						if (abs(list[i].second) == s && first_val != val2) continue;
						int free_v2 = 0;
						if (abs(list[i].second) != abs(list[i].first) && abs(list[i].second) != s) {
							free_v2 = get_free(val2 > 0 ? abs(list[i].second) : -abs(list[i].second));
						}
						add(dp[i + 1][xor_v ^ (v1 | v2) ^ free_v2][val2], dp[i][xor_v][prev]);
					}
				}
			}
		}

		for (int xor_v = 0; xor_v < 2; xor_v++) {
			for (int prev = 0; prev < 2; prev++) {
				add(ret[xor_v], dp[list.size()][xor_v][prev]);
			}
		}
	}

	//printf("ret = %d %d\n", ret[0], ret[1]);

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k; scanf("%d", &k);
		if (k == 1) {
			int x; scanf("%d", &x);
			free[x]++;
		} else {
			int x, y; scanf("%d %d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
	}

	vector<int> dp(2);
	dp[0] = 1;
	for (int i = 1; i <= m; i++) {
		if (visit[i]) continue;
		vector<int> sub = solve(i);
		vector<int> new_dp(2);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				add(new_dp[j ^ k], 1LL * dp[j] * sub[k] % MOD);
			}
		}
		dp = new_dp;
	}
	printf("%d\n", dp[1]);
	return 0;
}