#include <stdio.h>
#include <vector>
std::vector<int> box[101000];
int n, m, k, x;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x), box[x % m].push_back(x);
	for (int i = 0; i < m; i++)
		if (box[i].size() >= k) {
			puts("Yes");
			for (int j = 0; j < k; j++) printf("%d ", box[i][j]);
			return 0;
		}
	puts("No");
	return 0;
}