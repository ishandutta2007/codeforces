#pragma comment (linker, "/STACK:60000000")
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;


#define forn(i,n)  for (int i=0; i<int(n); ++i)
typedef long long int64;


const int MAXN = 100000;

int n, root, cnt[MAXN];
vector<int> g[MAXN];


bool read() {
	if (! (cin >> n))
		return false;
	forn(i,n) {
		scanf ("%d", &cnt[i]);
		g[i].clear();
	}
	forn(i,n-1) {
		int a, b;
		scanf ("%d%d", &a, &b);
		--a, --b;
		g[a].push_back (b);
		g[b].push_back (a);
	}
	cin >> root;
	--root;
	return true;
}

pair<int64,int> dfs (int v, int par = -1) {
	pair<int64,int> res;
	if (par != -1) {
		--cnt[v];
		++res.first;
	}

	int64 more = 0;
	vector<int64> vec;
	forn(i,g[v].size()) {
		int to = g[v][i];
		if (to == par)  continue;
		
		pair<int64,int> cur = dfs (to, v);
		vec.push_back (cur.first);
		more += cur.second;
	}
	sort (vec.begin(), vec.end());
	
	for (int i=(int)vec.size()-1; i>=0 && cnt[v]>0; --i) {
		res.first += vec[i] + 1;
		--cnt[v];
	}

	if (cnt[v]) {
		int add = (int) min (more, (int64) cnt[v]);
		cnt[v] -= add;
		more -= add;
		res.first += 2 * add;
	}

	res.second = cnt[v];
	
	return res;
}

void solve() {
	pair<int64,int> ans = dfs (root);
	cout << ans.first << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}