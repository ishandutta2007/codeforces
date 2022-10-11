#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <map>
#include <tuple>
using namespace std;

long long a[3], b[3];

int main() {
	cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2];
	if (a[0] > b[0] || a[0] + a[1] > b[0] + b[1] || a[0] + a[1] + a[2] > b[0] + b[1] + b[2]) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}