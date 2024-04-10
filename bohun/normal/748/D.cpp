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
  
using namespace std;

string s, odw;
int n, k, a;

map <string, vector <int> > m;
map <string, bool> used;
map <string, int> cost;
int best = 0; 
int sum = 0;

int main() {
	ios;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> s >> a;
		m[s].pb(a);
	}
	
	for(auto &it : m) {
		sort(it.se.begin(), it.se.end());
		reverse(it.se.begin(), it.se.end());
	}
	
	for(auto it : m) {
		if(used[it.fi])
			continue;
		odw = it.fi;
		reverse(odw.begin(), odw.end());
		
		if(m.find(odw) == m.end())
			continue;
		
		if(odw == it.fi) {
			int pos = 0;
			while(pos + 1 < ss(it.se)) {
				if(it.se[pos] + it.se[pos + 1] < 0)
					break;
				best += it.se[pos] + it.se[pos + 1];
				cost[odw] += it.se[pos] + it.se[pos + 1];
				pos += 2;
			}
		}
		else {
			FOR(j, 0, min(ss(m[odw]) - 1, ss(it.se) - 1)) {
				int a = m[odw][j];
				int b = it.se[j];
				if(a + b < 0)
					break;
				best += a + b;
				cost[it.fi] += a + b;
				cost[odw] += a + b;
			}
		}
		used[odw] = 1;
	}
	
	sum = best;
	
	for(auto it : m) {
		odw = it.fi;
		reverse(odw.begin(), odw.end());
		
		if(m.find(odw) == m.end())
			continue;
			
		int nowy = sum - cost[it.fi];
		if(odw == it.fi) {
			nowy += m[it.fi][0];
			int pos = 1;
			while(pos + 1 < ss(m[it.fi])) {
				int a = m[it.fi][pos];
				int b = m[it.fi][pos + 1];
				if(a + b < 0)
					break;
				nowy += a + b;
				pos += 2;
			}
		}
		best = max(best, nowy);
	}
	printf("%d", best);
			
			
	
	
	
	return 0;
}