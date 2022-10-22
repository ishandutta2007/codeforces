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
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
const ld INF = 1e16;

int n, x, y;
vector <pair<int, int>> Up, Down;
	
	

bool ok(ld R) {
	ld lewo = -INF;
	ld prawo = INF;
	for(auto it: Up) {
		ld x = it.fi;
		ld y = it.se;
		ld Y = abs(y - R);
		if(Y > R)
			return 0;
		ld daj = 2 * y * R - y * y;
		daj = fabs(daj);
		daj = sqrtl(daj);
		lewo = max(lewo, x - daj);
		prawo = min(prawo, x + daj);
	}
	return lewo <= prawo;
}

	
int main() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> x >> y;
		if(y < 0)
			Down.pb(mp(x, y));
		else
			Up.pb(mp(x, y));
	}
	
	if(ss(Down) && ss(Up)) {
		cout << -1;
		return 0;
	}
	
	if(ss(Down)) {
		for(auto &it: Down) 
			it.se *= -1;
		swap(Up, Down);
	}
		
	
	ld L = 0.0;
	ld R = 1e15;
	FOR(i, 1, 200) {
		ld M = (L + R) / 2;
		if(ok(M))
			R = M;
		else
			L = M;
	}
	
	cout << fixed << setprecision(13) << L << endl;
	
	
	
	
	
	return 0;
}