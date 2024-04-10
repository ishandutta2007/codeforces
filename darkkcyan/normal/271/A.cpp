#include <iostream>
using namespace std;

int main() {
	int num; cin >> num;
	while (true) {
		++num;
		bool has[10];
		for (int i = 0; i < 10; ++i) has[i] = false;
		
		bool is_distinct = true;
		int x = num;
		while (x > 0) {
			int digit = x % 10;
			x /= 10;
			if (!has[digit]) {
				has[digit] = true;
			} else {
				is_distinct = false;
			}
		}
		if (is_distinct) {
			cout << num;
			break;
		}
	}
	return 0;
}