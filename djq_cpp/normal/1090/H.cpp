#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 1e9 + 7;

int n, q;
char dat[200005];
int sum[200005][25];

int main()
{
	scanf("%d%s", &n, dat + 1);
	for(int i = n; i >= 2; i --) dat[i] ^= dat[i - 1];
	dat[1] = 0;
	rep1(i, n) rep(j, 18)
	sum[i][j] = (i >= (1 << j) ? sum[i - (1 << j)][j] : 0) + dat[i];
	
	scanf("%d", &q);
	rep(i, q) {
		int l, r;
		scanf("%d%d", &l, &r);
		l ++; r ++;
		int ans = 0;
		int cnt[25] = {}, cnt0[25] = {};
		rep(j, 18) if((1 << j) >= r - l + 1) break;
		else {
			cnt[j] = sum[r - (1 << j) + 1][j] - sum[l][j];
			cnt0[j] = (r - l + 1 >> j) - 1 - cnt[j];
		}
		rep(j, 18) ans += min(cnt[j] - cnt[j + 1], cnt0[j] - cnt0[j + 1]);
		printf("%d\n", ans + 1 >> 1);
	}
	return 0;
}