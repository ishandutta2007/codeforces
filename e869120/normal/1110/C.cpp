#include <iostream>
#include <algorithm>
using namespace std;

int t[26] = { 0, 0, 1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401 };

int main() {
	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		int a; cin >> a; bool flag = false;
		for (int j = 2; j <= 25; j++) {
			if ((1 << j) - 1 == a) { cout << t[j] << endl; flag = true; }
		}
		if (flag == false) {
			for (int j = 1; j <= 25; j++) {
				if ((1 << j) - 1 > a) { cout << (1 << j) - 1 << endl; break; }
			}
		}
	}
	return 0;
}