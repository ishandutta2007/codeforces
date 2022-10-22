#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int ll
char s[100004];
map<int,int> freq;
int32_t main () {
	int t;
	scanf ("%lld",&t);
	while (t--) {
		int n,x;
		scanf ("%lld %lld",&n,&x);
		scanf ("%s",s); freq.clear();
		int mx = 0, mn = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			cur += s[i] == '0' ? 1 : -1;
			++freq[cur];
			mx = max(mx,cur);
			mn = min(mn,cur);
		}
		ll ret = x == 0;
		if (!cur) {
			ret = mn<=x&&x<=mx?-1:0;
		} else if ((x < mn && cur > 0) || (x > mx && cur < 0)){
			ret = 0;
		} else if (cur > 0) { //prefixes increase
			//first time mx >= x, it works
			int omn = mn;
			int togo = (x-mx)/cur;
			togo = max(togo,0LL);
			mx += togo * cur; mn += togo * cur;
			if (mx < x) mx += cur, mn += cur;
			while (x >= mn) {
				if (freq.count(omn+(x-mn)))
					ret += freq[omn+(x-mn)];
				mn += cur;
				mx += cur;
			}
		} else {
			assert(cur<0);
			int omn = mn;
			int togo = (x-mn)/cur;
			togo = max(togo,0LL);
			mx += togo * cur; mn += togo * cur;
			if (mn > x) mn += cur, mx += cur;
			while (x <= mx) {
				if (freq.count(omn+(x-mn)))
					ret += freq[omn+(x-mn)];
				mn += cur;
				mx += cur;
			}
		}
		printf ("%lld\n",ret);
	}
	return 0;
}