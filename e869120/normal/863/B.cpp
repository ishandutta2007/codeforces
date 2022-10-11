#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[1000];
int main() {
	cin >> n; for (int i = 0; i < 2 * n; i++)cin >> a[i];
	int minx = (1 << 30);
	for (int i = 0; i < 2 * n; i++) {
		for (int j = i + 1; j < 2 * n; j++) {
			vector<int>X; int sum = 0;
			for (int k = 0; k < 2 * n; k++) { if (k != i && k != j)X.push_back(a[k]); }
			sort(X.begin(), X.end());
			for (int k = 0; k < X.size(); k += 2)sum += (X[k + 1] - X[k]);
			minx = min(minx, sum);
		}
	}
	cout << minx << endl;
	return 0;
}