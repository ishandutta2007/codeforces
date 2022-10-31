#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int a, b, s;
	cin >> a >> b >> s;
	s -= abs(a) + abs(b);
	if (s < 0 || (s & 1))
		cout << "No\n";
	else
		cout << "Yes\n";
	return 0;
}