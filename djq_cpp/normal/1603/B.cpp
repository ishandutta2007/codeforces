#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

LL a, b;
void solve()
{
	scanf("%lld%lld", &a, &b);
	if(a > b) printf("%lld\n", a + b);
	else printf("%lld\n", (b / a * a + b) / 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}