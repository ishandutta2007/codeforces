#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, a[10000], m, mid, maxn;
vector<long long>V1, V2;

int main() {
	cin >> n >> m; mid = n / 2;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < (1 << mid); i++) {
		long long S = 0;
		for (int j = 0; j < mid; j++) { if ((i / (1 << j)) % 2 == 1) S += a[j]; }
		V1.push_back(S%m);
	}
	for (int i = 0; i < (1 << (n - mid)); i++) {
		long long S = 0;
		for (int j = 0; j < n - mid; j++) { if ((i / (1 << j)) % 2 == 1) S += a[mid + j]; }
		V2.push_back(S%m);
	}
	sort(V1.begin(), V1.end());
	sort(V2.begin(), V2.end());
	for (int i = 0; i < V1.size(); i++) {
		int pos1 = lower_bound(V2.begin(), V2.end(), m - V1[i]) - V2.begin();
		maxn = max(maxn, V1[i] + V2[(pos1 - 1 + V2.size()) % V2.size()]);
	}
	cout << maxn << endl;
	return 0;
}