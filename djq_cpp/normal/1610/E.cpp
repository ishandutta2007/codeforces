#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	int ans = 0;
	rep(i, n) if(i == 0 || a[i] != a[i - 1]) {
		int j = lower_bound(a, a + n, a[i] + 1) - a, ca = j - i + (j < n);
		while(j < n && (a[j] - a[i]) * 2 <= a[n - 1] - a[i]) {
			int nj = lower_bound(a, a + n, a[i] + (a[j] - a[i]) * 2) - a;
			j = nj; ca ++;
		}
		ans = max(ans, ca);
	}
	printf("%d\n", n - ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}