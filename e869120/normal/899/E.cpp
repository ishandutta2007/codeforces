#include <iostream>
#include <tuple>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int n, a[200009], I = 1, cnt = 0; vector<pair<int, int>>vec;
set<tuple<int, int, int>>S;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>Q;
map<pair<int, int>, int>M;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i + 1]) { vec.push_back(make_pair(I, i)); I = i + 1; }
	}
	for (int i = 0; i < vec.size(); i++) {
		S.insert(make_tuple(vec[i].first, vec[i].second, vec[i].second - vec[i].first + 1));
		Q.push(make_tuple(-1*(vec[i].second - vec[i].first + 1), vec[i].first, vec[i].second));
	}
	while (!Q.empty()) {
		tuple<int, int, int> G = make_tuple(get<1>(Q.top()), get<2>(Q.top()), -get<0>(Q.top())); Q.pop();
		if (M[make_pair(get<0>(G), get<1>(G))] == true) continue;

		S.erase(G);
		auto itr = S.lower_bound(G); int minv = (1 << 30), maxv = -(1 << 30), sum = 0; vector<tuple<int, int, int>>tup;
		if (itr != S.begin()) {
			auto itr1 = itr; itr1--; tup.push_back(*itr1);
			minv = min(minv, get<0>(*itr1));
			maxv = max(maxv, get<1>(*itr1));
			sum += get<2>(*itr1);
			S.erase(itr1);
		}
		if (itr != S.end()) {
			auto itr2 = itr; tup.push_back(*itr2);
			minv = min(minv, get<0>(*itr2));
			maxv = max(maxv, get<1>(*itr2));
			sum += get<2>(*itr2);
			S.erase(itr2);
		}
		cnt++;
		if (sum == 0) {
			break;
		}
		else {
			if (tup.size() == 1 || tup.size() == 2 && (a[get<1>(tup[0])] == a[get<0>(tup[1])])) {
				if (tup.size() == 2) Q.push(make_tuple(-sum, minv, maxv));
				S.insert(make_tuple(minv, maxv, sum));
				if (tup.size() == 2) {
					M[make_pair(get<0>(tup[0]), get<1>(tup[0]))] = 1;
					M[make_pair(get<0>(tup[1]), get<1>(tup[1]))] = 1;
				}
			}
			else {
				S.insert(tup[0]);
				S.insert(tup[1]);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}