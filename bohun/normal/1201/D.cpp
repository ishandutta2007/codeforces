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
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

const int nax = 200000 + 111, INF = 1e9 + 111, mod = 1e9 + 7;

int n, m, k, q;
vector <int> row[nax];
int lewo[nax], prawo[nax];
int a, b;
vector <int> col;
vector <pair <int, ll>> opt;
int last = -1;

int small(int x) {
	auto it = upper_bound(col.begin(), col.end(), x);
	if(it == col.begin())
		return -1;
	--it;
	return *it;
}

int big(int x) {
	auto it = lower_bound(col.begin(), col.end(), x);
	if(it == col.end())
		return -1;
	return *it;
}

int odl(int x, int y) {
	return abs(x - y);
}

map <int, int> mapka;

int main() {
	ios
	cin >> n >> m >> k >> q;
	FOR(i, 1, n) {
		lewo[i] = INF;
		prawo[i] = -INF;
	}
	FOR(i, 1, k) {
		cin >> a >> b;
		row[a].pb(b);
		lewo[a] = min(lewo[a], b);
		prawo[a] = max(prawo[a], b);
		last = max(last, a);
	}
	FOR(i, 1, q) {
		cin >> a;
		col.pb(a);
	}
	sort(col.begin(), col.end());
	opt.pb(mp(1, 0));
	FOR(i, 1, last) {
		if(lewo[i] == INF) {
			if(i != 1) {
				for(auto &it: opt)
					it.se++;
				continue;
			}
			else {
				opt.clear();
				opt.pb(mp(col[0], 1 + (col[0] - 1)));
				continue;
			}
		}
		
		vector <pair<int, ll>> best;
		for(auto it: opt) {
			int x = it.fi;
			ll cena = it.se;
			ll dod = 0;
			if(x >= lewo[i] && x >= prawo[i]) {
				cena += 1;
				cena += (x - lewo[i]);
				int Lewo = small(lewo[i]);
				int Prawo = big(lewo[i]);
				//cat(Lewo);
				//cat(Prawo);
				if(last != i) {
					dod = lewo[i] - Lewo;
				}
				else {
					dod = 0;
				}
				if(Lewo != -1)
					best.pb(mp(Lewo, cena + dod));
				if(last != i) {
					dod = Prawo - lewo[i];
				}
				else {
					dod = 0;
				}
				if(Prawo != -1)
					best.pb(mp(Prawo, cena + dod));
			}
			else if(lewo[i] >= x && prawo[i] >= x) {
				cena += 1;
				cena += (prawo[i] - x);
				int Lewo = small(prawo[i]);
				int Prawo = big(prawo[i]);
				if(last != i) {
					dod = prawo[i] - Lewo;
				}
				else {
					dod = 0;
				}
				if(Lewo != -1)
					best.pb(mp(Lewo, cena + dod));
				if(last != i) {
					dod = Prawo - prawo[i];
				}
				else {
					dod = 0;
				}
				if(Prawo != -1)
					best.pb(mp(Prawo, cena + dod));
			}
			else {
				// 1. 
				ll ccc = cena + 1 + 2 * odl(x, lewo[i]) + odl(x, prawo[i]);
				int Lewo = small(prawo[i]);
				int Prawo = big(prawo[i]);
				if(last != i) {
					dod = prawo[i] - Lewo;
				}
				else {
					dod = 0;
				}
				if(Lewo != -1)
					best.pb(mp(Lewo, ccc + dod));
				if(last != i) {
					dod = Prawo - prawo[i];
				}
				else {
					dod = 0;
				}
				if(Prawo != -1)
					best.pb(mp(Prawo, ccc + dod));
					
				// 2.
				
				ccc = cena + 1 + odl(x, lewo[i]) + 2 * odl(x, prawo[i]);
				Lewo = small(lewo[i]);
				Prawo = big(lewo[i]);
				
				if(last != i) {
					dod = lewo[i] - Lewo;
				}
				else {
					dod = 0;
				}
				
				if(Lewo != -1)
					best.pb(mp(Lewo, ccc + dod));
				if(last != i) {
					dod = Prawo - lewo[i];
				}
				else {
					dod = 0;
				}
				
				
				if(Prawo != -1)
					best.pb(mp(Prawo, ccc + dod));
			}
		}
			sort(best.begin(), best.end(), [](pair<int, ll> a, pair<int, ll> b) {
				return a.se < b.se;
			});
			mapka.clear();
			opt.clear();
			for(auto it: best) {
				if(mapka.find(it.fi) == mapka.end()) {
					opt.pb(it);
				}
				mapka[it.fi] = 1;
			}
			
		
		
		
	
		
	
	}
	
	ll XD = 1e18;
	for(auto it: opt)
		XD = min(XD, it.se);
	cout << XD - 1;
	
	
 
    return 0;
}