#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

// 
const int MAX_N = (1 << 19);
int N = 1;
int idx[1 << 20];
int cp[1 << 20];
int par[MAX_N];
vector<pair<int, long long>> X[MAX_N]; 
vector<pair<int, int>> pres;

void MakeTree(int E) {
	pres.push_back(make_pair(1, 1)); par[1] = -1; idx[1] = 1;

	for (int i = 2; i <= E; i++) {
		int cx = i, maxn = 0, cv = 0;
		for (int j = 2; j <= i; j++) {
			if (cx % j != 0) continue;
			cv = 0;
			while (cx % j == 0) { cp[j]++; maxn = j; cv++; cx /= j; }
		}

		int pre_id = pres.size() - 1;
		for (int j = 0; j < pres.size(); j++) {
			if (pres[j].second == maxn) pre_id = j;
		}

		vector<pair<int, int>> pre2; idx[i] = N + 1;
		for (int j = 2; j <= maxn; j++) {
			if (cp[j] == 0) continue;
			N++; pre2.push_back(make_pair(N, j));
		}
		for (int j = pre_id; j < pres.size(); j++) {
			pre2.push_back(pres[j]);
		}
		for (int j = 0; j < pre2.size() - 1; j++) {
			if (par[pre2[j].first] != 0) continue;
			par[pre2[j].first] = pre2[j + 1].first;

			int weight = cp[pre2[j].second]; if (pre2[j].second == maxn) weight = cv;
			X[pre2[j + 1].first].push_back(make_pair(pre2[j].first, weight));
		}
		pres = pre2;
	}
}

long long NN, A[1 << 20];
long long cnt[MAX_N];
long long dist1[MAX_N], cnt1[MAX_N];
long long dist2[MAX_N], cnt2[MAX_N];

void dfs1(int pos) {
	cnt1[pos] = cnt[pos];
	dist1[pos] = 0;
	for (int i = 0; i < X[pos].size(); i++) {
		dfs1(X[pos][i].first);
		dist1[pos] += dist1[X[pos][i].first] + 1LL * X[pos][i].second * cnt1[X[pos][i].first];
		cnt1[pos] += cnt1[X[pos][i].first];
	}
}

void dfs2(int pos) {
	for (int i = 0; i < X[pos].size(); i++) {
		// 
		dist2[X[pos][i].first] += (dist2[pos] + 1LL * X[pos][i].second * cnt2[pos]);
		cnt2[X[pos][i].first] += cnt2[pos];
		
		// 
		dist2[X[pos][i].first] += (dist1[pos] + 1LL * X[pos][i].second * cnt1[pos]);
		cnt2[X[pos][i].first] += cnt1[pos];

		// 
		dist2[X[pos][i].first] -= (dist1[X[pos][i].first] + 2LL * X[pos][i].second * cnt1[X[pos][i].first]);
		cnt2[X[pos][i].first] -= cnt1[X[pos][i].first];

		dfs2(X[pos][i].first);
	}
}

int main() {
	MakeTree(5000);

	scanf("%lld", &NN); idx[0] = 1;
	for (int i = 1; i <= NN; i++) {
		scanf("%lld", &A[i]);
		cnt[idx[A[i]]]++;
	}

	dfs1(1);

	dfs2(1);

	long long ans = (1LL << 62);
	for (int i = 1; i <= N; i++) {
		ans = min(ans, dist1[i] + dist2[i]);
	}
	cout << ans << endl;
	return 0;
}