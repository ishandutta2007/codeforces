#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[1 << 18], B[1 << 18];
int dp[1 << 18], pars[1 << 18];
int grav;
vector<int> X[2009], Y[2009];
vector<int> Z1[2009], Z2[2009];

void dfs(int pos) {
	dp[pos] = 1;
	for (int i : X[pos]) {
		if (dp[i] >= 1) continue;
		dfs(i);
		Y[pos].push_back(i);
		dp[pos] += dp[i];
		pars[i] = pos;
	}
}

int idx[2009], num[2009], cnt1, cnt2;
int par[2009];

void dfs2(int pos) {
	if (pos != grav) {
		cnt1++; idx[pos] = cnt1;
		num[pos] = 1;
	}
	for (int i : Z1[pos]) {
		if (i == grav || idx[i] >= 1) continue;
		par[i] = pos;
		dfs2(i);
	}
}

void dfs3(int pos) {
	if (pos != grav) {
		cnt2++; idx[pos] = cnt2;
		num[pos] = 2;
	}
	for (int i : Z2[pos]) {
		if (i == grav || idx[i] >= 1) continue;
		par[i] = pos;
		dfs3(i);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		X[A[i]].push_back(B[i]);
		X[B[i]].push_back(A[i]);
	}
	dfs(1);

	for (int i = 1; i <= N; i++) {
		bool flag = false; int rem = N - 1; vector<pair<int, int>> c;
		for (int j : Y[i]) {
			if (dp[j] > N / 2) flag = true;
			rem -= dp[j];
			c.push_back(make_pair(dp[j], j));
		}
		if (rem > N / 2) flag = true;
		if (rem >= 1) c.push_back(make_pair(rem, pars[i]));

		if (flag == false) {
			grav = i;
			sort(c.begin(), c.end());
			reverse(c.begin(), c.end());
			int sum = 0, border = -1;
			for (int j = 0; j < c.size(); j++) {
				sum += c[j].first; border = j;
				if (3 * sum >= N - 1) break;
			}
			for (int j = 0; j <= border; j++) {
				Z1[grav].push_back(c[j].second);
				Z1[c[j].second].push_back(grav);
			}
			for (int j = border + 1; j < c.size(); j++) {
				Z2[grav].push_back(c[j].second);
				Z2[c[j].second].push_back(grav);
			}
			break;
		}
	}

	for (int i = 1; i <= N - 1; i++) {
		if (A[i] == grav || B[i] == grav) continue;
		Z1[A[i]].push_back(B[i]); Z2[A[i]].push_back(B[i]);
		Z1[B[i]].push_back(A[i]); Z2[B[i]].push_back(A[i]);
	}
	dfs2(grav);
	dfs3(grav);

	for (int i = 1; i <= N; i++) {
		if (i == grav) continue;
		int weight = idx[i] - idx[par[i]];
		if (num[i] == 2) weight *= (cnt1 + 1);
		cout << i << " " << par[i] << " " << weight << endl;
	}
	return 0;
}