#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, a[100005], psum[100005];
int pl[100005][32][2];

int main()
{
	scanf("%d", &n);
	rep1(i, n) scanf("%d", &a[i]);
	rep1(i, n) psum[i] = psum[i - 1] ^ a[i];
	
	rep(i, 30) rep(j, 2) pl[0][i][j] = -j;
	rep1(i, n) rep(j, 30) rep(k, 2) pl[i][j][k] = (psum[i] >> j & 1) == k ? i : pl[i - 1][j][k];
	
	int ans = INF;
	rep1(i, n) {
		int pos = i;
		for(int j = 29; j >= 0; j --) {
			pos = min(pos, pl[i - 1][j][psum[i] >> j & 1]);
			if(pos == -1) break;
			int cl = pl[pos][j][!(psum[i] >> j & 1)];
			if(cl != -1) ans = min(ans, i - cl);
		}
	}
	printf("%d\n", ans == INF ? -1 : ans - 2);
	return 0;
}