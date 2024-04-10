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
int T;
string a, b;

int main() {
	ios
	cin >> T;
	while(T--) {
		cin >> a >> b;
		int zera = 0;
		int wsk = ss(b) - 1;
		while(b[wsk] == '0') {
			--wsk;
			++zera;
		}
		wsk = ss(a) - 1;
		int i = 0;
		int res = 0;
		while(wsk >= 0) {
			++i;
			if(a[wsk] == '0') {
				--wsk;
				continue;
			}
			else if(i - 1 >= zera) {
				res = i - 1 - zera;
				break;
			}
			wsk--;
		}
		cout << res << endl;
	}
			
			
	
	
	
	
 
    return 0;
}