#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int a, b, c, d;
int cl = 100000, cr = 100000, A[1 << 18];

int main() {
	cin >> a >> b >> c >> d;

	if (a + b + c + d == 1) {
		cout << "YES" << endl;
		if (a == 1) cout << "0" << endl;
		if (b == 1) cout << "1" << endl;
		if (c == 1) cout << "2" << endl;
		if (d == 1) cout << "3" << endl;
	}
	else if (a + b == 0 && d - c == 1) {
		printf("YES\n");
		for (int i = 0; i < d + c; i++) {
			if (i >= 1) printf(" ");
			if (i % 2 == 0) printf("3");
			else printf("2");
		}
		printf("\n");
	}
	else if (c + d == 0 && a - b == 1) {
		printf("YES\n");
		for (int i = 0; i < a + b; i++) {
			if (i >= 1) printf(" ");
			if (i % 2 == 0) printf("0");
			else printf("1");
		}
		printf("\n");
	}
	else if (a > b || d > c || abs((a + c) - (b + d)) >= 2) {
		printf("NO\n");
	}
	else {
		int A1 = a, B1 = b, C1 = c, D1 = d;
		for (int i = 0; i < a; i++) {
			A[cr] = 0; cr++; A1--;
			A[cr] = 1; cr++; B1--;
		}
		for (int i = 0; i < min(b - a, c - d); i++) {
			A[cr] = 2; cr++; C1--;
			A[cr] = 1; cr++; B1--;
		}
		for (int i = 0; i < d; i++) {
			A[cr] = 2; cr++; C1--;
			A[cr] = 3; cr++; D1--;
		}
		if (B1 >= 1) { cl--; A[cl] = 1; B1--; }
		if (C1 >= 1) { A[cr] = 2; cr++; C1--; }

		printf("YES\n");
		for (int i = cl; i < cr; i++) {
			if (i > cl) printf(" ");
			printf("%d", A[i]);
		}
		printf("\n");
	}
	return 0;
}