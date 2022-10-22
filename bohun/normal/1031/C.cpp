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

const int nax = 100005;


int a, b;
vector <int> c, d;
bool bylo[1000005];

bool f(int x) {
	c.clear();
	d.clear();
	int X = a;
	int Y = b;
	for(int i = 1; i <= x; ++i) {
		bylo[i] = 0;
	}
	ll SUM = 1ll * x * (x + 1) / 2;
	while(X > 0 && x) {
		if(X >= x) {
			c.pb(x);
			SUM -= x;
			bylo[x] = 1;
			X -= x;
			x--;
		}
		else {
			c.pb(X);
			bylo[X] = 1;
			SUM -= X;
			break;
		}
	}
	if(SUM > Y)
		return 0;
	

	for(int i = 1; i <= x; ++i) {
		if(!bylo[i]) {
			d.pb(i);
		}
	}
	return 1;
}
		
			

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> a >> b;
	int l = 0, r = 1e6;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(f(mid))
			l = mid;
		else
			r = mid - 1;
	}
	f(l);
	
	cout << ss(c) << endl;
	for(auto it: c) {
		cout << it << " " ;
	}
	cout << endl;
	cout << ss(d) << endl;
	for(auto it: d) {
		cout << it << " ";
	}
	
	
	
	
	
	
	
	
				
	
	
    return 0;
}