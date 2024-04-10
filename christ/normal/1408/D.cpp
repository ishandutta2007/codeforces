#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main () {
	int n,m;
	scanf ("%d %d",&n,&m);
	vector<array<int,2>> robbers(n), searchlights(m);
	for (auto &a : robbers) scanf ("%d %d",&a[0],&a[1]);
	for (auto &a : searchlights) scanf ("%d %d",&a[0],&a[1]);
	sort(searchlights.begin(),searchlights.end());
	vector<array<int,2>> cmp;
	for (auto &a : searchlights) {
		while (!cmp.empty() && a[1] >= cmp.back()[1])
			cmp.pop_back();
		cmp.push_back(a);
	}
	const int MN = 1e6 + 5;
	multiset<int> st; vector<vector<array<int,2>>> changes(MN);
	for (auto &a : robbers) {
		int lstneed = -1; array<int,2> lst;
		for (auto &b : cmp) if (b[0] >= a[0]) {
			if (~lstneed) {
				changes[lst[0] - a[0] + 1].push_back({lstneed,max(0,b[1] - a[1] + 1)});
				lstneed = max(0,b[1] - a[1] + 1);
			} else {
				st.insert(lstneed = max(0,b[1] - a[1] + 1));
			}
			lst = b;
		}
		if (~lstneed) {
			changes[lst[0] - a[0] + 1].push_back({lstneed,0});
		} else {
			st.insert(0);
		}
	}
	int ret = MN * 2;
	for (int t = 0; t < MN; t++) {
		for (auto &au : changes[t]) {
			st.erase(st.find(au[0]));
			st.insert(au[1]);
		}
		ret = min(ret,t + *st.rbegin());
	}
	printf ("%d\n",ret);
	return 0;
}