#include <bits/stdc++.h>
using namespace std;
const int MN = 5e3 + 5;
int grid[505][505];
void solve () {
	int m,k; scanf ("%d %d",&m,&k);
	vector<int> freq(k+1);
	for (int i = 1; i <= k; i++) scanf ("%d",&freq[i]);
	int mxfreq = *max_element(freq.begin(),freq.end());
	auto check = [&] (int n) {
		int maxCanHave = ((n+1)/2) * (n + n/2);
		if (m > maxCanHave) return false;
		int maxOfOne = n * ((n+1)/2);
		if (mxfreq > maxOfOne) return false;
		return true;
	};
	int low = 1, high = 500, mid, ans = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (check(mid)) high = (ans = mid) - 1;
		else low = mid + 1;
	}
	vector<int> have;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < freq[i]; j++) have.push_back(i);
	}
	sort(have.begin(),have.end(),[&](int a, int b) {return freq[a] > freq[b] || (freq[a] == freq[b] && a < b);});
	vector<array<int,2>> order; int n = ans;
	for (int i = 1; i <= n; i += 2) {
		for (int j = 2; j <= n; j += 2) order.push_back({i,j});
	}
	for (int i = 1; i <= n; i += 2) {
		for (int j = 1; j <= n; j += 2) order.push_back({i,j});
	}
	for (int i = 2; i <= n; i += 2) {
		for (int j = 1; j <= n; j += 2) order.push_back({i,j});
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			grid[i][j] = 0;
	for (int i = 0; i < m; i++) grid[order[i][0]][order[i][1]] = have[i];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			assert((grid[i][j] == 0 || grid[i][j] != grid[i+1][j+1]) && (grid[i+1][j] == 0 || grid[i+1][j] != grid[i][j+1]) && ((!!grid[i][j]) + (!!grid[i+1][j]) + (!!grid[i][j+1]) + (!!grid[i+1][j+1]) <= 3));
		}
	}
	printf ("%d\n",ans);
	for (int i = 1; i <= ans; i++) {
		for (int j = 1; j <= ans; j++) {
			printf ("%d%c",grid[i][j]," \n"[j==ans]);
		}
	}
}
int main () {
	int t; scanf ("%d",&t);
	while (t--) solve();
	return 0;
}