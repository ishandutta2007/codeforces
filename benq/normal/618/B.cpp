#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int,int>> order;

int main() {
	cin >> n;
	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		int max1 = 0, count2 = 0;
		for (int j = 0; j < n; ++j) {
			int z;
			cin >> z;
			if (z > max1) {
				max1 = z;
				count2 = 1;
			} else if (z == max1) {
				count2++;
			}
		}
		if (count2 == 1) {
			if (flag == 0) {
				cout << (n-1) << " ";
				flag = 1;
			} else cout << n << " ";
		} else cout << (n-count2) << " ";
	}
	return 0;
}