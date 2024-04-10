#include <bits/stdc++.h>
using namespace std;
int a, b, t;
int main() {
	scanf("%d %d", &a, &b);
	while (a <= b) {
		a *= 3;
		b *= 2;
		t++;
	}
	printf("%d\n", t);
	return 0;
}