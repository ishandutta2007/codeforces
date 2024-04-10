#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

long long a, b;
int answer = 0;

int main() {
	cin >> a >> b;
	for (int len = 2; len <= 60; len++) {
		for (int zero = 1; zero < len; zero++) {
			long long mask = 1;
			for (int p = 1; p < len; p++) {
				if (p == zero) {
					mask <<= 1;
				} else {
					mask = (mask << 1) | 1;
				}
			}
			if (a <= mask && mask <= b) {
				answer++;
			}
		}
	}
	cout << answer << endl;
	return 0;
}