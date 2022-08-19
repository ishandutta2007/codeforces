#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

void solve()
{
	LL a, b, c;
	scanf("%lld%lld%lld", &a, &b, &c);
	printf("%lld %lld %lld\n", a + b + c, b + c, c);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}