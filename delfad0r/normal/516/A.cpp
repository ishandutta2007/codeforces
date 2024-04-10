#include <iostream>
#include <string>

using namespace std;

int N;
string As;
int A[20];
int F[10];
int primes[] = {2, 3, 5, 7};
int P[4];

void foo(int f, int v) {
	for(int i = 1; i <= f; ++i)
		for(int p = 0; p < 4; ++p) {
			int j = i;
			while((j % primes[p]) == 0) {
				P[p] += v;
				j /= primes[p];
			}
		}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> N;
	cin >> As;
	for(int i = 0; i < N; ++i) {
		A[i] = As[i] - '0';
		foo(A[i], 1);
	}
	for(int p = 3; p >= 0; --p) {
		while(P[p]) {
			cout << primes[p];
			foo(primes[p], -1);
		}
	}
}