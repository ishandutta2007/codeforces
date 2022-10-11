#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 21;

vector<int> G[1 << MAX_N];
int N, A[1 << MAX_N];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]); G[A[i]].push_back(i);
	}
	for (int i = 0; i < (1 << MAX_N); i++) {
		sort(G[i].begin(), G[i].end());
		reverse(G[i].begin(), G[i].end());
	}

	for (int i = (1 << MAX_N) - 1; i >= 0; i--) {
		int p1 = -1, p2 = -1, p3 = -1;
		if (G[i].size() >= 1) p1 = G[i][0];
		if (G[i].size() >= 2) p2 = G[i][1];

		for (int j = 0; j < MAX_N; j++) {
			if ((i & (1 << j)) != 0) continue;

			for (int k : G[i + (1 << j)]) {
				if (p1 == k || p2 == k) continue;
				p3 = k;
				if (p2 < p3) swap(p2, p3);
				if (p1 < p2) swap(p1, p2);
			}
		}
		G[i].clear();
		if (p1 != -1) G[i].push_back(p1);
		if (p2 != -1) G[i].push_back(p2);
	}
	
	int cur = 0;
	for (int i = MAX_N - 1; i >= 0; i--) {
		int mask = cur + (1 << i); bool flag = false;

		for (int j = 0; j < N; j++) {
			int s = (mask & ((1 << MAX_N) - 1 - A[j]));
			if (G[s].size() == 2 && G[s][1] > j) flag = true;
		}
		if (flag == true) cur = mask;
	}
	cout << cur << endl;
	return 0;
}