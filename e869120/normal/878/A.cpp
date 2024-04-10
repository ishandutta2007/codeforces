#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 19], P, S; char c[1 << 19];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		cin >> c[i]; scanf("%d", &A[i]);
		if (c[i] == '|') { P |= A[i]; S |= A[i]; }
		if (c[i] == '&') { P &= A[i]; S |= (1023 - A[i]); }
		if (c[i] == '^') P ^= A[i];
	}
	cout << "2" << endl;
	cout << "| " << S << endl;
	cout << "^ " << (P^S) << endl;
	return 0;
}