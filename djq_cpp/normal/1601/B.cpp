#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[300005], b[300005];
int dp[300005], pre[300005], pv[300005];
set<int> R;
queue<int> que;
int main()
{
	scanf("%d", &n);
	rep1(i, n) {
		scanf("%d", &a[i]); a[i] = i - a[i];
	}
	rep1(i, n) {
		scanf("%d", &b[i]); b[i] += i;
	}
	
	rep(i, n) dp[i] = -1;
	dp[n] = 0;
	que.push(n);
	rep(i, n) R.insert(i);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		while(true) {
			set<int>::iterator it = R.lower_bound(a[v]);
			if(it == R.end() || *it > v) break;
			if(dp[b[*it]] == -1) {
				pre[b[*it]] = v; pv[b[*it]] = *it;
				dp[b[*it]] = dp[v] + 1; que.push(b[*it]);
			}
			R.erase(it);
		}
	}
	
	if(dp[0] == -1) printf("-1\n");
	else {
		printf("%d\n", dp[0]);
		vector<int> ans;
		for(int i = 0; i != n; i = pre[i]) ans.push_back(pv[i]);
		for(int i = (int)ans.size() - 1; i >= 0; i --) printf("%d ", ans[i]);
	}
	return 0;
}