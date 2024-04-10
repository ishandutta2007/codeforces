#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[200005];
PII c[200005];
vector<int> ans[200005];
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	
	rep1(i, n) ans[i].clear();
	rep1(i, n) c[i] = MP(0, i);
	rep(i, n) c[a[i]].first ++;
	sort(c + 1, c + 1 + n);
	for(int i = c[n].first; i >= 1; i --) {
		int j;
		for(j = n; j >= 1 && c[j].first >= i; j --) ;
		for(int k = n; k > j; k --) ans[c[k].second].push_back(k == j + 1 ? c[n].second : c[k - 1].second);
	}
	rep(i, n) {
		printf("%d ", ans[a[i]].back()); ans[a[i]].pop_back();
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}