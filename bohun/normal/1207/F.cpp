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
const int nax = 500005, p = 43, mod = 1e9 + 7, pp = 37;

const int magic = 450;

int n;
int x, y;
int t[nax];
int odp[magic + 1][magic + 1];
vector <pair<int, int>> add;

void pre() {
	FOR(i, 1, magic) {
		for(auto it: add) {
			odp[(it.fi % i)][i] += it.se;
			if(i == 1)
				t[it.fi] += it.se;
		}
	}
	
	add.clear();
}
	

		
int main() {
	cin >> n;
	pre();
	
	while(n--) {
		int type;
		cin >> type >> x >> y;
		if(type == 1) {
			add.pb(mp(x, y));
			if(ss(add) >= magic)
				pre();
		}
		else {
			swap(x, y);
			if(y > magic) {
				int res = 0;
				int u = x;
				while(u <= 500000) {
					res += t[u];
					u += y;
				}
				for(auto it: add) {
					if(it.fi % y == x)
						res += it.se;
				}
				cout << res << endl;
			}
			else {
				int res = odp[x][y];
				for(auto it: add)
					if(it.fi % y == x)
						res += it.se;
				cout << res << endl;
			}
		}
	}
		
	
		
	
	
	return 0;
}