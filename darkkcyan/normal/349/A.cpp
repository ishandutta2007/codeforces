#include <iostream>
using namespace std;

int main() {
	int a[5] = {0};
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t; t /= 25;
		switch(t) {
		case 2:
			if (a[1] == 0) {
				cout << "NO";
				return 0;
			}
			--a[1];
			break;
		case 4:
			if (a[2] >= 1 and a[1] >= 1) {
				--a[2];
				--a[1];
			} else if (a[1] >= 3) {
				a[1] -= 3;
			} else {
				cout << "NO";
				return 0;
			}
		}
		
		++a[t];
	}
	cout << "YES";
	return 0;
}