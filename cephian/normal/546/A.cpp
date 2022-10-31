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

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);

	ll k, w, n;
	cin >> k >> w >> n;
	ll cost = k * ((n * (n + 1)) / 2);
	cost -= w;
	cout << max(0LL, cost) << "\n";

	return 0;
}