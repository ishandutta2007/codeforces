#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[1005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	sort(a, a + n);
	printf("%d\n", a[n - 1] + a[n - 2]);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}