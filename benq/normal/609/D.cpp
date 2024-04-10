#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second

ll a, n,m,k,s,ans = 300000, i1, i2;
vector<pair<ll,ll>> costdol, gaddol, costpou, gadpou;

int b(int low, int high, int x, int y) {
	if (low == high) return low;
	int z = (low+high)/2;
	if (((ll)gaddol[x].f*costdol[z].f+(ll)gadpou[y].f*costpou[z].f) <= (ll)s) return b(low,z,x,y);
	else return b(z+1,high,x,y);
}

int main() {
	cin >> n >> m >> k >> s;
	costdol.pb(mp(1000000001,0)), costpou.pb(mp(1000000001,0));
	FOR(i,1,n+1) {
		int a;
		scanf("%d",&a);
		if (a<costdol[i-1].f) costdol.pb(mp(a,(ll)i));
		else costdol.pb(costdol[i-1]);
	}
	FOR(i,1,n+1) {
		cin >> a;
		if (a<costpou[i-1].f) costpou.pb(mp(a,(ll)i));
		else costpou.pb(costpou[i-1]);
	}
	costdol.pb(mp(n+1,0)), costpou.pb(mp(n+1,0));
	gaddol.pb(mp(0,0)), gadpou.pb(mp(0,0));
	FOR(i,1,m+1) {
		ll t,c;
		cin >> t >> c;
		if (t == 1) gaddol.pb(mp(c,i));
		else gadpou.pb(mp(c,i));
	}
	sort(gaddol.begin(),gaddol.end());
	F0R(i,gaddol.size()-1) gaddol[i+1].f += gaddol[i].f;
	sort(gadpou.begin(),gadpou.end());
	F0R(i,gadpou.size()-1) gadpou[i+1].f += gadpou[i].f;
	F0R(i,k+1) if (i < gaddol.size() && k-i < gadpou.size()) {
		int y = b(1,n+1,i,k-i);
		if (y<ans) {
			ans = y;
			i1 = i, i2 = k-i;
		}
	}
	if (ans > n) cout << -1;
	else {
		cout << ans << endl;
		F0R(i,i1) cout << gaddol[i+1].s << " " << costdol[ans].s << endl;
		F0R(i,i2) cout << gadpou[i+1].s << " " << costpou[ans].s << endl;
	}
	return 0;
}