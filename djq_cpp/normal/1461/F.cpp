#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const LL INF = 0x3f3f3f3f3f3f3f3f;

int n, a[100005];
char s[5], ans[100005];
bool hv[128];

vector<int> pos;
int pre[65];
LL dp[65];
void solve(int l, int r)
{
	while(l <= r && a[l] == 1) {
		ans[l + 1] = '+'; l ++;
	}
	while(l <= r && a[r] == 1) {
		ans[r] = '+'; r --;
	}
	if(l > r) return;
	
	LL cur = 1;
	for(int i = l; i <= r; i ++)
	cur = cur > INF / a[i] ? INF : cur * a[i];
	if(cur >= INF) {
		for(int i = l + 1; i <= r; i ++) ans[i] = '*';
		return;
	}
	
	for(int i = l + 1; i <= r; i ++) ans[i] = '+';
	
	pos.clear();
	for(int i = l; i <= r; i ++) if(a[i] != 1) pos.push_back(i);
	dp[0] = 0;
	rep(i, pos.size()) {
		dp[i + 1] = -INF;
		LL coef = 1;
		for(int j = i; j >= 0; j --) {
			coef *= a[pos[j]];
			LL ndp = coef + dp[j] + (j == 0 ? 0 : pos[j] - pos[j - 1] - 1);
			if(ndp > dp[i + 1]) {
				dp[i + 1] = ndp; pre[i + 1] = j;
			}
		}
	}
	for(int i = pos.size(); i != 0; i = pre[i])
	for(int j = pos[pre[i]] + 1; j <= pos[i - 1]; j ++) ans[j] = '*';
}

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	scanf("%s", s);
	for(int i = 0; s[i]; i ++) hv[s[i]] = true;
	if(hv['+']) hv['-'] = false;
	if(!hv['*']) {
		if(hv['+']) rep(i, n) ans[i] = '+';
		else rep(i, n) ans[i] = '-';
	} else if(hv['+']) {
		int pre = -1;
		rep(i, n) if(a[i] == 0) {
			ans[i] = ans[i + 1] = '+';
			solve(pre + 1, i - 1);
			pre = i;
		}
		solve(pre + 1, n - 1);
	} else if(hv['-']) {
		rep(i, n) ans[i] = '*';
		rep(i, n) if(a[i] == 0) {
			ans[i] = '-'; break;
		}
	} else rep(i, n) ans[i] = '*';
	
	rep(i, n) {
		if(i != 0) printf("%c", ans[i]);
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}