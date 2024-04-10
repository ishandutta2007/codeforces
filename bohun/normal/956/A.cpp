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
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define FORd(i, n) for(int i = n; 1 <= i; --i)
#define po(x) cerr << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;	
	
int n, m;
string s[55];	

vector <int> v[55];
bool done[55];

map <int, int> mapa;

bool cos(vector <int> &a, vector <int> &b) {
	mapa.clear();
	for(auto it: a)
		mapa[it] = 1;
	for(auto it: b) {
		if(mapa[it] == 1)
			return 1;
	}
	return 0;
}
	

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	bool ok = 1;
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
		s[i] = '2' + s[i];
		for(int j = 1; j <= m; ++j) {
			if(s[i][j] == '#')
				v[i].pb(j);
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			if(cos(v[i], v[j]) == 0)
				continue;
			if(v[i] != v[j])
				ok = 0;
		}
	}
	cout << (ok == 1 ? "Yes" : "No");
		
		
	
	
	
	
	
	return 0;
}