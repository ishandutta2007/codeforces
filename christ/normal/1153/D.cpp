#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int MN = 3e5+3, BASE = 31, LOG = 20;
int op[MN];
int ans[MN];
int sz[MN];
vector<int> c[MN];
int dfs (int cur) { //returns best answer in terms of relative ordering of leaves
	if (c[cur].empty()) return ans[cur] = sz[cur] = 1;
	for (int i : c[cur]) dfs(i), sz[cur] += sz[i];
	sort(all(c[cur]),[&](int a, int b) {return ans[a]-sz[a] > ans[b]-sz[b];});
	if (op[cur] == 1) {
		return ans[cur] = sz[cur]+ans[c[cur][0]]-sz[c[cur][0]];
	} else {
		int sum = 0;
		for (int i : c[cur]) sum += sz[i]-ans[i]+1;
		return ans[cur] = sz[cur]-sum+1;
	}
}
int main() {
	int n;
	scanf ("%d",&n);
	for (int i = 1; i <= n; i++) scanf ("%d",&op[i]);
	for (int i = 2; i <= n; i++) {
		int p;
		scanf ("%d",&p);
		c[p].push_back(i);
	}
	printf ("%d\n",dfs(1));
	return 0;
}
//orz ninjaclasher