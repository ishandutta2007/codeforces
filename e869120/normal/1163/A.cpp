#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M;

int main() {
	cin >> N >> M;
	int Z = max(M, 1);
	int Y = N - M;
	cout << min(Z, Y) << endl;
	return 0;
}