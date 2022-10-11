#include <bits/stdc++.h>
using namespace std;

long long X, Y, Z;

int main() {
	cin >> X >> Y >> Z;
	long long K = (X + Y) / Z;
	if ((X / Z) + (Y / Z) == K) {
		cout << K << " " << 0 << endl;
	}
	else {
		long long E1 = Z - (X % Z);
		long long E2 = Z - (Y % Z);
		cout << K << " " << min(E1, E2) << endl;
	}
	return 0;
}