#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long A, B, C;

int main() {
	cin >> A >> B >> C;
	long long E = 0;
	if (A == B) E = 2LL * A;
	else E = 2LL * min(A, B) + 1LL;
	cout << 2LL * C + E << endl;
	return 0;
}