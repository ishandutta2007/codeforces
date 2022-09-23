#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<int> V[202020];
int A[202020];
int B[202020];
bool vst[202020];
int id;
vector<pii> ans;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= N; i++) {
		if(vst[i]) continue;
		int j = i;
		id++; V[id].push_back(0);
		while(1) {
			vst[j] = true; V[id].push_back(j);
			j = A[j];
			if(j == i) break;
		}
	}

	for(int i = 1; i <= id; i++) B[i] = i;
	sort(B + 1, B + id + 1, [&](const int& a, const int& b) {
		return V[a].size() < V[b].size();
	});

	if(id & 1) {
		int j = B[id];
		if(V[j].size() == 3) {
			int k = B[id - 1];
			ans.emplace_back(V[k][1], V[j][2]);
			ans.emplace_back(V[k][1], V[j][1]);
			ans.emplace_back(V[k][1], V[j][2]);
		}
		else if(V[j].size() > 3) {
			int x = (int)V[j].size() - 1;
			ans.emplace_back(V[j][x - 1], V[j][x]);
			ans.emplace_back(V[j][x - 2], V[j][x]);
			for(int i = 1; i <= x - 2; i++) {
				ans.emplace_back(V[j][i], V[j][x - 1]);
			}
			ans.emplace_back(V[j][x - 1], V[j][x]);
		}
	}

	for(int z = 1; z <= id / 2; z++) {
		int i = B[z * 2 - 1], j = B[z * 2];
		int x = (int)V[i].size() - 1, y = (int)V[j].size() - 1;

		ans.emplace_back(V[i][x], V[j][y]);
		for(int k = 1; k < x; k++) {
			ans.emplace_back(V[i][k], V[j][y]);
		}
		for(int k = 1; k < y; k++) {
			ans.emplace_back(V[i][x], V[j][k]);
		}
		ans.emplace_back(V[i][x], V[j][y]);
	}

	printf("%d\n", ans.size());
	for(auto& i : ans) printf("%d %d\n", i.first, i.second);

	return 0;
}