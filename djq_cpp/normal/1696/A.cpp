#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[2005], z;
void solve()
{
	scanf("%d%d", &n, &z);
	rep(i, n) scanf("%d", &a[i]);
	int ans = 0;
	rep(i, n) ans = max(ans, a[i] | z);
	printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}