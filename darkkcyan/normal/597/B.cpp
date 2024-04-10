#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define fff(i, a, b) for (i = a; i != b; ++i)
#define ff(i, n) fff(i, 0, n)

bool cmpPair(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

#define MAX_N 500010

pair<int, int> arr[MAX_N];
// int tarr[MAX_N] = {0};
int n;

int process(int index) {
	if (index >= n) return 0;
	int i, g, h;

	fff (i, index + 1, n) {
		if (arr[i].first > arr[index].second) break;
	}

	return process(i) + 1;
}

int main (void) {
	ios_base::sync_with_stdio(0);

	cin >> n;

	int i, g, h;

	ff (i, n) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr, &arr[n], cmpPair);

	cout << process(0) << '\n';

	return 0;
}