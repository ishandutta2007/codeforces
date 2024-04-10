#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int dp[200009], par[200009], n, a[200009];
map<int, pair<int, int>>M;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pair<int, int>G = M[a[i] - 1];
		if (G.first == 0) {
			dp[i] = 1; par[i] = -1;
		}
		else {
			dp[i] = G.first; par[i] = G.second;
		}
		M[a[i]] = make_pair(dp[i] + 1, i);
	}
	int maxn = 0, maxid = 0;
	for (int i = 1; i <= n; i++) {
		if (maxn < dp[i]) { maxn = dp[i]; maxid = i; }
	}
	vector<int>I; int cx = maxid;
	while (cx != -1) {
		I.push_back(cx);
		cx = par[cx];
	}
	reverse(I.begin(), I.end());
	cout << maxn << endl;
	for (int i = 0; i < I.size(); i++) {
		if (i)cout << " "; cout << I[i];
	}
	cout << endl;
	return 0;
}