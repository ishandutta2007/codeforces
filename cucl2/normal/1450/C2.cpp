#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
typedef long long ll;

int N;
char s[305][305];
char t[3][305][305];

void solve() {
	scanf("%d", &N);
	rep(i, N) scanf("%s", s[i]);
	int k = 0;
	rep(i, N) rep(j, N) if (s[i][j] != '.') ++k;
	rep(p, 3) {
		int q = (p + 1) % 3;
		rep(i, N) rep(j, N) {
			t[p][i][j] = s[i][j];
			if ((i + j) % 3 == p && s[i][j] != '.') t[p][i][j] = 'O';
			if ((i + j) % 3 == q && s[i][j] != '.') t[p][i][j] = 'X';
		}
		int dif = 0;
		rep(i, N) rep(j, N) if (t[p][i][j] != s[i][j]) ++dif;
		if (dif <= k / 3) {
			rep(i, N) {
				t[p][i][N] = 0;
				printf("%s\n", t[p][i]);
			}
			break;
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}