#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	int k,r;
	cin >> k >> r;
	int buy = 1;
	int cost = k;
	while(cost%10 != 0 && cost %10 != r) {
		++buy;
		cost+=k;
	}
	cout << buy << "\n";

	return 0;
}