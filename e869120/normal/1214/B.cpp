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

int B, G, N, cnt = 0;

int main() {
	cin >> B >> G >> N;
	for (int i = 0; i <= B; i++) {
		for (int j = 0; j <= G; j++) {
			if (i + j == N) cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}