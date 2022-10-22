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

const int LOG = 23, nax = (1 << 23) + (1 << 22);

int v[nax];
int n, m, ans;
bitset <nax> odw;

queue <int> q;

void dfs(int node) {
	q.push(node);
	while(!q.empty()) {
		node = q.front();
		q.pop();
		odw[node] = 1;
		if(v[node] != -1 && !odw[v[node]]) {
			odw[v[node]] = 1;
			q.push(v[node]);
		}
		if(node < (1 << m)) {
			for(int j = 0; j < m; ++j) {
				if(((1 << j) & node) && !odw[((1 << j) ^ node)]) {
					odw[((1 << j) ^ node)] = 1;
					q.push((1 << j) ^ node);
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
		
	cin >> m >> n;
	
	for(int i = 0; i < nax; ++i)
		v[i] = -1;
	
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		int x = (1 << m) + i;
		int com = (1 << m) - 1 - a;
		v[x] = com;
		v[a] = x;
	}
	
	for(int i = 0; i < n; ++i) {
		int x = (1 << m) + i;
		if(odw[x])
			continue;
		ans++;
		dfs(x);
	}
	
	cout << ans;
	
			
	
	
	
				
	
	
	return 0;
}