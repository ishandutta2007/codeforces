#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long N, M;

int main() {
	cin >> N >> M;
	if (N <= 30) cout << M % (1LL << N) << endl;
	else cout << M << endl;
	return 0;
}