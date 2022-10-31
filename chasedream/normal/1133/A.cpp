#include <bits/stdc++.h>
using namespace std;

int a1, a2, b1, b2;

int main() {
	scanf("%d:%d", &a1, &a2);
	scanf("%d:%d", &b1, &b2);
	int k1 = 60 * a1 + a2;
	int k2 = 60 * b1 + b2;
	int k = (k1 + k2) / 2;
	printf("%.2d:%.2d\n", k / 60, k % 60);
	return 0;
}