#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, dp[100009], l[100009], r[100009];

vector<int>LIS(vector<int>a) {
	vector<int>G(a.size() + 1, 0), H;

	for (int i = 0; i < a.size(); i++) {
		int pos1 = upper_bound(H.begin(), H.end(), a[i]) - H.begin();
		if (pos1 == H.size()) H.push_back(a[i]);
		else H[pos1] = a[i];
		G[i + 1] = H.size();
	}
	return G;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> l[i] >> r[i];
		dp[r[i] + 1]--; dp[l[i]]++;
	}
	for (int i = 1; i <= M + 1; i++) dp[i] += dp[i - 1];

	vector<int>R; for (int i = 1; i <= M; i++) R.push_back(dp[i]);
	vector<int>vec1 = LIS(R); reverse(R.begin(), R.end());
	vector<int>vec2 = LIS(R); reverse(vec2.begin(), vec2.end());

	int ret = 0;
	for (int i = 0; i <= M; i++) ret = max(ret, vec1[i] + vec2[i]);
	cout << ret << endl;
	return 0;
}