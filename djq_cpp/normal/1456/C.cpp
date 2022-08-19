#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, k, c[500005];
LL ssum0[500005], ssum1[500005];

int main()
{
	scanf("%d%d", &n, &k); k ++;
	rep(i, n) scanf("%d", &c[i]);
	sort(c, c + n);
	
	for(int i = n - 1; i >= 0; i --) {
		ssum0[i] = ssum0[i + 1] + c[i];
		ssum1[i] = ssum1[i + 1] + ssum0[i + 1];
	}
	
	LL ans = ssum1[0], ca = 0;
	rep(i, n) {
		ca += 1LL * (i / k) * c[i];
		ans = max(ans, ca + ssum1[i + 1] + ((i / k) + 1) * ssum0[i + 1]);
	}
	printf("%lld\n", ans);
	return 0;
}