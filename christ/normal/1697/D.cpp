#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 123;
int main () {
	int n; scanf ("%d",&n);
	map<pair<int,int>, int> memo;
	auto query = [&] (int l, int r) {
		if (l == r) return 1;
		if (memo.count({l,r})) return memo[{l,r}];
		assert(l < r);
		printf ("? 2 %d %d\n",l,r);
		fflush(stdout);
		int ret; scanf ("%d",&ret);
		memo[{l,r}] = ret;
		return ret;
	};
	auto qq = [&] (int i) {
		printf ("? 1 %d\n",i);
		fflush(stdout);
		char ret; scanf (" %c",&ret);
		return ret;
	};
	vector<char> s(n+1);
	set<int> ends;
	for (int i = 1; i <= n; i++) {
		vector<int> w(ends.begin(),ends.end());
		//we want the first point where query(j,i-1) == query(j,i)
		int low = 0, high = (int)w.size() - 1, mid, ans = -1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (query(w[mid],i) == (int)w.size() - mid) low = (ans = mid) + 1;
			else high = mid - 1;
		}
		if (ans == -1) s[i] = qq(i);
		else ans = w[ans], s[i] = s[ans], ends.erase(ans);
		ends.insert(i);
	}
	printf ("! ");
	for (int i = 1; i <= n; i++) printf ("%c",s[i]);
	printf ("\n");
	return 0;
}
//x=3, y=2