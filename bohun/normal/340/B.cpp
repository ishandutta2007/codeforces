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
// tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;		
const int nax = 311;
int n;
struct punkt {
	int x, y;
};
punkt t[nax];
ld best = 0;

int wek(punkt a, punkt b) {
	return a.x * b.y - a.y * b.x;
}

punkt sub(punkt a, punkt b) {
	return {a.x - b.x, a.y - b.y};
}

int main() {
	ios
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i].x >> t[i].y;
	}
	
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			if(i == j)
				continue;
			int lewo = -1;
			int prawo = -1;
			punkt ja = sub(t[j], t[i]);
			FOR(g, 1, n) {
				if(g == i || g == j)
					continue;
				punkt on = sub(t[g], t[i]);
				if(wek(ja, on) < 0)
					lewo = max(lewo, abs(wek(ja, on)));
				else
					prawo = max(prawo, abs(wek(ja, on)));
			}
			if(lewo != -1 && prawo != -1) {
				best = max(best,(ld) lewo / 2 + (ld) prawo / 2);
			}
		}
	}
	
	cout << fixed << setprecision(15) << best;
	
	
	
	
	return 0;
}