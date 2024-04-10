#include<bits/stdc++.h>
using namespace std;
const int MN = 1e5+5, LOG = 60, MOD = 1e9+7, ADD = MN*MN*2;
using pii = pair<int,int>;
using ll = long long;
int bit[MN];
void inc (int i) {
	for (++i;i<MN;i+=i&-i)
		++bit[i];
}
void dec (int i ){
	for (++i;i<MN;i+=i&-i)
		--bit[i];
}
int query (int i) {
	int ret = 0;
	for(++i;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		int n,m;
		scanf ("%d %d",&n,&m);
		vector<int> a(n),b(m),idx(n+1);
		for (int i = 0; i <= n+1; i++) bit[i] = 0;
		for (auto &au : a) scanf ("%d",&au);
		for (int i = 0; i < n; i++) {
			idx[a[i]] = i;
			inc(i);
		}
		for (auto &au : b) scanf ("%d",&au);
		int mx = -1; ll ans = 0;
		for (auto &au : b) {
			if (mx < idx[au]) {
				mx = idx[au];
				dec(idx[au]);
				ans += query(idx[au])*2+1;
			} else {
				ans++;
				dec(idx[au]);
			}
		}
		printf ("%lld\n",ans);
	}
	return 0;
}