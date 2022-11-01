#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 24;

int n, a[N], sum[1 << N], cnt1, pos[1 << N];
bool exist[1 << N];
vector<int> number;
bool f[N][1 << (N >> 1)][N];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) {
			cnt1++;
		} else {
			number.push_back(a[i]);
		}
	}
	sort(number.begin(), number.end());
	int m = number.size();
	if (n == 1 && cnt1 == 1) {
		printf("YES\n");
		return 0;
	}
	if (m == 0 || number[m - 1] != n || cnt1 < (n + 1) / 2 || cnt1 < number[0] - 1 || number[0] == 2) {
		printf("NO\n");
		return 0;
	} 
	for(int i = 0; i < (1 << m); i++) {
		for(int j = 0; j < m; j++) {
			if (i >> j & 1) {
				sum[i] += number[j];
				pos[i]++;
			}
		}
	}
	f[0][1][cnt1 - number[0] + 1] = true;
	for(int i = 0; i < m - 1; i++)
		for(int j = 0; j < (1 << (i + 1)); j++)
			for(int k = 0; k <= cnt1; k++) {
				if (f[i][j][k] == false)
					continue;
				if (i == 3 && j == 11 && k == 3)
					i = 3;
				int c = number[i + 1];
				for(int subset = j; ; subset = (subset - 1) & j) {
					if (sum[subset] <= c - 1 && c - 1 - sum[subset] <= k 
						&& pos[subset] + c - 1 - sum[subset] > 1) {
						f[i + 1][(j ^ subset) | 1 << (i + 1)][k - (c - 1 - sum[subset])] = true;
					}
					if (subset == 0)
						break;
				}
			}
	if (f[m - 1][1 << (m - 1)][0]) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}