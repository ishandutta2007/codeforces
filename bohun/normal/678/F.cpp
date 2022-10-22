#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int nax = 3e5 + 111, pier = 500;
const ll INF = 2e18;
struct line {
	int x, y;
};
struct cht {
	deque <line> s;
	ld prze(line a, line b) {
		return (ld) (b.y - a.y) / (a.x - b.x);
	}
	ll val(line a, int x) {
		return (ll) x * a.x + a.y;
	}
	void add(line a) {
		while(!s.empty() && s.back().x == a.x) {
			if(s.back().y <= a.y)
				s.pop_back();
			else
				return ;
		}
		while(ss(s) >= 2 && prze(a, s[ss(s) - 2]) <= prze(s.back(), s[ss(s) - 2]))
			s.pop_back();
		s.pb(a);
	}
	ll daj(int x) {
		while(ss(s) >= 2 && val(s[0], x) <= val(s[1], x))
			s.pop_front();
		return val(s[0], x);
	}
};

cht ja;

ll ans[nax];
vector <pair<int, int>> v;
int n;
struct query {
	int type, a, b, over;
};
query q[nax];
vector <int> dod;
vector <pair<query, int>> kub;

void solve(int l, int r) {
	ja.s.clear();
	dod.clear();
	kub.clear();
	
	for(auto it: v) {
		int nr = it.se;
		if(nr <= l && r <= q[nr].over)
			ja.add({q[nr].a, q[nr].b});
		else if((l <= nr && nr <= r) || (l <= q[nr].over && q[nr].over <= r))
			dod.pb(it.se);
	}
	
	for(int i = l; i <= r; ++i) {
		if(q[i].type == 3) {
			kub.pb(mp(q[i], i));
		}
	}
	sort(kub.begin(), kub.end(), [](pair<query, int> a, pair<query, int> b) {
		return a.fi.a < b.fi.a;
	});
	
	if(ss(ja.s)){
		for(auto it: kub) {
			ans[it.se] = ja.daj(it.fi.a);
		}
	}
	if(ss(dod)) {
		for(auto it: kub) {
			for(auto i: dod) {
				if(it.se >= i && it.se <= q[i].over)
					ans[it.se] = max(ans[it.se], (ll) q[i].a * it.fi.a + q[i].b);
			}
		}
	}
} 
			
	



int main() {
	ios
	cin >> n;
	FOR(i, 1, n) {
		cin >> q[i].type >> q[i].a;
		q[i].over = n;
		if(q[i].type == 1) {
			cin >> q[i].b;
			v.pb(mp(q[i].a, i));
		}
		if(q[i].type == 2) {
			q[q[i].a].over = i - 1;
		}
		if(q[i].type == 3) {
			ans[i] = -INF;
		}
	}
	
	sort(v.begin(), v.end());
	
	for(int i = 1; i <= n; i += pier) {
		solve(i, min(n, i + pier - 1));
	}
	
	FOR(i, 1, n) {
		if(q[i].type == 3) {
			if(ans[i] == -INF)
				cout << "EMPTY SET" << endl;
			else
				cout << ans[i] << endl;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}