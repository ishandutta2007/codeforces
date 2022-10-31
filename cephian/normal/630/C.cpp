#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	cout << (1LL << (n+1))-2 << "\n";
	return 0;
}