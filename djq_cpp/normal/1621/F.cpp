#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a, b, c;
char S[100005];
int c00;
multiset<int> gd, bd;

LL solve(int x)
{
	LL ret = 0;
	if(x == 1) {
		if(c00 == 0) return 0;
		c00 --; ret = max(ret, solve(0) + b); c00 ++;
	} else {
		if(c00 > 0) {
			if(!gd.empty() && *gd.rbegin()) {
				int t = *gd.lower_bound(1);
				gd.erase(gd.find(t)); gd.insert(t - 1);
				ret = max(ret, solve(1) + a);
				gd.insert(t); gd.erase(gd.find(t - 1));
			} else if(!bd.empty() && *bd.rbegin()) {
				int t = *bd.lower_bound(1);
				bd.erase(bd.find(t)); bd.insert(t - 1);
				ret = max(ret, solve(1) + a);
				bd.insert(t); bd.erase(bd.find(t - 1));
			} else if(!gd.empty() && !(*gd.begin())) {
			    gd.erase(gd.find(0)); c00 ++;
			    ret = max(ret, solve(1) - c);
			    gd.insert(0); c00 --;
		    } else if(!bd.empty() && !(*bd.begin())) {
			    bd.erase(bd.find(0));
			    ret = max(ret, solve(1) - c);
			    bd.insert(0);
		    }
		} else {
			if(!gd.empty() && *gd.rbegin() || !bd.empty() && *bd.rbegin()) ret = max(ret, (LL)a);
	    	if(!gd.empty() && !(*gd.begin())) {
			    gd.erase(gd.find(0)); c00 ++;
			    ret = max(ret, solve(1) - c);
			    gd.insert(0); c00 --;
		    }
	    }
	}
	return ret;
}

void solve()
{
	scanf("%d%d%d%d%s", &n, &a, &b, &c, S);
	int bg = 0;
	c00 = 0; gd.clear(); bd.clear();
	rep(i, n) if(S[i] == '1') {
		if(bg < i) (bg == 0 ? bd : gd).insert(i - bg - 1);
		bg = i + 1; c00 += i > 0 && S[i - 1] == '1';
	}
	if(bg < n) bd.insert(n - bg - 1);
	printf("%lld\n", max(solve(0), solve(1)));
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}