#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, K;

int main() {
	cin >> N >> K;
	int V = (N - K) / 2; V++;

	for (int i = 0; i < N; i++) {
		if (i%V == V - 1) printf("1");
		else printf("0");
	}
	printf("\n");
	return 0;
}