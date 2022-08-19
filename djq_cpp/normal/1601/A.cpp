#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005], c[35];
int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x % y);
}
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	memset(c, 0, sizeof(c));
	rep(i, n) rep(j, 30) if(a[i] >> j & 1) c[j] ++;
	int r = 0;
	rep(i, 30) r = gcd(r, c[i]);
	rep1(i, n) if(r % i == 0) printf("%d ", i); printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}