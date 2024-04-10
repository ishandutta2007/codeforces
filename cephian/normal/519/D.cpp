#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

vector<vector<int> > pos(26, vector<int>());
string s;
int val[26];
ll sum[100000];

ll pfxsum(int i) {
	if (i == 0)
		return 0;
	return sum[i - 1];
}

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i < 26; ++i)
		cin >> val[i];
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		pos[s[i] - 'a'].push_back(i);
		sum[i] = val[s[i] - 'a'] + pfxsum(i);
	}

	ll ans = 0;
	for (int c = 0; c < 26; ++c) {
		map<ll, int> m;
		for (int i = 0; i < pos[c].size(); ++i) {
			ll ind = pos[c][i];
			ans += m[pfxsum(ind)];
			++m[sum[ind]];
		}
	}
	cout << ans << "\n";
	return 0;
}