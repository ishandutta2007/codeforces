#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

map<int, int> mp;
int N;
int A[404040];

vector<pii> v;
int ans = 0;
int row = 0, col;

vector<int> mat[404040];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		mp[A[i]]++;
	}

	for(auto i : mp) v.push_back({i.second, i.first});

	sort(v.begin(), v.end());
	int M = v.size();

	int sum = 0;

	for(int i = 1; i * i <= N; i++) {
		sum += M - (lower_bound(v.begin(), v.end(), pii(i, 0)) - v.begin());
		if(ans < i * (sum / i) && i <= sum / i) {
			ans = i * (sum / i);
			row = i;
			col = sum / i;
		}
	}

	for(int i = 1; i <= row; i++) mat[i].resize(col + 1);

	printf("%d\n", ans);
	printf("%d %d\n", row, col);
	int cnt = 0;

	reverse(v.begin(), v.end());

	int y = 1, x = 0;
	for(auto i : v) {
		for(int j = 1; j <= min(row, i.first); j++) {
			if(cnt >= ans) break;
			// printf("%d %d\n", y, (x + y - 1) % col + 1);
			mat[y][(x + y - 1) % col + 1] = i.second;
			y++; if(y > row) { x++; y = 1; }
			cnt++;
		}
	}

	for(int i = 1; i <= row; i++) {
		for(int j = 1; j <= col; j++) printf("%d ", mat[i][j]); puts("");
	}

	return 0;
}