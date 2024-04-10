#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long double ld;
typedef long long ll;

int main() {
	ll a,b;
	cin >> a >> b;
	cout << setprecision(15) << fixed;
	cout << a*pow(1.000000011,b) << "\n";
	return 0;
}