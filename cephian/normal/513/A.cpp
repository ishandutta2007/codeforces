#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a <= b)
		cout << "Second\n";
	else
		cout << "First\n";

	return 0;
}