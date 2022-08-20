#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ook order_of_key
#define fbo find_by_order

using namespace std;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define f first
#define s second
#define all(x) begin(x), end(x)
#define rsz resize

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;

int n;
vector<array<ll,3>> v;

typedef pair<ll,int> T;

void solve() {
	cin >> n; v.rsz(n);
	priority_queue<T,vector<T>,greater<T>> start;
	start.push({4e18,-1});
	set<T> cur;
	priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> ins;
	F0R(i,n) {
		F0R(j,3) cin >> v[i][j];
		v[i][1] -= v[i][2];
		start.push({v[i][0]+v[i][2],i});
		ins.push({v[i][0],-1,i});
		ins.push({v[i][1],1,i});
	}
	ll ti = 0, ans = 0;
	while (1) {
		while (sz(ins) && mp(ins.top()[0],ins.top()[1]) < mp(ti,0LL)) {
			int ind = ins.top()[2];
			if (ins.top()[1] == -1) cur.insert({v[ind][2],ind});
			else cur.erase({v[ind][2],ind});
			ins.pop();
		}
		while (sz(start) && start.top().f-v[start.top().s][2] <= ti) start.pop();
		// cout << "AH " << sz(cur) << " " << sz(start) << "\n";
		if (sz(cur) && ti+cur.begin()->f < start.top().f) {
			ll d = cur.begin()->f;
			ll num = max(1LL,(ins.top()[0]-ti)/d);
			ti += num*d; ans += num;
			// ti+d*? <= ins.top()[0]
		} else {
			 if (start.top().f == 4e18) break;
			 ti = start.top().f; ans ++;
		}
	}
	cout << ans << "\n";
}
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
}