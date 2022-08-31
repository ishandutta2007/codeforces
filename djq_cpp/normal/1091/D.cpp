#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n;
int revs[1000005];

int main()
{
	scanf("%d", &n);
	revs[0] = 1;
	rep(i, n) revs[i + 1] = 1LL * revs[i] * (n - i) % MOD;
	
	LL ans = 0;
	rep1(i, n) ans = (1LL * ans + revs[n] - revs[i] + MOD) % MOD;
	printf("%lld\n", (ans + revs[n]) % MOD);
	return 0;
}