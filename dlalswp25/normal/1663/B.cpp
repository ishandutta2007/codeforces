#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v{1200, 1400, 1600, 1900, 2200, 2300, 2400, 2600, 3000};
	int x; scanf("%d", &x);
	printf("%d\n", *upper_bound(v.begin(), v.end(), x));
	return 0;
}