#include <bits/stdc++.h>
 
using namespace std;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

long long tot, n, m, par[150001], sz[150001];
 
int gp(int a) {
	if (par[a] != par[par[a]]) par[a] = gp(par[a]);
	return par[a];
}
 
void unite(int a, int b) {
	a = gp(a), b = gp(b);
	if (a != b) par[b] = a, sz[a] += sz[b];
}
 
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,n+1) par[i] = i, sz[i] = 1;
	F0R(i,m) {
		int a,b; cin >> a >> b;
		unite(a,b);
	}
	FOR(i,1,n+1) if (i == gp(i)) tot += sz[i]*(sz[i]-1)/2;
	if (tot == m) cout << "YES";
	else cout << "NO";
}