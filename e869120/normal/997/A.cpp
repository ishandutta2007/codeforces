#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S; long long cnt = 0, n, a, b;

int main() {
	cin >> n >> a >> b >> S;
	for (int i = 1; i < S.size(); i++) {
		if (S[i - 1] == '1' && S[i] == '0') cnt++;
	}
	if (S[0] == '0') cnt++;

	long long L1 = 1LL * b * cnt;
	long long L2 = 1LL * b + 1LL * a * (cnt - 1LL); L2 = max(L2, 0LL);
	cout << min(L1, L2) << endl;
	return 0;
}