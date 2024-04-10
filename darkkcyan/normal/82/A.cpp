#include <iostream>
#include <cmath>
using namespace std;

string names[] = {
	"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"
};

int main() {
	long long n;
	cin >> n;
	int t = 0;
	int i = 1;
	while (t + i * 5 < n) {
		t += i * 5;
		i *= 2;
	}
	n -= t + 1;
	// cout << n << ' ' << t << ' ' << i << endl;
	cout << names[(int)floor((float)n / i)];
	return 0;
}