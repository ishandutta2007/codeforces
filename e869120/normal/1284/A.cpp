#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int N; string A[100009];
int M; string B[100009];
int Q, D;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> D; D--;
		cout << A[D % N] << B[D % M] << endl;
	}
	return 0;
}