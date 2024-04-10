#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n, h;

int main() {
	scanf("%d %d", &n, &h);
	double area = 1. * h / n;
	for (int i = 1; i < n; i++) {
		printf("%.12f ", sqrt(area * i * h));
	}
	puts("");
	return 0;
}