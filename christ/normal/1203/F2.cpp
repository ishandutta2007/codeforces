#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using pib = pair<int,bool>;
using ll = long long;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#ifdef fread_unlocked
#define fread fread_unlocked
#define fwrite fwrite_unlocked
#endif
#define mp make_pair
#define lc ind<<1
#define rc ind<<1|1
const int MN = 105, MK = 6e4 + 5, MOD = 1e9+7, BASE = 31, MASK = (1 << 10) - 1;
int dp[MK];
int main () {
	int n,cur;
	scanf ("%d %d",&n,&cur); vector<pii> pos, neg = {{-1,-1}};
	for (int i = 1; i <= n; i++) {
		int a,b;
		scanf ("%d %d",&a,&b);
		if (b >= 0) pos.emplace_back(a,b);
		else neg.emplace_back(a,b);
	}
	int ret = 0;
	sort(all(pos));
	for (pii p : pos) if (cur >= p.first) cur += p.second, ++ret;
	sort(1+all(neg),[](const pii &a, const pii &b) {return a.first + a.second > b.first + b.second;});
	memset(dp,-63,sizeof dp);
	dp[cur] = 0;
	for (int i = 1; i < (int)neg.size(); i++) {
		int lose = -neg[i].second, need = max(lose,neg[i].first);
		for (int j = need; j <= cur; j++) dp[j-lose] = max(dp[j-lose],dp[j] + 1);
	}
	int extra = 0;
	for (int i = 0; i <= cur; i++) extra = max(extra,dp[i]);
	printf ("%d\n",ret + extra);
	return 0;
}