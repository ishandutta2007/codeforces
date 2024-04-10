#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, L[1 << 19], stamina, grass, water, coins; char c[1 << 19];
bool iswater = false;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) { scanf("%lld", &L[i]); L[i] *= 2; coins += L[i]; }
	scanf("%s", &c);

	for (int i = 0; i < N; i++) {
		if (c[i] == 'G') grass += L[i];
		if (c[i] == 'W') { water += L[i]; iswater = true; }

		stamina -= L[i];

		// Step 1. 
		long long A1 = min(water, -stamina / 2LL); water -= A1; stamina += 2LL * A1; coins += 2LL * A1;

		// Step 2. 
		long long A2 = min(grass, -stamina / 2LL); grass -= A2; stamina += 2LL * A2; coins += 4LL * A2;

		// Step 3.
		if (iswater == true) {
			long long A3 = -stamina / 2LL; stamina += 2LL * A3; coins += 6LL * A3;
		}
		
		// Step 4.
		long long A4 = -stamina / 2LL; stamina += 2LL * A4; coins += 10LL * A4;
	}
	cout << coins / 2 << endl;
	return 0;
}