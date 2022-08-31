#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[300005];
LL gcd(LL x, LL y)
{
	return y == 0 ? x : gcd(y, x % y);
}
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	LL tmp = 1;
	rep(i, n) {
		if(tmp <= 1000000000000LL) tmp = tmp / gcd(tmp, i + 2) * (i + 2);
		if(a[i] % tmp == 0) {
			printf("NO\n"); return;
		}
	}
	printf("YES\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}