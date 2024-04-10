#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ld long double

const int MOD = 1000000007;

int n,x1,y11,x2,y2; 
pair<ld,ld> ans = {0,MOD};
double rx, ry, vx, vy, err = 0.0000001;

bool ok(ld t) {
	ld tx = rx+vx*t, ty = ry+vy*t;
	if (tx>x1 && tx<x2 && ty>y11 && ty<y2) return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x1 >> y11 >> x2 >> y2;
	cout << fixed << setprecision(15);
	F0R(i,n) {
		cin >> rx >> ry >> vx >> vy;
		vector<ld> z; z.pb(0); z.pb(MOD);
		if (vx != 0) if ((x1-rx)/vx >= 0) z.pb((x1-rx)/vx);
		if (vx != 0) if ((x2-rx)/vx >= 0) z.pb((x2-rx)/vx);
		if (vy != 0) if ((y11-ry)/vy >= 0) z.pb((y11-ry)/vy);
		if (vy != 0) if ((y2-ry)/vy >= 0) z.pb((y2-ry)/vy);
		sort(z.begin(),z.end());
		bool flag = 0;
		F0R(i,z.size()-1) if (ok((z[i]+z[i+1])/2)) {
			ans.f = max(ans.f,z[i]);
			ans.s = min(ans.s,z[i+1]);
			flag = 1;
		}
		if (!flag) {
			cout << -1;
			return 0;
		}
	}
	if (ans.f>=ans.s) cout << -1;
	else cout << ans.f;
}