#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int bls = 666;
int N, M;
int x[200005], y[200006];
int adt[200005];
int cc[bls + 5][bls + 5];
int ad[400005];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%d%d", x + i, y + i);
	int sm = 0;
	for (int i = 1; i <= M; ++i) {
		int op; scanf("%d", &op);
		if (op == 1) {
			int k; scanf("%d", &k);
			if (x[k] + y[k] >= bls) {
				for (int t = i; t <= M; t += x[k] + y[k]) {
					if (t + x[k] <= M) ++ad[t + x[k]];
					if (t + x[k] + y[k] <= M) --ad[t + x[k] + y[k]];
				}
			}
			else {
				for (int t = x[k]; t < x[k] + y[k]; ++t) ++cc[x[k] + y[k]][(i + t) % (x[k] + y[k])];
			}
			adt[k] = i;
		}
		else {
			int k; scanf("%d", &k);
			int I = adt[k];
			if (x[k] + y[k] >= bls) {
				for (int t = I; t <= M; t += x[k] + y[k]) {
					int nt = t + x[k];
					if (nt <= M) {
						if (nt < i) --sm;
						else --ad[nt];
					}
					nt = t + x[k] + y[k];
					if (nt <= M) {
						if (nt < i) ++sm;
						else ++ad[nt];
					}
				}
			}
			else {
				for (int t = x[k]; t < x[k] + y[k]; ++t) --cc[x[k] + y[k]][(I + t) % (x[k] + y[k])];
			}
		}
		sm += ad[i];
		int nsm = sm;
		for (int j = 1; j < bls; ++j) nsm += cc[j][i % j];
		printf("%d\n", nsm);
	}
	return 0;
}