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

		
		

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int a, b, c, ans = 0;
	cin >> a >> b >> c;
	while(c--) {
		ans += (a + b) * 2 - 4;
		a -= 4;
		b -= 4;
		if(a <= 0 || b <= 0	)
			break;
	}
	cout << ans;
	
	
	
				
	
	
    return 0;
}