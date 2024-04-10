#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning(disable: 4996)

int n, p[400000], dp[400000];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)scanf("%d", &p[i]);
	for (int i = n; i >= 1; i--)dp[i] = max(dp[i + 1], p[i]);
	for (int i = 1; i <= n + 1; i++) {
		if (i >= 2)printf(" ");
		printf("%d", dp[i] - (n - i));
	}
	cout << endl;
	return 0;
}