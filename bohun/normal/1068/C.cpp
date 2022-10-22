#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 200005, inf = 1e9 + 1;

vector <pair<int, int>> res[105];

int pier = 1005;
int licz[105];


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int a, b;
		cin >> a >> b;
		int x = min(a, b);
		int y = max(a, b);
		int px = licz[x];
		int py = licz[y];
		int X = x;
		int Y = y;
		x = pier * x;
		y = pier * y;
		res[X].pb(mp(x + licz[X], x + licz[X] - 1));
		res[Y].pb(mp(y + licz[Y], y + licz[Y] - 1));
		res[X].pb(mp(x + licz[X], x + licz[X]));
		res[Y].pb(mp(y + licz[Y], y + licz[Y]));
		res[X].pb(mp(y + py, x + px));
		licz[X]++;
		licz[Y]++;
		
	}
	for(int i = 1; i <= n; ++i) {
		if(ss(res[i]) == 0)
			res[i].pb(mp(pier * i, pier * i));
	}
	
	for(int i = 1; i <= n; ++i) {
		cout << ss(res[i]) << endl;
		for(auto it: res[i]) {
			cout << it.fi << " " << it.se << endl;
		}
	}
	
	
	
    return 0;
}