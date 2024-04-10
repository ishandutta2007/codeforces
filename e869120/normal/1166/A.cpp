#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int n, cnt[26]; string S[109];

int solve(int v) {
	return v * (v - 1) / 2;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) { cin >> S[i]; cnt[S[i][0] - 'a']++; }
	int sum = 0; for (int i = 0; i < 26; i++) sum += solve(cnt[i] / 2) + solve((cnt[i] + 1) / 2);
	cout << sum << endl;
	return 0;
}