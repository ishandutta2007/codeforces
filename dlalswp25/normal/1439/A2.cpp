#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
char A[105][105];
int B[105][105];

struct X {
	pii p1, p2, p3;
	X(pii a, pii b, pii c) : p1(a), p2(b), p3(c) {}

	void print() {
		printf("%d %d %d %d %d %d\n", p1.first, p1.second, p2.first, p2.second, p3.first, p3.second);
	}
};

vector<X> ans;

void f(int x1, int y1, int x2, int y2, int x3, int y3) {
	ans.emplace_back(pii(x1, y1), pii(x2, y2), pii(x3, y3));
	B[x1][y1] ^= 1;
	B[x2][y2] ^= 1;
	B[x3][y3] ^= 1;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		ans.clear();
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			scanf("%s", A[i] + 1);
			for(int j = 1; j <= M; j++) B[i][j] = A[i][j] - '0';
		}

		if((N & 1) || (M & 1)) {
			if(B[1][1]) f(1, 1, 1, 2, 2, 1);
		}

		int x = 1, y = 1;

		if(N & 1) {
			for(int j = 2; j <= M; j++) {
				if(B[1][j]) f(1, j, 2, j - 1, 2, j);
			}
			x++;
		}

		if(M & 1) {
			for(int i = 2; i <= N; i++) {
				if(B[i][1]) {
					if(i == N) f(i, 1, i - 1, 2, i, 2);
					else f(i, 1, i + 1, 2, i, 2);
				}
			}
			y++;
		}

		for(int i = x; i <= N; i += 2) {
			for(int j = y; j <= M; j += 2) {
				vector<pii> v, w;
				for(int a = 0; a < 2; a++) {
					for(int b = 0; b < 2; b++) {
						if(B[i + a][j + b]) v.emplace_back(i + a, j + b);
						else w.emplace_back(i + a, j + b);
					}
				}

				if(!v.size()) continue;
				if(v.size() == 3) {
					f(v[0].first, v[0].second, v[1].first, v[1].second, v[2].first, v[2].second);
					continue;
				}
				if(v.size() == 1) {
					f(v[0].first, v[0].second, w[0].first, w[0].second, w[1].first, w[1].second);
					f(v[0].first, v[0].second, w[0].first, w[0].second, w[2].first, w[2].second);
					f(v[0].first, v[0].second, w[2].first, w[2].second, w[1].first, w[1].second);
					continue;
				}
				if(v.size() == 2) {
					f(v[0].first, v[0].second, w[0].first, w[0].second, w[1].first, w[1].second);
					f(v[1].first, v[1].second, w[0].first, w[0].second, w[1].first, w[1].second);
					continue;
				}
				for(int k = 0; k < 4; k++) {
					f(v[k].first, v[k].second, v[(k + 1) % 4].first, v[(k + 1) % 4].second, v[(k + 2) % 4].first, v[(k + 2) % 4].second);
				}
			}
		}

		printf("%d\n", ans.size());
		for(auto i : ans) i.print();
	}
	return 0;
}