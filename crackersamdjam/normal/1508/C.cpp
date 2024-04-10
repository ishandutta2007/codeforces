#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

ll ans;
int n, m, sum, par[MM];
vector<array<int, 3>> old, edges;
set<pair<int, int>> st;
set<int> nvis;

void init(){
	iota(par, par+MM, 0);
}

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

bool connected(int a, int b){
	return find(a) == find(b);
}

void merge(int a, int b){
	par[find(a)] = find(b);
}

void dfs(int cur){
	nvis.erase(cur);
	int pre = -1;
	while(1){
		int u = *nvis.upper_bound(pre);
		pre = u;
		if(u > n) break;
		if(!st.count({cur, u})){
			edges.push_back({0, cur, u});
			dfs(u);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;
	for(int i = 0,a,b,c; i < m; i++){
		cin>>a>>b>>c;
		sum ^= c;
		old.push_back({c, a, b});
		st.insert({a, b});
		st.insert({b, a});
	}

	init();
	sort(all(old));
	for(auto [c, a, b]: old){
		a = find(a), b = find(b);
		if(a != b){
			merge(a, b);
			edges.push_back({c, a, b});
		}
	}
	
	ll tot = (ll)n*(n-1)/2 - m;

	if(tot <= n-1){
		init();
		for(int i = 1; i <= n; i++){
			for(int j = 1; j < i; j++){
				if(!st.count({i, j})){
					edges.push_back({0, i, j});
					merge(i, j);
				}
			}
		}
		init();
		sort(all(edges));
		for(auto [c, a, b]: edges){
			if(!connected(a, b)){
				merge(a, b);
				ans += c;
			}
			else{
				sum = min(sum, c);
			}
		}
		cout<<ans+sum<<'\n';
		return 0;
	}

	for(int i = 1; i <= n+1; i++)
		nvis.insert(i);

	for(int i = 1; i <= n; i++){
		if(nvis.count(i)){
			dfs(i);
		}
	}

	init();
	sort(all(edges));
	for(auto [c, a, b]: edges){
		if(!connected(a, b)){
			merge(a, b);
			ans += c;
		}
	}
	cout<<ans<<'\n';
}
/*

5 6
2 3 11
5 3 7
1 4 10
2 4 46
4 3 8
2 5 6

ans = 6

*/