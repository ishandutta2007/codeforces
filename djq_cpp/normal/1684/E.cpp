#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, a[100005];
map<int, int> occ;

void solve()
{
	scanf("%d%d", &n, &k); k = min(n, k);
	rep(i, n) scanf("%d", &a[i]);
	
	occ.clear();
	rep(i, n) occ[a[i]] ++;
	int tmp = -1, cnt = 0, ans = 0;
	rep(i, 2 * n + 5) if(occ.find(i) == occ.end()) {
		if(cnt == k) {
			tmp = i; break;
		}
		cnt ++;
	}
	vector<int> ret;
	for(map<int, int>::iterator it = occ.begin(); it != occ.end(); it ++)
	if(it->first >= tmp) ret.push_back(it->second);
	sort(ret.begin(), ret.end());
	rep(i, ret.size()) if(cnt >= ret[i]) cnt -= ret[i];
	else ans ++;
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}