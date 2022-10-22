#include <bits/stdc++.h>
using namespace std;
const int MN = 3e5 + 5;
vector<int> adjA[MN], adjB[MN];
int st[MN], ed[MN], tt, ans = 0;
set<pair<int,int>> ranges;
void tour (int cur) {
	st[cur] = ++tt;
	for (int i : adjB[cur]) tour(i);
	ed[cur] = tt;
}
void dfs (int cur) {
	auto it = ranges.upper_bound(pair(st[cur],tt+1));
	pair<int,int> addBack = {-1,-1}, del = {-1,-1};
	if (it != ranges.end() && it->second <= ed[cur]) goto skip; // do nothing
	if (it != ranges.begin() && prev(it)->second >= st[cur]) {
		addBack = *prev(it);
		ranges.erase(prev(it));
	}
	ranges.insert({st[cur],ed[cur]});
	del = {st[cur],ed[cur]};
	skip:;
	ans = max(ans,(int)ranges.size());
	for (int i : adjA[cur]) {
		dfs(i);
	}
	if (addBack.first != -1) ranges.insert(addBack);
	if (del.first != -1) ranges.erase(del);
}
void solve () {
	int n; scanf ("%d",&n);
	tt = 0; ans = 0; ranges.clear();
	for (int i = 1; i <= n; i++) {
	    adjA[i].clear(), adjB[i].clear();
	    st[i] = ed[i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		int p; scanf ("%d",&p);
		adjA[p].push_back(i);
	}
	for (int i = 2; i <= n; i++) {
		int p; scanf ("%d",&p);
		adjB[p].push_back(i);
	}
	tour(1);
	dfs(1);
	printf ("%d\n",ans);
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}