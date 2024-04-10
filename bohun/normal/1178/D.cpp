#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Plus, Minus;		
const int nax = 1000001, mod = 998244353;
int n;
vector <int> v[nax];
set <int> s[2];

int prime(int x) {
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0)
			return 0;
	}
	return 1;
}

bool byl[100005];

int main() {
	cin >> n;
	for(int i = 1; i < n; ++i) 
		v[i].pb(i + 1);
	v[1].pb(n);
	int res = n;
	
	int X = n;
	while(!prime(X))
		X++;
		
	int i = n;
	while(res != X) {
		while(byl[i] == 1)
			--i;
		byl[i] = byl[i - 2] = 1;
		v[i].pb(i - 2);
		res++;
	}
		
	
	cout << res << endl;
	for(int i = 1; i <= n; ++i) {
		for(auto it: v[i]) {
			cout << i << " " << it << endl;
		}
	}
	
	
		
		
		
	
	
	
	
	
	return 0;
}