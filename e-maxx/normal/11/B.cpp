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

	int x;
	cin >> x;

	long long s = 0;
	for (int i=0; ; ++i) {
		s += i;
		if ((i + 1) / 2 % 2 == abs(x) % 2)
			if (-s <= x && x <= s) {
				cout << i;
				return 0;
			}
	}

}