#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, A[100], minx = 1000, s = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> A[i]; minx = min(minx, A[i]); }
	for (int i = 0; i < N; i++) {
		if (A[i] == minx) s++;
	}
	if (s > N / 2) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return 0;
}