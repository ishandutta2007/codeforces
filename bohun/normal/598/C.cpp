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
struct punkt {
	int x, y;
};
int n;
punkt t[111111];
int r[111111];

int up(punkt a) {
	if((a.y >= 0 && a.x >= 0) || (a.y > 0 && a.x <= 0))
		return 1;
	return -1;
}

ll wek(punkt a, punkt b) {
	return (ll) a.x * b.y - (ll) a.y * b.x;
}

ll skal(punkt a, punkt b) {
	return (ll) a.x * b.x + (ll) a.y * b.y;
}

bool cmp(int a, int b) {
	if(up(t[a]) != up(t[b]))
		return up(t[a]) > up(t[b]);
	return wek(t[b], t[a]) < 0;
}

ll dl(punkt a) {
	return sqrt((ll) a.x * a.x + a.y * a.y);
}

ld naj = 1000.0;
pair <int, int> res;

ld pi = acos(-1);
	

int main() {
	cin >> n;
	FOR(i, 1, n) {
		cin >> t[i].x >> t[i].y;
		r[i] = i;
	}
	sort(r + 1, r + n + 1, cmp);
	for(int i = 1; i <= n; ++i) {
		int x = r[i];
		int y = r[i + 1];
		if(i == n)
			y = r[1];
		ld kat = atan2(t[x].y, t[x].x);
		ld k = atan2(t[y].y, t[y].x);
		if(k < 0)
			k += 2 * pi;
		if(kat < 0)
			kat += 2 * pi;
		ld nowy = fabs(k - kat);
		nowy = nowy * 180 / pi;
		nowy = min(nowy, 360 - nowy);	
		if(nowy < naj) {
			naj = nowy;
			res = mp(x, y);
		}
		
	}
	
	cout << res.fi << " " << res.se;
		
	
	
	
	
	
	
	
	return 0;
}