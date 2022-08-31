#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, b[200005];
vector<int> hv[600005];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &b[i]);
	
	LL ans = 0;
	rep(i, n) hv[b[i] - i + n - 1].push_back(i);
	rep(i, n + 400000) {
		LL ca = 0;
		rep(j, hv[i].size()) ca += b[hv[i][j]];
		ans = max(ans, ca);
	}
	printf("%lld\n", ans);
	return 0;
}