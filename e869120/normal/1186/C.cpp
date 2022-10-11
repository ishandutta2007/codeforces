#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

string A, B; int col[2000009], ans;

int main() {
	cin >> A >> B;
	for (int i = 0; i < (int)A.size(); i++) {
		if (A[i] == '0') col[i + 1] = 0;
		if (A[i] == '1') col[i + 1] = 1;
	}
	for (int i = 1; i <= (int)A.size(); i++) col[i] += col[i - 1];

	int cnt1 = 0; for (int i = 0; i < (int)B.size(); i++) { if (B[i] == '1') cnt1++; }

	for (int i = 0; i <= (int)A.size() - (int)B.size(); i++) {
		int cnt2 = col[i + (int)B.size()] - col[i];
		if ((cnt1 + cnt2) % 2 == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}