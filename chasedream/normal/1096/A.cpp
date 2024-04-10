#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long l, r;
int t;


int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%lld %lld", &l, &r);
		printf("%lld %lld\n", l, 2 * l);
	}
	return 0;
}