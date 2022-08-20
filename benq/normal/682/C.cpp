#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define M 100000

ll n,a[M], maxdist[M], ans = 0;
pair<int,ll> parent[M];
bool mark[M];
vector<pair<int,ll>> child[M], adj[M];

void rem(int node) {
	mark[node] = 1;
	for (pii i: child[node]) rem(i.f);
}

void fine(int par, int node) {
	maxdist[node] = max((ll)0,maxdist[par]+parent[node].s);
	if (maxdist[node]>a[node]) rem(node);
	else for (pii i: child[node]) fine(node,i.f);
}

void root(int par, int node) {
	for (pii i: adj[node]) if (i.f != par) {
		parent[i.f] = mp(node,i.s);
		child[node].pb(i), root(node,i.f);
	}
}

void finish() {
	int ans = 0;
	F0R(i,n) ans += mark[i];
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin >> n;
	F0R(i,n) cin >> a[i];
	F0R(i,n-1) {
		int p,c;
		cin >> p >> c;
		adj[i+1].pb(mp(p-1,c)), adj[p-1].pb(mp(i+1,c));
	}
	root(0,0), fine(0,0), finish();
	// if (a[0] == 386) F0R(i,n) cout << maxdist[i] << " ";
}