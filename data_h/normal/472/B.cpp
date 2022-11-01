#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2222;

int s[N], t[N], n, k;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		t[x]++;
	}
	int ans = 0;
	for(int i = 2; i <= 2000; i++) {
		int times = (n + k - 1) / k;
		if (times) {
			ans += times * 2;
		}
		n -= t[i];
	}
	printf("%d\n", ans);
	return 0;
}