#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

int N, M, K;

int main() {
	cin >> N >> M >> K;
	if (N <= M && N <= K) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}