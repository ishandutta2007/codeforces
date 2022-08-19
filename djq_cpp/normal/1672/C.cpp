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
	int mn = n, mx = -1;
	rep(i, n - 1) if(a[i] == a[i + 1]) {
		mn = min(mn, i); mx = max(mx, i);
	}
	printf("%d\n", mx > mn ? max(mx - mn - 1, 1) : 0);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}