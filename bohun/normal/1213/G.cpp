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
#define bignum tuple <ll, ll, ll>
 
 
using namespace std;
const int nax = 2e5 + 11;
int p[nax], ile[nax];
vector <int> v[nax];
int n, a, b, c;
vector <int> q[nax];
vector <pair<int, int>> add[nax];
int T;
ll res = 0;
ll odp[nax];

int Find(int x) {
	if(x == p[x])
		return x;
	return p[x] = Find(p[x]);
}

void Onion(int x, int y) {
	x = Find(x);
	y = Find(y);
	if(x == y)
		return;
	res += (ll) ile[x] * ile[y];
	p[x] = y;
	ile[y] += ile[x];
}


int main() {
	ios;
	cin >> n >> T;
	FOR(i, 1, n - 1) {
		cin >> a >> b >> c;
		add[c].pb(mp(a, b));
	}
	FOR(i, 1, T) {
		cin >> c;
		q[c].pb(i);
	}
	
	FOR(i, 1, n) {
		p[i] = i;
		ile[i] = 1;
	}
	
	FOR(i, 1, nax - 1) {
		for(auto it: add[i])
			Onion(it.fi, it.se);
		for(auto it: q[i])
			odp[it] = res;
	}
	
	FOR(i, 1, T)
		cout << odp[i] << " ";
	
	
	
	return 0;
}