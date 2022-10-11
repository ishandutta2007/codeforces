#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <map>
#include <tuple>
#include <ctime>
using namespace std;

const int THE_LARGEST = 29;
long long N; bool used[1000009];

long long gcd(long long a, long long b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a % b);
}

int Rand() {
	return rand() * 32768 + rand();
}

int main() {
	srand((unsigned)time(NULL));

	cin >> N;

	// get the largest value
	long long cx = 0;
	for (int i = THE_LARGEST; i >= 0; i--) {
		cout << "> " << min(1000000000LL, cx + (1 << i) - 1) << endl;
		int p; cin >> p;
		if (p == 1) cx += (1 << i);
	}
	
	long long V = 0;
	for (int i = 0; i < min(30LL, N); i++) {
		while (true) {
			int u = Rand() % N + 1;
			if (used[u] == false) {
				cout << "? " << u << endl;
				long long t; cin >> t;
				V = gcd(V, 1LL * cx - t); used[u] = true;
				break;
			}
		}
	}
	cout << "! " << cx - (N - 1LL) * V << " " << V << endl;
	return 0;
}