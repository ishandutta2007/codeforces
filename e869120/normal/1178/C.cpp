#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long H, W, S = 1;

int main() {
	cin >> H >> W;
	for (int i = 1; i <= H + W; i++) { S *= 2LL; S %= 998244353LL; }
	cout << S << endl;
	return 0;
}