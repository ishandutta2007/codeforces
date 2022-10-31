#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

map<ll,ll> best_cost;

struct event {
	bool type;
	ll t,val,dur;
	event(bool tp, int t, int v, int d):type(tp),t(t),val(v),dur(d){}
	bool operator<(const event& e) const {
		if(t != e.t) return t < e.t;
		return type < e.type;
	}
};

vector<event> v;

const ll INF = 1e16;

int main() {
	int n,x;
	cin >> n >> x;
	for(int i = 0; i < n; ++i) {
		int l,r,c;
		cin >> l >> r >> c;
		v.emplace_back(0,l,c,r-l+1);
		v.emplace_back(1,r,c,r-l+1);
	}
	sort(v.begin(),v.end());
	ll ans = INF;
	for(event &e : v) {
		if(e.type==0) {
			if(best_cost.count(x-e.dur)) {
				ans = min(ans,e.val + best_cost[x-e.dur]);
			}
		} else {
			ll q = INF;
			if(best_cost.count(e.dur))
				q = best_cost[e.dur];
			best_cost[e.dur] = min(q,(ll)e.val);
		}
	}
	if(ans==INF) cout << "-1\n";
	else cout << ans << "\n";
}