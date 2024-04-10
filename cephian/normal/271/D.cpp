#include <iostream>
#include <algorithm>

using namespace std;

int dp[1505][1505];

int main() {
	ios::sync_with_stdio(0);

	string s, g;
	int k;
	cin >> s >> g >> k;

	vector<string> suff;
	suff.reserve(s.size());
	for (unsigned int i = 0; i < s.size(); ++i)
		suff.push_back(s.substr(i));

	sort(suff.begin(), suff.end());

	int ans = 0;
	for (unsigned int i = 0; i < suff.size(); ++i) {

		bool left_eq = i != 0;
		int bad_chars = 0;

		for (unsigned int j = 0; j < suff[i].size(); ++j) {

			bad_chars += 1 - (g[suff[i][j] - 'a'] - '0');

			if (bad_chars > k)
				break;

			if (left_eq)
				left_eq = (j < suff[i - 1].size()) && (suff[i - 1][j] == suff[i][j]);

			if (!left_eq)
				++ans;

		}
	}

	cout << ans << "\n";
	return 0;
}