#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
long long m, h[2], a[2], x[2], y[2]; vector<long long>F[2];
int main() {
	cin >> m;
	for (int i = 0; i < 2; i++) {
		cin >> h[i] >> a[i] >> x[i] >> y[i];
		for (int j = 0; j < 3000000; j++) {
			if (h[i] == a[i])F[i].push_back(j);
			h[i] = (x[i] * h[i] + y[i]) % m;
		}
		if (F[i].size() == 0) { cout << "-1" << endl; return 0; }
		if (F[i].size() >= 2) {
			while (F[i].size() < 1000000)F[i].push_back(F[i][F[i].size() - 1] * 2 - F[i][F[i].size() - 2]);
		}
	}
	for (int i = 0; i < F[0].size(); i++) {
		int pos1 = lower_bound(F[1].begin(), F[1].end(), F[0][i]) - F[1].begin();
		if (F[1].size() > pos1 && F[1][pos1] == F[0][i]) {
			cout << F[0][i] << endl; return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}