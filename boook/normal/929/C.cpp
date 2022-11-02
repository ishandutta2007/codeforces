#include <bits/stdc++.h>
using namespace std;

int sum[4][101000];
int combination[1010][10];
vector< pair<int, int> > v;

int main() {
	for (int i = 0; i <= 1000; i++) {
		combination[i][0] = combination[i][i] = 1;
		for (int j = 1; j < min(5, i); j++)
			combination[i][j] = combination[i - 1][j] + combination[i - 1][j - 1];
	}


	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= a; i++) {
		int x;
		scanf("%d", &x);
		sum[1][x]++;
		v.push_back(make_pair(x, 1));
	}

	for (int i = 1; i <= b; i++) {
		int x;
		scanf("%d", &x);
		sum[2][x]++;
		v.push_back(make_pair(x, 2));
	}

	for (int i = 1; i <= c; i++) {
		int x;
		scanf("%d", &x);
		sum[3][x]++;
		v.push_back(make_pair(x, 3));
	}

	for (int i = 1; i <= 100000; i++) {
		for (int j = 1; j <= 3; j++) {
			sum[j][i] += sum[j][i - 1];
		}
	}

	long long ans = 0;

	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int need[4];
			need[1] = 1, need[2] = 2, need[3] = 3;
			int pos1 = v[i].second;
			int pos2 = v[j].second;
			if (pos1 == 1 && pos2 == 1) continue;
			need[pos1]--;
			need[pos2]--;

			int Min = min(v[i].first, v[j].first);
			int Max = max(v[i].first, v[j].first);
			if (Max > 2 * Min) continue;

			long long foo = 1;
			for (int k = 1; k <= 3; k++) {
				int cnt = sum[k][Max - 1] - sum[k][Min];
				foo *= combination[cnt][need[k]];
			}

			ans += foo;
		}
	}

	printf("%lld\n", ans);
	return 0;
}