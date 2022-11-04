#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
char c[405][405];
int sm[405][405];
int ln0[405], ln1[405];
int pl0[405], pl1[405], pl2[405];

void solve() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; ++i) scanf("%s", c[i] + 1);
	for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) sm[i][j] = sm[i][j - 1] + (c[i][j] == '1');
	int res = Inf;
	for (int i = 1; i <= M; ++i) for (int j = i + 3; j <= M; ++j) {
		for (int k = 1; k <= N; ++k) {
			ln0[k] = sm[k][j - 1] - sm[k][i] + (c[k][i] == '0') + (c[k][j] == '0');
			ln1[k] = (j - i - 1) - (sm[k][j - 1] - sm[k][i]);
			pl0[k] = pl0[k - 1] + ln0[k];
		}
		for (int k = 1; k <= N; ++k) {
			pl1[k] = ln1[k] - pl0[k];
			pl2[k] = ln1[k] + pl0[k - 1];
		}
		int mx = Inf;
		for (int k = 5; k <= N; ++k) {
			int nk = k - 4;
			mx = min(mx, pl1[nk]);
			res = min(res, pl2[k] + mx);
		}
	}
	printf("%d\n", res);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}