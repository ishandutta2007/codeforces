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
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;

const int nax = 200005, mod = 1e9 + 7;

int n;
int ile[nax];
int a, b;

				
int main() {
	scanf("%d", &n);
	for(int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		ile[a]++;
		ile[b]++;
	}
	bool ok = 1;
	for(int i = 1; i <= n; ++i) {
		ok &= (ile[i] != 2);
	}
	printf(ok == 1 ? "YES" : "NO");
	
	
		
	
	
	
		
	return 0;
}