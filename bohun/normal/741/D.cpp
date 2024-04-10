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

const int nax = 500005;

int dp[nax];
int n, a, b;
vector <pair<int, int>> v[nax];
int t[5000005];
int h[nax], d[nax], siz[nax], in[nax], out[nax], fre = 0, seg[nax], val[nax];
			
		
void dfs(int node, int bit) {
	val[node] = bit;
	seg[fre] = node;
	in[node] = fre++;
	siz[node] = 1;
	for(auto it: v[node]) {
		h[it.fi] = h[node] + 1;
		dfs(it.fi, (bit ^ (1 << it.se)));
		siz[node] += siz[it.fi];
		if(siz[it.fi] > siz[d[node]])
			d[node] = it.fi;
	}
	out[node] = fre - 1;
}

void akt(int node, int s) {
	if(t[val[s]] != 0)
		dp[node] = max(dp[node], t[val[s]] + h[s] - 2 * h[node]);
	for(int i = 0; i < 22; ++i) {
		int nowa = ((1 << i) ^ val[s]);
		if(t[nowa] != 0)
			dp[node] = max(dp[node], t[nowa] + h[s] - 2 * h[node]);
	}
}
	

vector <int> e;

void go(int node, int keep = 1) {
	for(auto it: v[node]) {
		if(it.fi != d[node]) {
			go(it.fi, 0);
			dp[node] = max(dp[node], dp[it.fi]);
		}
	}
	
	if(d[node]) {
		go(d[node], 1);
		dp[node] = max(dp[node], dp[d[node]]);
	}
	
	for(auto it: v[node]) {
		if(it.fi != d[node]) {
			for(int i = in[it.fi]; i <= out[it.fi]; ++i) {
				e.pb(seg[i]);
				akt(node, seg[i]);
			}
			for(auto it: e) {
				t[val[it]] = max(t[val[it]], h[it]);
			}
			e.clear();
		}
	}
	t[val[node]] = max(t[val[node]], h[node]);
	akt(node, node);
	
	if(!keep) {
		for(int i = in[node]; i <= out[node]; ++i) {
			t[val[seg[i]]] = 0;
		}
	}
}
		
	


int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 2; i <= n; ++i) {
		char c;
		cin >> a >> c;
		b = c - 'a';
		v[a].pb(mp(i, b));
	}
	
	h[1] = 1;
	
	dfs(1, 0);
	
	go(1);
	
	for(int i = 1; i <= n; ++i) {
		cout << dp[i] << " ";
	}
	
	
	
				
	
	
    return 0;
}