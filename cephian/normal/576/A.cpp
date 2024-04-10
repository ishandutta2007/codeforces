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

vector<int> primes;

void genp(int mx) {
	if (mx > 2)
		primes.push_back(2);
	bool seive[mx];
	int max_it = (int) sqrt(mx);
	fill(seive, seive + mx, 1);
	for (int i = 3; i < mx; i += 2) {
		if (seive[i]) {
			if (i <= max_it)
				for (int j = i * i; j < mx; j += 2 * i)
					seive[j] = 0;
			primes.push_back(i);
		}
	}
}

vector<int> a;

int main() {
	ios::sync_with_stdio(0);

	genp(1005);

	int n;
	cin >> n;
	for (int i = 0; i < primes.size(); ++i) {
		if (primes[i] > n)
			break;
		int pp = primes[i];
		while (pp <= n) {
			a.push_back(pp);
			pp *= primes[i];
		}
	}
	cout << a.size() << '\n';
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i) {
		cout << a[i];
		if (i == a.size() - 1)
			cout << '\n';
		else
			cout << ' ';
	}

	return 0;
}