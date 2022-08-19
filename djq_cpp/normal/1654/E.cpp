#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAGIC = 320;

int n, a[100005], dp[100005][325],* arr = &dp[0][0];
int calc(int d)
{
	int ret = 0;
	rep(i, n) ret = max(ret, ++ arr[a[i] + d * i]);
	rep(i, n) arr[a[i] + d * i] --;
	return n - ret;
}

int tt[200010],* tmp = tt + 100005;
int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	int ans = n - 1;
	rep(i, 2) {
		for(int j = 0; j <= MAGIC; j ++) ans = min(ans, calc(j));
		reverse(a, a + n);
	}
	
	rep(i, n) {
		for(int j = min(MAGIC, i); j >= 1; j --) {
			int q = (a[i] - a[i - j]) / j;
			if(a[i] - a[i - j] == q * j) tmp[q] = max(tmp[q], dp[i][j]);
		}
		for(int j = min(MAGIC, n - 1 - i); j >= 1; j --) {
			int q = (a[i + j] - a[i]) / j;
			if(a[i + j] - a[i] == q * j) ans = min(ans, n - 1 - (dp[i + j][j] = max(dp[i + j][j], tmp[q] + 1)));
		}
		for(int j = min(MAGIC, i); j >= 1; j --) tmp[(a[i] - a[i - j]) / j] = 0;
	}
	printf("%d\n", ans);
	return 0;
}