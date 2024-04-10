/*#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<string>
#include<bitset>
#include<algorithm>
#include<vector>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int color[200001], n, ans = 0;
vi adj[200001];

void dfs(int par, int node) {
	int ccolor = 0;
	for (int i: adj[node]) if (i != par) {
		ccolor ++;
		while (ccolor == color[par] || ccolor == color[node]) ccolor++;
		color[i] = ccolor;
		dfs(node,i);
	}
}

int main() {
	cin >> n;
	F0R(i,n-1) {
		int x,y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	color[1] = 1;
	dfs(0,1);
	FOR(i,1,n+1) ans = max(ans,color[i]);
	cout << ans << "\n";
	FOR(i,1,n+1) cout << color[i] << " ";
}