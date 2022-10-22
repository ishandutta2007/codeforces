#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 4e5+5, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
int a[MN];
int color[MN];
int main() {
	int n,k;
	scanf ("%d %d",&n,&k);
	set<pii> best;
	set<int> pos;
	for (int i = 1; i <= n; i++) {
		scanf ("%d",&a[i]);
		best.insert({a[i],i});
		pos.insert(i);
	}
	int turn = 1;
	while (!best.empty()) {
		int take = best.rbegin()->second;
		color[take] = turn;
		best.erase({a[take],take});
		pos.erase(take);
		int cur = take;
		for (int cnt = 1; cnt <= k; cnt++) {
			auto it = pos.upper_bound(cur);
			if (it == pos.end()) break;
			cur = *it;
			color[cur] = turn;
			best.erase({a[cur],cur});
			pos.erase(cur);
		}
		cur = take;
		for (int cnt = 1; cnt <= k; cnt++) {
			auto it = pos.lower_bound(cur);
			if (it == pos.begin()) break;
			cur = *(--it);
			color[cur] = turn;
			best.erase({a[cur],cur});
			pos.erase(cur);
		}
		turn = 3-turn;
	}
	for (int i = 1; i <= n; i++) putchar('0'+color[i]);
	printf ("\n");
    return 0;
}