#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", n / 2 + 1);
	}
	return 0;
}