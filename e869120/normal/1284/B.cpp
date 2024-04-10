#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, ans;
vector<pair<long long, int>> vec;

int main() {
	scanf("%lld", &N); ans = 1LL * N * N;
	for (int i = 1; i <= N; i++) {
		long long s; scanf("%lld", &s);
		vector<long long> v(s, 0); bool flag = false;
		for (int j = 0; j < s; j++) scanf("%lld", &v[j]);
		for (int j = 1; j < s; j++) {
			if (v[j - 1] < v[j]) flag = true;
		}
		if (flag == false) {
			vec.push_back(make_pair(v[0], 0));
			vec.push_back(make_pair(v[s - 1], 1));
		}
	}
	sort(vec.begin(), vec.end());

	long long cnt = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].second == 1) ans -= cnt;
		else cnt += 1;
	}
	cout << ans << endl;
	return 0;
}