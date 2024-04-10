#include <bits/stdc++.h>
typedef long long LL;
const int N = 2e5, M = 64;

int n, cnt[M + 5];
LL a[N + 5], b[N + 5], c[N + 5];

int main() {
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]), sum += b[i];
    for (int i = 1; i <= n; i++) scanf("%lld", &c[i]), sum += c[i];
    if (sum % (2 * n) != 0) {
    	puts("-1");
    	return 0;
	}
    sum /= (2 * n);
    for (int i = 1; i <= n; i++) {
        LL tmp = b[i] + c[i] - sum;
        if (tmp < 0 || tmp % n != 0) {
        	puts("-1");
        	return 0;
		}
        a[i] = tmp / n;
        for (int j = 0; j <= 63; j++) if (((a[i] >> j) & 1) == 1) cnt[j]++;
    }
    for (int i = 1; i <= n; i++) {
        LL tmp1 = 0, tmp2 = 0;
        for (int j = 0; j <= 63; j++) {
            if (((a[i] >> j) & 1) == 1) {
                tmp1 += (1LL << j) * cnt[j];
                tmp2 += (1LL << j) * n;
            } else {
                tmp2 += (1LL << j) * cnt[j];
            }
        }
        if (tmp1 != b[i] || tmp2 != c[i]) {
        	puts("-1");
        	return 0;
		}
    }
    for (int i = 1; i <= n; i++) printf("%lld%c", a[i], " \n"[i == n]);
    return 0;
}