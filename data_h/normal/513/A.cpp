#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int n1, n2, k1, k2;

int main() {
	cin >> n1 >> n2 >> k1 >> k2;
	printf("%s\n", (n1 <= n2) ? "Second" : "First");;
}