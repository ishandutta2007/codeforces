#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

const int N = 500 + 5;

bitset<N> f[N];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	f[0].set(0, 1);
	for (int i = 0; i < n; i++) {
		int w;
		scanf("%d", &w);
		for (int j = k; j >= 0; j--) {
			if (j >= w) {
				f[j] |= (f[j - w] << w);
				f[j] |= f[j - w];
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i <= k; i++) {
		if (f[k][i] == 1) {
			ans.push_back(i);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d%c", ans[i], " \n"[i + 1 == ans.size()]);
	}
}