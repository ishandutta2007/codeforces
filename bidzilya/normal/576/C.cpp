#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	const int kMinX = 0;
	const int kMaxX = 1e6;
	const int kBlockSize = 1000;
	const int kAmountOfBlocks = (kMaxX - kMinX + 1) / kBlockSize + ((kMaxX - kMinX + 1) % kBlockSize != 0);

	vector<vector<pair<pair<int, int>, int> > > points(kAmountOfBlocks);

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		pair<int, int> point;
		scanf("%d%d", &point.first, &point.second);
		points[(point.first - kMinX) / kBlockSize].push_back(make_pair(point, i));
	}	

	vector<int> ans;
	for (int i = 0; i < kAmountOfBlocks; ++i) {
		for (auto& point: points[i]) {
			swap(point.first.first, point.first.second);
		}
		sort(points[i].begin(), points[i].end());
		if (i & 1) {
			reverse(points[i].begin(), points[i].end());
		}
		for (const auto& x: points[i]) {
			ans.push_back(x.second);
		}
	} 

	for (auto x: ans) {
		printf("%d ", x + 1);
	}
	printf("\n");

	return 0;
}