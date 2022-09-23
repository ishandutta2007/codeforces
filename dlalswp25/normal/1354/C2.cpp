#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		double theta = 2 * PI * (N / 2) / (2 * N);
		// printf("%f\n", theta);
		printf("%.10f\n", 1 / sin(PI / 2 / N) * cos(PI / 4 - theta / 2));
	}
	return 0;
}