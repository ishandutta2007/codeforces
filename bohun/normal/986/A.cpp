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

const int nax = 100005, inf = 1e9;

vector <int> v[nax];

int n, m, a, b, k, s;
int col[nax];
int ile[nax];
int res[nax];
int t[nax][105];
int byl[nax][105];

queue <pair<int, int>> q;

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m >> k >> s;
	
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= k; ++j)
			t[i][j] = inf;
	
	for(int i = 1; i <= n; ++i) {
		cin >> col[i];
		t[i][col[i]] = 0;
		byl[i][col[i]] = 1;
		ile[i] = 1;
		q.push(mp(i, col[i]));
	}
	
	for(int i = 1; i <= m; ++i) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	while(!q.empty()) {
		pair<int, int> x = q.front();
		q.pop();
		//cout << x.fi << " " << x.se << endl;
		for(auto it: v[x.fi]) {
			if(ile[it] == s || byl[it][x.se] == 1)
				continue;
			t[it][x.se] = t[x.fi][x.se] + 1;
			ile[it]++;
			byl[it][x.se] = 1;
			q.push(mp(it, x.se));
			res[it] += t[it][x.se];
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		cout << res[i] << " ";
	}
				
	
	
	
	
	
	
	
	
	
	
				
	
	
	return 0;
}