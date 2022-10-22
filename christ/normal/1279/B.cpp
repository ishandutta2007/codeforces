#include<bits/stdc++.h>
using namespace std;
const int MN = 81, LOG = 60, MOD = 1e9+7, ADD = MN*MN*2;
using pii = pair<int,int>;
using ll = long long;
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n,s;
		scanf ("%d %d",&n,&s);
		vector<int> a(n);
		for (auto &au : a) scanf ("%d",&au);
		vector<ll> psa;
		for (auto &au : a) psa.push_back((psa.empty() ? 0 : psa.back())+au);
		if (psa[n-1] <= s) {printf ("0\n"); continue;} 
		int ans = 0, w = -1;
		for (int i = 0; i < n; i++) {
			ll cntl = i?psa[i-1]:0;
			if (cntl > s) continue;
			int ret = i;
			ret += max(0,upper_bound(psa.begin(),psa.end(),psa[i]+s-cntl)-psa.begin()-i-1);
			if (ret > ans) {
				ans = ret;
				w = i;
			}
		}
		printf ("%d\n",w+1);
	}
	return 0;
}