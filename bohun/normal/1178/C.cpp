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
int a, b;

int main() {
	cin >> a >> b;
	int s = a + b;
	int res = 1;
	for(int i = 1; i <= s; ++i)
		res = (ll) res * 2 % mod;
	cout << res;
	
	
	
	
	
	
	return 0;
}