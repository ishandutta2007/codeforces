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

using namespace std;
using namespace __gnu_pbds;

// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;



const int nax = 5005, inf = 1e9 + 1, mod = 998244353;

int n;
int t[nax];

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	ll a, b, c;
	cin >> a >> b >> c;
	ll res = a / c + b / c;
	ll d = a % c;
	ll e = b % c;
	if(d + e < c) {
		cout << res << " " << 0;
		return 0;
	}
	cout << res + 1 << " ";
	if(d < e) {
		cout << c - e << endl;
	}
	else {
		cout << c - d;
	}
	
	
	
				
			
	
	
				
	
	
    return 0;
}