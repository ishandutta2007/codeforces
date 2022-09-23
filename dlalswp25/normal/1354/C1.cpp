#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		printf("%.10f\n", 1 / tan(PI / 2 / N));
	}
	return 0;
}