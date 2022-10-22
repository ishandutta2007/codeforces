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
const int nax = 1e5 + 111;
int n, a, b;
int t[nax];
map <int, int> mapka, Res, Poz;
int p[nax];
vector <int> Vec[nax];

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
	if(ss(Vec[x]) > ss(Vec[y]))
		swap(x, y);
	for(auto it: Vec[x])
		Vec[y].pb(it);
	p[x] = y;
}
	

int main() {
	ios;
	cin >> n >> a >> b;
	FOR(i, 1, n) {
		cin >> t[i];
		Poz[t[i]] = i;
		Vec[i].pb(t[i]);
		p[i] = i;
		mapka[t[i]] = 1;
	}
	
	FOR(i, 1, n) {
		if(mapka.find(a - t[i]) != mapka.end())
			Onion(i, Poz[a - t[i]]);
		if(mapka.find(b - t[i]) != mapka.end())
			Onion(i, Poz[b - t[i]]);
	}
	
	FOR(i, 1, n) {
		if(p[i] != i)
			continue;
		mapka.clear();
		for(auto it: Vec[i])
			mapka[it] = 1;
		
		bool ok = 1;
		for(auto it: Vec[i]) 
			ok &= mapka.find(a - it) != mapka.end();
	
		if(ok) {
			for(auto it: Vec[i])
				Res[Poz[it]] = 0;
			continue;
		}
		
		ok = 1;
		for(auto it: Vec[i]) 
			ok &= mapka.find(b - it) != mapka.end();
		
		if(ok) {
			for(auto it: Vec[i])
				Res[Poz[it]] = 1;
			continue;
		}
		
		cout << "NO\n";
		return 0;
	}
	
	cout << "YES\n";
	FOR(i, 1, n)
		cout << Res[i] << " ";
	
	
	
	
	
	return 0;
}