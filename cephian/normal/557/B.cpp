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
	ios::sync_with_stdio(0);

	int n;
	double w;
	scanf("%d %lf", &n, &w);
	double arr[2 * n];
	for (int i = 0; i < 2 * n; ++i)
		scanf("%lf", &arr[i]);
	sort(arr, arr + 2 * n);
	double ans = min(arr[0], arr[n] / 2.0);
	printf("%f\n", min(ans * 3 * n, w));

	return 0;
}