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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
using namespace std;
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;
int n;
int xd;
int magic = 30000;

int main() {
	
	cin >> n;
	while(n--) {
		cin >> xd;
		int x = 1;
		while((ll) x * (x + 1) / 2 <= xd) {
			++x;
		}
		int ile = xd - x * (x - 1) / 2;
		cout << "133";
		FOR(i, 1, ile)
			cout << "7";
		FOR(i, 1, x - 2)
			cout << "3";
		cout << "7";
		cout << endl;
	}
		
		
		
	
	
	
 
    return 0;
}