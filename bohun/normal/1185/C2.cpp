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

const int mod = 1e9 + 7, nax = 200005;

int n, m;
int t[nax];
int res[nax], ile[nax];

ll sum = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> t[i];
		if(sum + t[i] <= m) {
			ile[t[i]]++;
			sum += t[i];
			continue;
		}
		ll so_far = 0;
		ll get = 0;
		for(int j = 100; 1 <= j; --j) {
			ll all = ile[j] * j + so_far;
			//cout << j << " " << sum + t[i] - all << " " << so_far << " " << ile[j] << endl;
			if(sum + t[i] - all > m) {
				get += ile[j];
				so_far += j * ile[j];
				continue;
			}
			long double x = (ld) (sum + t[i] - m - so_far) / j;
			res[i] = ceil(x) + get;
			break;
		}
		ile[t[i]]++;
		sum += t[i];
	}
	
	for(int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
	}
			
			
			
		
			
		
		
			
						
	
	
				
	
	
	return 0;
}