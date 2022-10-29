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

	int bal = 0,  ans = 0;

	for (char c; scanf ("%c", &c) == 1; ) {
		if (c == '(')
			++bal;
		else if (c == ')') {
			if (bal) {
				--bal;
				ans += 2;
			}
		}
	}
	cout << ans;

}