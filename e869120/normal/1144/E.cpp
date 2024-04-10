#include <iostream>
#include <string>
using namespace std;

int N, A[200009], B[200009], C[200009], carry = 0;
string S, T;

int main() {
	cin >> N >> S >> T;
	for (int i = 0; i < N; i++) A[i] = (S[i] - 'a');
	for (int i = 0; i < N; i++) B[i] = (T[i] - 'a');

	for (int i = 0; i < N; i++) {
		C[i] = (A[i] + B[i]) / 2; C[i] += carry;

		int cx = i;
		while (C[cx] >= 26) {
			C[cx] -= 26;
			C[cx - 1] += 1;
			cx--;
		}
		
		if ((A[i] + B[i]) % 2 == 1) carry = 13;
		else carry = 0;
	}
	for (int i = 0; i < N; i++) {
		printf("%c", (char)('a' + C[i]));
	}
	printf("\n");
	return 0;
}