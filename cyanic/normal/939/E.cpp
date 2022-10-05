#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 500005;
LL s[maxn]; int n, now, op, Q, K;
int l, r, lmid, rmid;
double res;

double calc(int x) {
	return now - 1.0 * (s[x] + now) / (x + 1);
}

int main() {
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &now); K++;
			s[K] = s[K-1] + now;
		}
		else {
			l = 1; r = K-1;
			while (r-l >= 10) {
				lmid = (2*l + r) / 3;
				rmid = (l + 2*r) / 3;
				if (calc(lmid) < calc(rmid)) l = lmid;
				else r = rmid;
			}
			for (int i=l; i<=r; i++)
				res = max(res, calc(i));
			printf("%.8lf\n", res);
		}
	}
	return 0;
}