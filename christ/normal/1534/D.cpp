#include <bits/stdc++.h>
using namespace std;
const int MN = 2e3 + 5, MOD = 1e9 + 7;
int n;
vector<int> get (int r) {
	printf ("? %d\n",r); fflush(stdout);
	vector<int> ret(n+1);
	for (int i = 1; i <= n; i++) scanf ("%d",&ret[i]);
	return ret;
}
int dp[MN][3];
set<int> adj[MN];
int main () {
	scanf ("%d",&n);
	vector<int> d = get(1);
	int mx = *max_element(d.begin()+1,d.end());
	vector<vector<int>> at(mx+1);
	for (int i = 1; i <= n; i++) at[d[i]].push_back(i);
	for (int i : at[1]) {
		adj[1].insert(i);
		adj[i].insert(1);
	}
	int sum = 0;
	for (int i = 2; i <= mx; i += 2) sum += (int)at[i].size();
	if (sum + 1 <= (n+1)/2) {
		for (int i = 2; i <= mx; i += 2) {
			for (int j : at[i]) {
				vector<int> got = get(j);
				for (int k = 1; k <= n; k++) if (got[k] == 1) {
					adj[k].insert(j); adj[j].insert(k);
				}
			}
		}
	} else {
		for (int i = 1; i <= mx; i += 2) {
			for (int j : at[i]) {
				vector<int> got = get(j);
				for (int k = 1; k <= n; k++) if (got[k] == 1) {
					adj[k].insert(j); adj[j].insert(k);
				}
			}
		}
	}
	printf ("!\n"); fflush(stdout);
	for (int i = 1; i <= n; i++) for (int j : adj[i]) if (j >= i) {
		printf ("%d %d\n",i,j); fflush(stdout);
	}
	return 0;
}
//aba aba
//012 345

//ab a ba
//01 2 34