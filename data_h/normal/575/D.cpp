#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int n;

int main() {
	printf("%d\n", 2001);
	for (int i = 1; i <= 1000; i++) {
		printf("%d %d %d %d\n", i, 1, i, 2);
	}
	printf("%d %d %d %d\n", 1, 1, 1, 2);
	for (int i = 1; i <= 1000; i++) {
		printf("%d %d %d %d\n", i, 1, i, 2);
	}
	return 0;
}