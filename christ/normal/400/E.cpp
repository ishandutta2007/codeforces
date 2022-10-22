#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+2, BASE = 131, MOD = 1e9+7;
set<int> zero[17]; ll ans;
int a[MN];
inline ll c2 (ll x) {return x * (x+1) / 2;}
void update (int bit, int idx, bool go) {
	int lsz = idx - *(--zero[bit].lower_bound(idx)) - 1, rsz = *zero[bit].upper_bound(idx) - idx - 1;
	ans += (1 << bit) * (go ? 1 : -1) * (c2(rsz + lsz + 1) - c2(rsz) - c2(lsz));
	if (go) zero[bit].erase(idx);
	else zero[bit].insert(idx);
}
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	for (int j = 0; j < 17; j++) for (int i = 0; i <= n+1; i++) zero[j].insert(i);
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		for (int j = 0; j < 17; j++) if (a[i]>>j&1) update(j,i,1);
	}
	while (m--) {
		int x,v;
		scanf ("%d %d",&x,&v);
		for (int j = 0; j < 17; j++) if ((a[x]^v)>>j&1) update(j,x,v>>j&1);
		a[x] = v; printf ("%lld\n",ans);
	}
    return 0;
}