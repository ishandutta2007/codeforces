#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[505];
vector<PII> ans;
vector<int> ls;
void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	
	ans.clear(); ls.clear();
	while(n != 0) {
		int j = -1;
		for(int i = n - 2; i >= 0; i --) if(a[i] == a[n - 1]) {
			j = i; break;
		}
		if(j == -1) {
			printf("-1\n"); return;
		}
		ls.push_back((n - j - 1) * 2);
		rep(i, n - j - 2) ans.push_back(MP(j + i, a[n - 2 - i]));
		reverse(a + j, a + n - 1);
		n -= 2;
	}
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()) printf("%d %d\n", ans[i].first, ans[i].second);
	printf("%d\n", (int)ls.size());
	for(int j = (int)ls.size() - 1; j >= 0; j --) printf("%d%c", ls[j], " \n"[j == 0]);
	
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}