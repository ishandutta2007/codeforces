#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a[109], b[109]; vector<int>A;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)cin >> a[i] >> b[i];
	for (int i = 1; i <= 100; i++) {
		bool OK = true;
		for (int j = 1; j <= m; j++) {
			int F = (a[j] - 1) / i; F++;
			if (F != b[j])OK = false;
		}
		if (OK == true)A.push_back((n - 1) / i + 1);
	}
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	if (A.size() != 1)cout << "-1" << endl;
	else cout << A[0] << endl;
	return 0;
}