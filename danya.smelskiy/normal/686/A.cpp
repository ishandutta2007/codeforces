#include <iostream>

using namespace std;
int main() {
	long long n, x;
	cin >> n >> x;

    long long sad = 0;
	for(int i = 0; i < n; i++){
		char c;
		long long d;
		cin >> c >> d;

		if (c == '+') {
			x += d;
		}
		if (c == '-') {
			x - d >= 0 ? x -= d : sad++;
		}
	}

	cout << x << " " << sad;
}