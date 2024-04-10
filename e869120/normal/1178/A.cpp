#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, S, T, A[1 << 18];
vector<int> vec;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); S += A[i]; }
	vec.push_back(1); T += A[1];
	for (int i = 2; i <= N; i++) {
		if (A[i] * 2 <= A[1]) { vec.push_back(i); T += A[i]; }
	}
	if (T * 2 - 1 >= S) {
		cout << vec.size() << endl;
		for (int i = 0; i < vec.size(); i++) { if (i) cout << " "; cout << vec[i]; } cout << endl;
	}
	else {
		cout << "0" << endl;
	}
	return 0;
}