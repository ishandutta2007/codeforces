#include <bits/stdc++.h>

using namespace std;

int N;
char A[205][205];
char B[205][205];
vector<pair<int, int> > ans1, ans2;

int x[4] = {1, 2, };
int y[4] = {2, 1, };

void print(vector<pair<int, int> >& v) {
	printf("%d\n", v.size());
	for(auto i : v) printf("%d %d\n", i.first, i.second);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);

		B[1][2] = B[2][1] = '0';
		B[N - 1][N] = B[N][N - 1] = '1';
		ans1.clear();
		ans2.clear();

		x[2] = N - 1; x[3] = N;
		y[2] = N; y[3] = N - 1;

		for(int i = 0; i < 4; i++) {
			if(A[x[i]][y[i]] != B[x[i]][y[i]]) ans1.emplace_back(x[i], y[i]);
			else ans2.emplace_back(x[i], y[i]);
		}
		if(ans1.size() > 2) print(ans2);
		else print(ans1);
	}
	return 0;
}