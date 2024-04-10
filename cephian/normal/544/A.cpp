#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int k;
	cin >> k;
	string q;
	cin >> q;
	bool f[26];
	fill(f, f + 26, 0);
	for (int i = 0; i < q.size(); ++i) {
		f[q[i] - 'a'] = true;
	}
	int sum = 0;
	for (int i = 0; i < 26; ++i)
		if (f[i])
			++sum;
	if (sum < k)
		cout << "NO\n";
	else {
		vector<string> ans;
		bool seen[26];
		fill(seen, seen + 26, false);
		int start = 0;
		seen[q[0] - 'a'] = true;
		if (ans.size() == k - 1) {
			ans.push_back(q.substr(start));
		} else {
			for (int i = 1; i < q.size(); ++i) {
				if (!seen[q[i] - 'a']) {
					seen[q[i] - 'a'] = true;
					ans.push_back(q.substr(start, i - start));
					start = i;
				}
				if (ans.size() == k - 1) {
					ans.push_back(q.substr(start));
					break;
				}
			}
		}
		cout << "YES\n";
		for (int i = 0; i < k; ++i) {
			cout << ans[i] << "\n";
		}
	}

	return 0;
}