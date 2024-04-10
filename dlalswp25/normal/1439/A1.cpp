#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char A[105][105];

struct X {
	pii p1, p2, p3;
	X(pii a, pii b, pii c) : p1(a), p2(b), p3(c) {}

	void print() {
		printf("%d %d %d %d %d %d\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
	}
};

vector<X> ans;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans.clear();
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				if(A[i][j] != '1') continue;

				int dx, dy;
				if(i == 1 && j == 1) { dx = 1; dy = 1; }
				else if(i == 1) { dx = 1; dy = -1; }
				else if(j == 1) { dx = -1; dy = 1; }
				else { dx = dy = -1; }

				ans.emplace_back(pii(i, j), pii(i + dx, j), pii(i, j + dy));
				ans.emplace_back(pii(i, j), pii(i + dx, j), pii(i + dx, j + dy));
				ans.emplace_back(pii(i, j), pii(i + dx, j + dy), pii(i, j + dy));
			}
		}

		printf("%d\n", ans.size());
		for(auto i : ans) i.print();
	}
	return 0;
}