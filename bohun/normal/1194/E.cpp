#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;



using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;

bitset <5005> bit[5005];
int n;
int a, b, c, d;
vector <pair<int, pair<int, int>>> pion, poziom;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a >> b >> c >> d;
		int A = min(a, c);
		int C = max(a, c);
		int B = min(b, d);
		int D = max(b, d);
		if(a == c)
			pion.pb(mp(A, mp(B, D)));
		else
			poziom.pb(mp(B, mp(A, C)));
	}
	ll ans = 0;
	if(ss(pion) < ss(poziom)) {
		for(int i = 0; i < ss(pion); ++i)
			for(int j = 0; j < ss(poziom); ++j) {
				if(poziom[j].se.fi <= pion[i].fi && pion[i].fi <= poziom[j].se.se && pion[i].se.fi <= poziom[j].fi && poziom[j].fi <= pion[i].se.se)
					bit[i][j] = 1;
			}
		for(int i = 0; i < ss(pion); ++i)
		for(int j = i + 1; j < ss(pion); ++j) {
			int x = (bit[i] & bit[j]).count();
			ans += (ll) x * (x - 1) / 2;
		}
	}
	else {
		for(int i = 0; i < ss(poziom); ++i)
			for(int j = 0; j < ss(pion); ++j) {
				if(poziom[i].se.fi <= pion[j].fi && pion[j].fi <= poziom[i].se.se && pion[j].se.fi <= poziom[i].fi && poziom[i].fi <= pion[j].se.se)
					bit[i][j] = 1;
			}
		for(int i = 0; i < ss(poziom); ++i)
		for(int j = i + 1; j < ss(poziom); ++j) {
			int x = (bit[i] & bit[j]).count();
			ans += (ll) x * (x - 1) / 2;
		}
	}
		
	cout << ans;
			
		
		
		
	
	

	return 0;
}