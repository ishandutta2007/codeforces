#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

const int N = 18;
const int MASK = 1 << N;

int cnt[MASK];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		static char op[10];
		long long x;
		scanf("%s", op);
		if (op[0] == '+' || op[0] == '-') {
			scanf("%lld", &x);
			int mask = 0;
			for (int i = 0; i < N; i++, x /= 10) {
				int d = x % 10;
				mask |= (d & 1) << i;
			}
			cnt[mask] += (op[0] == '+') ? 1 : -1;
		} else {
			static char buffer[1000];
			scanf("%s", buffer);
			int mask = 0;
			for (int i = 0; buffer[i]; i++) {
				mask = (mask << 1) | (buffer[i] == '1');
			}
			printf("%d\n", cnt[mask]);
		}

	}
	return 0;
}