#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, D[1 << 18];
vector<int> vec;
vector<pair<int, int>> ans;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &D[i]);

	vector<pair<int, int>> ord;
	for (int i = 1; i <= N; i++) ord.push_back(make_pair(D[i], i));
	sort(ord.begin(), ord.end());
	reverse(ord.begin(), ord.end());

	vec.push_back(ord[0].second * 2 - 1);
	for (int i = 1; i < ord[0].first; i++) vec.push_back(ord[i].second * 2 - 1);
	vec.push_back(ord[0].second * 2);
	for (int i = 0; i < vec.size() - 1; i++) ans.push_back(make_pair(vec[i], vec[i + 1]));

	for (int i = 1; i < ord[0].first; i++) {
		int pos = ord[i].second, leng = ord[i].first;
		ans.push_back(make_pair(vec[i + leng - 1], pos * 2));
		if (i + leng == vec.size()) vec.push_back(pos * 2);
	}

	for (int i = ord[0].first; i < ord.size(); i++) {
		int pos = ord[i].second, leng = ord[i].first;
		if (leng == 1) {
			ans.push_back(make_pair(vec[0], pos * 2 - 1));
			ans.push_back(make_pair(pos * 2 - 1, pos * 2));
		}
		else {
			ans.push_back(make_pair(vec[0], pos * 2 - 1));
			ans.push_back(make_pair(vec[leng - 2], pos * 2));
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}