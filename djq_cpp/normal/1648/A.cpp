#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m;
vector<int> hv[200005];
LL calc(int id)
{
	sort(hv[id].begin(), hv[id].end());
	int len = hv[id].size();
	LL ret = 0;
	rep(i, len) ret += (2 * i - len + 1LL) * hv[id][i];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, n) rep(j, m) {
		int x;
		scanf("%d", &x);
		hv[x].push_back(i); hv[x + 100000].push_back(j);
	}
	
	LL ret = 0;
	rep1(i, 200000) ret += calc(i);
	printf("%lld\n", ret);
	return 0;
}