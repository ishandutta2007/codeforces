#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

const int N = 1000000+10;
int sum[N];
char s[N];
vector<int> vec, pos;
int n, m;

int dp[N];

#define sz(x) ((int)(x.size()))

bool can(int T) {
//	cout << "T = " << T << endl;
	for (int i = 1; i <= sz(vec); i++) {
		int p = vec[i-1];
		if (dp[i-1] == sz(pos)) return 1;
		dp[i] = dp[i-1];
		if (sum[p] <= dp[i-1]) dp[i] = max(dp[i], sum[min(n, p+T)]);
		if (sum[max(p-T-1, 0)] <= dp[i-1]) dp[i] = max(dp[i], sum[p]);
		if (i > 1 && sum[max(p-T-1, 0)] <= dp[i-2]) dp[i] = max(dp[i], sum

[min(n, vec[i-2]+T)]);
//		cout << dp[i] << ' ';
	}
//	cout << endl;
	return dp[sz(vec)] == sz(pos);
}

int main() {
	scanf("%d%s", &n, s+1);
	for (int i = 1; i <= n; i ++) {
		if (s[i] == 'P') m++, vec.push_back(i);
		sum[i] = sum[i-1] + (s[i] == '*');
		if (s[i] == '*') pos.push_back(i);
	}
	if (m == 1) {
		int lp = 0, lt = 0, rp = 0, rt = 0;
		for (int i = vec[0] + 1; i <= n; i ++) {
			if (s[i] == '*') lp++, lt = i - vec[0];
		}
		for (int i = vec[0] - 1; i > 0; i --) {
			if (s[i] == '*') rp++, rt = vec[0] - i;
		}
		PII ret = PII(-lp, lt);
		ret = min(ret, PII(-rp, rt));
		printf("%d %d\n", -ret.first, ret.second);
		return 0;
	}
	printf("%d ", pos.size());
	int st = 0, en = 1e6;
	while (en - st > 1) {
		int mid = st + en >> 1;
		if (can(mid)) en = mid;
		else st = mid;
	}
	cout << en << endl;
	return 0;
}