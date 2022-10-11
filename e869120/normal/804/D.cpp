#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

int N, M, Q, A[1 << 17], B[1 << 17];
int col[1 << 17], dia[1 << 17], dist_far[1 << 17], dist[1 << 17], cnts;
bool used[1 << 17];
vector<long long> G[1 << 17], I, L[1 << 17], LL[1 << 17];

map<pair<int, int>, long double>Map;

void dfs(int pos, int dep) {
	if (used[pos] == true) return;
	I.push_back(pos);
	dist[pos] = dep; col[pos] = cnts; used[pos] = true;
	for (int i = 0; i < G[pos].size(); i++) dfs(G[pos][i], dep + 1);
}

void count_diameter(int root) {
	cnts++; I.clear();
	dfs(root, 0);
	pair<int, int>maxn1 = make_pair(-1, -1); for (int i = 0; i < I.size(); i++) maxn1 = max(maxn1, make_pair(dist[I[i]], (int)I[i]));
	for (int i = 0; i < I.size(); i++) used[I[i]] = false; I.clear();
	dfs(maxn1.second, 0);
	pair<int, int>maxn2 = make_pair(-1, -1); for (int i = 0; i < I.size(); i++) maxn2 = max(maxn2, make_pair(dist[I[i]], (int)I[i]));
	for (int i = 0; i < I.size(); i++) { used[I[i]] = false; dist_far[I[i]] = max(dist_far[I[i]], dist[I[i]]); } I.clear();
	dfs(maxn2.second, 0);
	for (int i = 0; i < I.size(); i++) { dist_far[I[i]] = max(dist_far[I[i]], dist[I[i]]); }
	for (int i = 0; i < I.size(); i++) dia[cnts] = max(dia[cnts], dist_far[I[i]]);
}

long double solve(int pos1, int pos2) {
	if (Map[make_pair(pos1, pos2)] > 0.5L) return Map[make_pair(pos1, pos2)] - 1.0L;

	int border = max(dia[pos1], dia[pos2]); long long sum = 0;
	for (int i = 0; i < L[pos1].size(); i++) {
		int pos3 = lower_bound(L[pos2].begin(), L[pos2].end(), border - 1 - L[pos1][i]) - L[pos2].begin();
		long long V1 = 1LL * border * pos3;
		long long V2 = 1LL * (LL[pos2][LL[pos2].size() - 1] - LL[pos2][pos3]) + 1LL * ((long long)L[pos2].size() - pos3) * (L[pos1][i] + 1LL);
		sum += (V1 + V2);
	}
	long double ans = 1.0L * sum / (long double)(1LL * (long long)L[pos1].size() * (long long)L[pos2].size());
	Map[make_pair(pos1, pos2)] = ans + 1.0L;
	return ans;
}

int main() {
	scanf("%d%d%d", &N, &M, &Q);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	for (int i = 1; i <= N; i++) {
		if (used[i] == true) continue;
		count_diameter(i);
	}
	for (int i = 1; i <= N; i++) L[col[i]].push_back(dist_far[i]);
	for (int i = 1; i <= cnts; i++) { sort(L[i].begin(), L[i].end()); LL[i].push_back(0); for (int j = 0; j < L[i].size(); j++) LL[i].push_back(LL[i][j] + L[i][j]); }

	for (int i = 1; i <= Q; i++) {
		int A, B; scanf("%d%d", &A, &B);
		A = col[A]; B = col[B]; if (L[A].size() > L[B].size()) swap(A, B);
		if (A == B) printf("-1\n");
		else {
			printf("%.12Lf\n", solve(A, B));
		}
	}
	return 0;
}