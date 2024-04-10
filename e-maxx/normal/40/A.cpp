#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int x, y;
	cin >> x >> y;

	if (x == 0 || y == 0)
		cout << "black";
	else {
		bool tp = x>0 && y>0 || x<0 && y<0;
		for (int i=0; i<2000; i+=2) {
			int d = x*x + y*y;
			if (i*i <= d && d <= (i+2)*(i+2)) {
				bool first = d <= (i+1)*(i+1);
				bool second = (i+1)*(i+1) <= d;
				if (tp && first || !tp && second) {
					cout << "black";
					return 0;
				}
			}
		}
		cout << "white";
	}

}