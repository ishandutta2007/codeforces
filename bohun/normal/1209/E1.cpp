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
#define bignum vector <int>
 
 
using namespace std;
const int nax = 111;

int T, n, m, a;
int dp[(1 << 5)][2];
deque <int> v[nax];

int main() {
	cin >> T;
	while(T--) {
		cin >> n >> m;
		
		FOR(i, 1, m) 
			while(ss(v[i]))
				v[i].pop_front();
		
		FOR(i, 1, n) {
			FOR(j, 1, m) {
				cin >> a;
				v[j].pb(a);
			}
		}
		FOR(i, 0, (1 << n) - 1)
			dp[i][0] = 0;
		
		FOR(i, 1, m) {
			FOR(g, 0, (1 << n) - 1)
				dp[g][1] = 0;
			FOR(j, 1, n) {
				int b = v[i].front();
				v[i].pop_front();
				v[i].pb(b);
				FOR(maska, 0, (1 << n) - 1) {
					FOR(pop, 0, (1 << n) - 1) {
						if((pop & maska) != pop)
							continue;
						int RES = dp[pop][0];
						FOR(bit, 0, n - 1)
							if(((1 << bit) & maska) && !((1 << bit) & pop))
								RES += v[i][bit];
								
						//assert(v[i][0] != v[i][1]);
								
						dp[maska][1] = max(dp[maska][1], RES);
					}
				}
			}
			
			FOR(g, 0, (1 << n) - 1)
				dp[g][0] = dp[g][1];
			
		}
		
		cout << dp[(1 << n) - 1][0] << endl;
	}
								
						
						
				
	
	
	
	
	return 0;
}