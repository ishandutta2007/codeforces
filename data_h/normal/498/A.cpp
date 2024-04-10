#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 333;

int n;
int pos[N];

int main() {
	int sx, sy, tx, ty, answer = 0;
	scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int sign = ((1LL * sx * a + 1LL * sy * b + c) > 0 ? 1 : -1);
		sign *= ((1LL * tx * a + 1LL * ty * b + c) > 0 ? 1 : -1);
		if (sign < 0) {
			answer++;
		}
	}
	printf("%d\n", answer);
	return 0;
}