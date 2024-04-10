#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N, D, E, minx = (1 << 30);

int main() {
	cin >> N >> D >> E;
	for (int i = 0; i <= N / E; i += 5) {
		int V = (N - i * E) / D;
		minx = min(minx, N - i * E - V * D);
	}
	cout << minx << endl;
	return 0;
}