#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[4] = { 0, 2, 19, 6 }, B[100], sum = 10000;
string S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) B[i] = (S[i] - 'A');
	for (int i = 0; i < N - 3; i++) {
		int minx = 0;
		for (int j = 0; j < 4; j++) {
			minx += min(abs(B[i + j] - A[j]), 26 - abs(B[i + j] - A[j]));
		}
		sum = min(sum, minx);
	}
	cout << sum << endl;
	return 0;
}