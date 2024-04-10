#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int N, M;
int cc[11];
int a[11][100005];
vector<vector<int> > bans;

int main() {
	scanf("%d", &N);
	rep(i, N) {
		scanf("%d", cc + i);
		repi(j, cc[i]) scanf("%d", a[i] + j);
	}
	scanf("%d", &M);
	rep(i, M) {
		vector<int> ban;
		rep(j, N) {
			int b; scanf("%d", &b);
			ban.push_back(b);
		}
		bans.push_back(ban);
	}
	sort(bans.begin(), bans.end());
	int ans = -1;
	int ni, fj, nk;
	if (M) {
		rep(i, N) {
			rep(j, M) {
				vector<int> seq;
				int qz = 0;
				rep(k, i) seq.push_back(bans[j][k]), qz += a[k][bans[j][k]];
				seq.push_back(Inf);
				assert(bans[j] < seq);
				int nj = j;
				while (nj < M && bans[nj] < seq) ++nj;
				int cur = bans[j][i] - 1;
				for (int k = j; k < nj; ++k) {
					int nxt = (k < nj - 1 ? bans[k + 1][i] : cc[i] + 1);
					if (bans[k][i] + 1 < nxt) cur = nxt - 1;
				}
				if (!cur) {
					j = nj - 1;
					continue;
				}
				qz += a[i][cur];
				for (int k = i + 1; k < N; ++k) qz += a[k][cc[k]];
				ans = max(ans, qz);
				if (ans == qz) {
					ni = i;
					fj = j;
					nk = cur;
				}
				j = nj - 1;
			}
		}
	}
	else {
		rep(i, N) printf("%d ", cc[i]);
		return 0;
	}
	rep(i, ni) printf("%d ", bans[fj][i]);
	printf("%d ", nk);
	for (int i = ni + 1; i < N; ++i) printf("%d ", cc[i]);
	return 0;
}