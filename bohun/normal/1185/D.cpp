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

int n;
pair <int, int> t[nax];
vector <int> dif;
map <int, int> mapa;
int rozne = 0;
int roz[nax];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> t[i].fi, t[i].se = i;
	if(n == 2 || n == 3) {
		cout << 1;
		return 0;
	}
		
	sort(t + 1, t + n + 1);
	
	for(int i = n; 2 <= i; --i) {
		roz[i] = t[i].fi - t[i - 1].fi;
		mapa[roz[i]]++;
	}
	for(int i = 1; i <= n; ++i) {
		if(i == 1) {
			mapa[roz[i + 1]]--;
			if(mapa[roz[i + 2]] == n - 2) {
				cout << t[i].se;
				return 0;
			}
			mapa[roz[i + 1]]++;
		}
		if(i == n) {
			mapa[roz[i]]--;
			if(mapa[roz[i - 1]] == n - 2) {
				cout << t[i].se;
				return 0;
			}
			mapa[roz[i]]++;
		}
		else if(i != 1){
			int sum = roz[i] + roz[i + 1];
			mapa[roz[i + 1]]--;
			mapa[roz[i]]--;
			if(mapa[sum] == n - 3) {
				cout << t[i].se;
				return 0;
			}
			mapa[roz[i + 1]]++;
			mapa[roz[i]]++;
		}
	}
	cout << -1;
				
			
	
	
	
			
			
			
		
			
		
		
			
						
	
	
				
	
	
	return 0;
}