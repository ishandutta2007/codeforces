#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
	int n;
	int mn[3];
	int mx[3];
	int a[3];

	scanf("%d", &n);
	for (int i = 0; i < 3; ++i) {
		scanf("%d %d", &mn[i], &mx[i]);
		a[i] = mn[i];
		n -= mn[i];
	}

	for (int i = 0; i < 3; ++i) {
		int g = min(n, mx[i] - mn[i]);
		n -= g;
		a[i] += g;
	}

	printf("%d %d %d", a[0], a[1], a[2]);

	return 0;
}