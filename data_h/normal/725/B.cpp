#include <iostream>

using namespace std;

long long row;
char col;

int main() {
	scanf("%I64d%c", &row, &col);
	long long ans = 0;
	row--;
	ans += row / 4 * 16;
	row %= 4;
	if (row >= 2) {
		row -= 2;
	}
	if (row) {
		ans += 7;
	}
	if (col >= 'd') {
		ans += 'f' - col + 1;
	} else {
		ans += col - 'a' + 1 + 3;
	}
	cout << ans << endl;
	return 0;
}