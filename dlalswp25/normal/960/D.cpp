#include <stdio.h>

int Q;
long long shift[64];

int main() {
	scanf("%d", &Q);
	for(int q = 0; q < Q; q++) {
		int T;
		long long X, K;
		scanf("%d", &T);
		if(T <= 2) {
			scanf("%lld%lld", &X, &K);
			int level = 0; long long tmp = 1;
			while(tmp <= X) {
				tmp <<= 1; level++;
			}
			level--; tmp >>= 1;
			long long how = K;
			if(K < 0) {
				how += tmp;
			}

			shift[level] = (shift[level] + how) % tmp;
			if(T == 2) {
				for(int i = level + 1; i <= 63; i++) {
					shift[i] = (shift[i] + (how << (i - level))) % ((1LL) << i);
				}
			}
		}
		else {
			scanf("%lld", &X);
			int level = 0; long long tmp = 1;
			while(tmp <= X) {
				tmp <<= 1; level++;
			}
			level--; tmp >>= 1;
			long long loc = tmp + (X + shift[level]) % tmp;

			while(loc >= 1) {
				printf("%lld ", tmp + (loc + tmp - shift[level]) % tmp);
				tmp >>= 1; loc >>= 1; level--;
			}
			puts("");
		}
	}
	return 0;
}