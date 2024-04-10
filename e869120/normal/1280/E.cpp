#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int ty;
	vector<int> chil;
};

int N = 1;
Node E[1 << 20];

vector<int> G[1 << 20];
string Z;
long long num[1 << 20];
long long dep[1 << 20];
long long dp[1 << 20];
long long ans[1 << 20];

void init() {
	for (int i = 0; i < N; i++) {
		E[i].ty = 0;
		E[i].chil.clear();
		dp[i] = 0;
		ans[i] = 0;
	}
	for (int i = 0; i <= Z.size(); i++) {
		dep[i] = 0;
		G[i].clear();
	}
	N = 1; Z = "";
}

void parse(int cl, int cr, int u) {
	if (cl == cr) {
		E[u].ty = 3;
		num[u] = cl;
		return;
	}

	int pos1 = lower_bound(G[dep[cl]].begin(), G[dep[cl]].end(), cl) - G[dep[cl]].begin();
	int pos2 = lower_bound(G[dep[cl]].begin(), G[dep[cl]].end(), cr + 1) - G[dep[cl]].begin();

	if (pos1 == pos2) {
		parse(cl + 1, cr - 1, u);
	}
	if (pos1 < pos2) {
		vector<int> vec; vec.push_back(cl - 1);
		for (int i = pos1; i < pos2; i++) vec.push_back(G[dep[cl]][i]);
		vec.push_back(cr + 1);

		if (Z[G[dep[cl]][pos1]] == 'S') E[u].ty = 1;
		if (Z[G[dep[cl]][pos1]] == 'P') E[u].ty = 2;

		vector<tuple<int, int, int>> vec2;
		for (int i = 0; i < vec.size() - 1; i++) {
			vec2.push_back(make_tuple(vec[i] + 1, vec[i + 1] - 1, N));
			E[u].chil.push_back(N);
			N++;
		}
		for (int i = 0; i < vec2.size(); i++) {
			parse(get<0>(vec2[i]), get<1>(vec2[i]), get<2>(vec2[i]));
		}
	}
}

void dfs(int pos, long long ret) {
	ans[pos] = ret;
	if (E[pos].ty == 1) {
		pair<long long, int> minx = make_pair(1LL << 60, -1);
		for (int i : E[pos].chil) minx = min(minx, make_pair(dp[i], i));
		dfs(minx.second, ret);
	}
	if (E[pos].ty == 2) {
		for (int i : E[pos].chil) {
			long long val = (ret / dp[pos]) * dp[i];
			dfs(i, val);
		}
	}
}

vector<pair<int, long long>> solve(string SS) {
	dep[0] = 0; Z = SS;
	for (int i = 0; i < SS.size(); i++) {
		dep[i + 1] = dep[i];
		if (SS[i] == '(') dep[i + 1]++;
		if (SS[i] == ')') dep[i + 1]--;
	}
	for (int i = 0; i < SS.size(); i++) {
		if (SS[i] == 'P' || SS[i] == 'S') G[dep[i]].push_back(i);
	}
	parse(0, SS.size() - 1, 0);

	for (int i = N - 1; i >= 0; i--) {
		if (E[i].ty == 3) {
			dp[i] = 1;
		}
		if (E[i].ty == 1) {
			dp[i] = (1LL << 60);
			for (int j : E[i].chil) dp[i] = min(dp[i], dp[j]);
		}
		if (E[i].ty == 2) {
			for (int j : E[i].chil) {
				dp[i] += dp[j];
				dp[i] = min(dp[i], 1LL << 60);
			}
		}
	}

	dfs(0, dp[0] * dp[0]);

	vector<pair<int, long long>> rem;
	for (int i = 0; i < N; i++) {
		if (E[i].ty == 3) { rem.push_back(make_pair(num[i], ans[i])); }
	}
	sort(rem.begin(), rem.end());
	return rem;
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		long long R; cin >> R;
		string S = ""; while (S == "") { getline(cin, S); }

		string SS = "";
		for (int j = 0; j < S.size(); j++) {
			if (S[j] != ' ') SS += S[j];
		}

		vector<pair<int, long long>> FinalAns = solve(SS);
		printf("REVOLTING ");
		for (int j = 0; j < FinalAns.size(); j++) {
			if (j) printf(" ");
			printf("%lld", FinalAns[j].second * R);
		}
		printf("\n");
		init();
	}
	return 0;
}