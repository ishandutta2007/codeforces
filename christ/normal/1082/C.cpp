#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5, M = 2e4 + 5;
int main () {
	int n,m; scanf ("%d %d",&n,&m);
	vector<vector<int>> with(m+1);
	for (int i = 1; i <= n; i++) {
		int s,r; scanf ("%d %d",&s,&r);
		with[s].push_back(r);
	}
	vector<long long> at(n+1);
	for (int i = 1; i <= m; i++) {
		sort(with[i].rbegin(),with[i].rend());
		int cnt = (int)with[i].size();
		long long sofar = 0;
		for (int j = 0; j < cnt; j++) {
			sofar += with[i][j];
			if (sofar >= 0) at[j] += sofar;
		}
	}
	long long ret=  0;
	for (int i = 0; i <= n; i++) {
		ret = max(ret,at[i]);
	}
	printf ("%lld\n",ret);
	return 0;
}