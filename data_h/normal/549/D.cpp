#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 111;

int n, m;
char table[N][N];
int sum[N], answer = 0;

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", table[i]);
	}
	// W 1, B -1
	for (int i = n - 1; i >= 0; i--) {
		int pre = 0;
		for (int j = m - 1; j >= 0; j--) {
			pre += sum[j];
			int target = 1;
			if (table[i][j] == 'B') {
				target = -1;
			}
			int delta = target - pre;
			if (delta) {
				answer++;
				sum[j] += delta;
				pre += delta;
			}
		}
	}
	printf("%d\n", answer);
	return 0;
}