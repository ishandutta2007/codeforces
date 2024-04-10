#include <iostream>

using namespace std;

int main (void) {
	ios_base::sync_with_stdio(false);

	int a, b, c;
	int x, y ,z;

	cin >> a >> b >> c;
	cin >> x >> y >> z;

	int r = 0;
	int d = 0;

	if (a > x) r += (a - x) / 2;
	else d += x - a;

	if (b > y) r += (b - y) / 2;
	else d += y - b;

	if (c > z) r += (c - z) / 2;
	else d += z - c;

	if (r >= d) cout << "YES";
	else cout << "NO";

	return 0;
}