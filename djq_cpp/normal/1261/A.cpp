#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k;
char ch[2005], ret[2005];

void solve()
{
	scanf("%d%d%s", &n, &k, ch);
	rep(i, n) ret[i] = i & 1 ? ')' : '(';
	rep(i, n - k * 2 + 2) ret[i] = i < n / 2 - k + 1 ? '(' : ')';
	
	vector<PII> ans;
	rep(i, n) if(ch[i] != ret[i]) {
		for(int j = i; j < n; j ++) if(ch[j] == ret[i]) {
			ans.push_back(MP(i, j));
			reverse(ch + i, ch + j + 1);
			break;
		}
	}
	
	printf("%d\n", ans.size());
	rep(i, ans.size()) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}