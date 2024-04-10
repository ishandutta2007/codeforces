#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[5] = {1, 1, 2, 7, 4};
int b[5];

int main() {
	int ans = 100000;
	for(int i = 0; i < 5; i++) {
		scanf("%d", &b[i]);
		ans = min(ans, b[i] / a[i]);
	}
	printf("%d\n", ans);
	return 0;
}