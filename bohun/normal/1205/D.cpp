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

const int nax = 1000 + 11;

int n, a, b;
vector <int> v[nax];
int siz[nax];

void dfs(int u, int p) {
	siz[u] = 1;
	for(auto it: v[u]) {
		if(it != p) {
			dfs(it, u);
			siz[u] += siz[it];
		}
	}
}

int daj(int u, int p) {
	for(auto it: v[u]) 
		if(it != p && siz[it] * 2 > siz[1])
			return daj(it, u);
	return u;
}

vector <int> x, y;
vector <pair<int, int>> z;
bool ok[nax];

int K;

vector <pair<pair<int, int>, int>> res;

int cena, reszta;

void solve(int u, int p, int odl, int type) {
	res.pb(mp(mp(u, p), K - odl));
	odl = K;
	
	if(type == 0)
		K++;
	else
		K += cena + 1;
	
	
	for(auto it: v[u]) 
		if(it != p)
			solve(it, u, odl, type);
}

int main() {
	cin >> n;
	FOR(i, 1, n - 1) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs(1, 0);
	
	int c = daj(1, 0);
	
	dfs(c, 0);
	
	for(auto it: v[c]) 
		z.pb(mp(siz[it], it));
		
	sort(z.begin(), z.end());
	
	reverse(z.begin(), z.end());
	
	int mam = 0;
	int val = 2 * n * n / 9;
	int p = 0;
	
	FOR(i, 1, n / 2) {
		p = i;
		if(i * (n - i - 1) >= val)
			break;
	}
	
	for(auto it: z) {
		mam += it.fi;
		ok[it.se] = 1;
		if(mam >= p)
			break;
	}
	
	for(auto it: v[c]) {
		if(ok[it]) 
			x.pb(it);
		else
			y.pb(it);
	}
	
	cena = mam;
	reszta = n - 1 - mam;
	if(reszta < cena) {
		swap(cena, reszta);
		swap(x, y);
	}
	
	K = 1;
	for(auto it: x) {
		solve(it, c, 0, 0); //cout << it << "A " << " " << cena << endl;
	}
	
	K = cena + 1;
	for(auto it: y)
		solve(it, c, 0, 1);
		
	for(auto it: res)
		cout << it.fi.fi << " " << it.fi.se << " " << it.se << endl;
	
	
	
	
	
	
	return 0;
}