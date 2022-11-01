#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 2e5 + 7;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i] += i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		a[i] -= i;
	}
	for (int i = 0; i + 1 < n; i++) {
		if (a[i] > a[i + 1]) {
			puts(":(");
			exit(0);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d%c", a[i], i + 1 == n ? '\n' : ' ');
	}
	return 0;
}