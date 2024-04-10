#include <bits/stdc++.h>
using namespace std;

int main() {
	int m,a,b,c;
	cin >> a >> b >> c >> m;
	int x = 2*a;
	int y = 2*b;
	int z = min(2*c,2*m);
	if(
		a <= x && x <= 2*a &&
		b <= y && y <= 2*b &&
		c <= z && z <= 2*c &&
		m <= z && z <= 2*m &&
		m <= x && m <= y &&
		2*m < x && 2*m < y) {
		cout << x << " " << y << " " << z << "\n";
	}
	else cout << "-1\n";
}