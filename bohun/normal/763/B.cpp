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
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

int n, a, b, c, d;		

int main() { 
	cin >> n;
	cout << "YES\n";
	FOR(i, 1, n) {
		cin >> a >> b >> c >> d;
		a += 1000000000;
		b += 1000000000;
		cout << 1 + 2 * (a & 1) + (b & 1) << endl;
	}
	
	
	
	
	return 0;
}