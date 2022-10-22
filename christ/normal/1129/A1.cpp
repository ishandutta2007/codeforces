#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 5e5+3, MOD = 1e9+7;
vector<int> go[MN];
int mn[MN];
ll from[MN];
int main() {
	int n,m;
	scanf ("%d %d",&n,&m);
	while (m--){
		int a,b;
		scanf ("%d %d",&a,&b);
		go[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) if (!go[i].empty()){
		mn[i] = INT_MAX;
		for (int j : go[i]) {
			int need = j-i;
			if (need < 0) need += n;
			mn[i] = min(mn[i],need);
		}
		from[i] = n * 1LL * (go[i].size()-1) + mn[i];
	}
	for (int i = 1; i <= n; i++) {
		ll ret = 0;
		for (int j = 1; j <= n; j++) if (go[j].size()) {
			int need = j-i;
			if (need < 0) need += n;
			ret = max(ret,from[j] + need);
		}
		printf ("%lld%c",ret," \n"[i==n]);
	}
    return 0;
}