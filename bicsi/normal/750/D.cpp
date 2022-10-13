#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"


#define int long long

set<long long> DP;
vector<int> Ch;
set<long long> Sol;

int dx[] = {-1, -1, -1,  0,  1,  1,  1,  0},
	dy[] = {-1,  0,  1,  1,  1,  0, -1, -1};

long long has(vector<int> x) {
	long long h = 0;
	for(auto y : x)
		h = h * 391827 + y;
	return h;
}

void dfs(int x, int y, int d, int t) {
	d %= 8;
	if(d < 0) d += 8;

	x += dx[d];
	y += dy[d];

	auto ch_time = lower_bound(Ch.begin(), Ch.end(), t);
	if(ch_time == Ch.end()) return;

	if(!DP.insert(has({x, y, d, t})).second) 
		return;
	Sol.insert(has({x, y}));

	if(t == *ch_time) { dfs(x, y, d - 1, t + 1); dfs(x, y, d + 1, t + 1); }
	else dfs(x, y, d, t + 1);
}

int32_t main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	int n;
	cin >> n;

	Ch.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> Ch[i];
	}
	for(int i = 1; i < n; ++i)
		Ch[i] += Ch[i - 1];

	dfs(0, 0, 3, 1);
	cout << Sol.size() << endl;

	return 0;
}