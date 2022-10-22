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

const int mod = 1e9 + 7, nax = 100005;

int n, m, v;

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	
	int down = 1;
	int up = n;
	while(up >= down) {
		if(up == down)
			break;
		if(v == 0) {
			for(int i = 1; i <= m; ++i) {
				printf("%d %d\n", down, i);
				printf("%d %d\n", up, m - i + 1);
				
			}
		}
		else {
			for(int i = m; 1 <= i; --i) {
				printf("%d %d\n", down, i);
				printf("%d %d\n", up, m - i + 1);
			}
		}
		up--;
		down++;
		v ^= 1;
	}
	if(up == down) {
		for(int i = 1; i <= m / 2; ++i) {
			printf("%d %d\n", up, i);
			printf("%d %d\n", up, m - i + 1);
		}
		if(m % 2 == 1) {
			cout << up << " " << m / 2 + 1 << endl;
		}
	}
		
			
		
	
	
	
	
	
	
				
	
	
	return 0;
}