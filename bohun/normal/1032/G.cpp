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

const int nax = 3e5 + 11, pod = (1 << 19), LOG = 19, INF = 1e9;
int n, r[nax];
pair <int, int> jump[nax][LOG + 1];
pair <int, int> d[2 * pod][LOG + 1];


void init() {
	FOR(j, 0, LOG)
	FOR(i, 1, 2 * pod - 1) 
		d[i][j] = mp(INF, -INF);
}

void add(int x, pair<int, int> val, int lvl) {
	x += pod;
	d[x][lvl] = val;
	x /= 2;
	while(x) {
		d[x][lvl].fi = min(d[2 * x][lvl].fi, d[2 * x + 1][lvl].fi);
		d[x][lvl].se = max(d[2 * x][lvl].se, d[2 * x + 1][lvl].se);
		x /= 2;
	}
}

pair <int, int> query(int l, int r, int lvl) {
	r += 1;
	pair<int, int> res = mp(INF, -INF);
	for(l += pod, r += pod; l < r; l /= 2, r /= 2) {
		if(l & 1) {
			res.fi = min(res.fi, d[l][lvl].fi);
			res.se = max(res.se, d[l][lvl].se);
			l += 1;
		}
		if(r & 1) {
			r -= 1;
			res.fi = min(res.fi, d[r][lvl].fi);
			res.se = max(res.se, d[r][lvl].se);
		}
	}
	return res;
}
	
	
void reduce(pair<int, int> &x) {
	x.fi = max(x.fi, 1);
	x.se = min(x.se, 3 * n);
}

int main() {	
	init();
	ios;
	cin >> n;
	FOR(i, 1, n) {
		int a;
		cin >> a;
		r[i] = r[i + n] = r[i + n + n] = a;
	}
	
	if(n == 1) {
		cout << 0;
		return 0;
	}
	
	int m = 3 * n;
	
	FOR(i, 1, m) {
		jump[i][0] = mp(i - r[i], i + r[i]);
		reduce(jump[i][0]);
		add(i, jump[i][0], 0);
	}
	
	FOR(j, 1, LOG) {
		
		
		FOR(i, 1, m) {
			jump[i][j] = query(jump[i][j - 1].fi, jump[i][j - 1].se, j - 1);
			reduce(jump[i][j]);
			add(i, jump[i][j], j);
		}
	}
	
	FOR(i, n + 1, 2 * n) {
		int ans = 0;
		int L = i;
		int R = i;
		for(int j = LOG; 0 <= j; --j) {
			int nL = query(L, R, j).fi;
			int nR = query(L, R, j).se;
			if(nR - nL < n - 1) {
				ans += (1 << j);
				L = nL;
				R = nR;
			}
		}
		
		cout << ans + 1 << " ";
	}
			 
		
	
	
	
	
	return 0;
}