#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, m, k;
int a[3505];
void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	k = min(k, m - 1);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, m) a[i] = max(a[i], a[i + n - m]);
	n = m;
	int ans = 0;
	for(int i = 0; i <= k; i ++) {
		int cmin = INF;
		for(int j = i; j < n - k + i; j ++) cmin = min(cmin, a[j]);
		ans = max(ans, cmin);
	}
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}