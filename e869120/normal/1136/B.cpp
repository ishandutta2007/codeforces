#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, K;

int main() {
	cin >> N >> K;
	cout << N * 3 + min(K - 1, N - K) << endl;
	return 0;
}