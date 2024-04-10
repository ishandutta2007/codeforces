// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int nax = 1e6 + 111;

int n;
int per[nax];
vector <int> cycle;
int res[nax];
int byl[nax];

void dfs(int u) {
	cycle.pb(u);
	byl[u] = 1;
	if(!byl[per[u]])
		dfs(per[u]);
}

vector <vector <int> > v[nax];

vector <int> x, y;

int main() {
	scanf("%d", &n);
	FOR(i, n) scanf("%d", &per[i]);
	FOR(i, n) 
		if(!byl[i]) {
			cycle.clear();
			dfs(i);
			if(ss(cycle) & 1) {
				int j1 = ss(cycle) / 2;
				int j2 = (ss(cycle) + 1) / 2;
				for(int j = 0; j < j1; ++j)
					res[cycle[j]] = cycle[j + j2];
				for(int j = j1 + 1; j < ss(cycle); ++j)
					res[cycle[j]] = cycle[j - j1];
				res[cycle[j1]] = cycle[0];
			}
			else {
				v[ss(cycle)].pb(cycle);
			}
		}
	for(int i = 2; i < nax; ++i) {
		if(v[i].empty())
			continue;
		if(ss(v[i]) & 1) {
			printf("-1\n");
			return 0;
		}
		while(!v[i].empty()) {
			x = v[i].back();
			v[i].pop_back();
			y = v[i].back();
			v[i].pop_back();
			for(int j = 0; j < i; ++j)	
				res[x[j]] = y[j];
			for(int j = 0; j + 1 < i; ++j)
				res[y[j]] = x[j + 1];
			res[y[i - 1]] = x[0];
		}
	}
	FOR(i, n)
		printf("%d ", res[i]);
		
		
	
	return 0;
}