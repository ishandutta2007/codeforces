#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f;

int n, p, k, x, y, a[100005], cnt[100005];
void solve()
{
	scanf("%d%d%d", &n, &p, &k); getchar();
	rep(i, k) cnt[i] = 0;
	rep1(i, n) a[i] = '1' - getchar();
	for(int i = n; i >= 1; i --) cnt[i] = a[i] + (i + k <= n ? cnt[i + k] : 0);
	
	scanf("%d%d", &x, &y);
	int ans = INF;
	rep1(i, n) if(i + p - 1 <= n) ans = min(ans, (i - 1) * y + cnt[i + p - 1] * x);
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}