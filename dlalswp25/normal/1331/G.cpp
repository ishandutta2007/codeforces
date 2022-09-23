#include <bits/stdc++.h>

using namespace std;

int A[12];

int main() {
	for(int i = 0; i < 11; i++) scanf("%d", &A[i]);
	for(int i = 10; i >= 0; i--) {
		double x = A[i];
		double y = x * x * x * 5;
		y += sqrt(abs(x));
		if(y >= 400) printf("f(%d) = MAGNA NIMIS!\n", A[i]);
		else printf("f(%d) = %.2f\n", A[i], y);
	}
	return 0;
}