#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	if (x1 == x2)
		cout << (x1 + dy) << ' ' << y1 << ' ' << (x1 + dy) << ' ' << y2;
	else if (y1 == y2) 
		cout << x1 << ' ' << (y1 + dx) << ' ' << x2 << ' ' << (y1 + dx);
	else if (dx != dy)
		cout << -1;
	else
		cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1;
	
	return 0;
}