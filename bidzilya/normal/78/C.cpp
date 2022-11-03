#include <cstdlib>
#include <cmath>

#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

int n, m, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	if (n % 2 == 0) {
		cout << "Marsel" << endl;
		return 0;
	}
	for (int i = 1; i * i <= m; ++i)
		if (m % i == 0 && (i != 1 && m / i >= k || i != m && i >= k)) {
			cout << "Timur" << endl;
			return 0;
		}
	cout << "Marsel" << endl;
	return 0;
}