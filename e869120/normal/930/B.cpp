#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S; int cnt[5009][26][26], I[26];

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		I[S[i] - 'a']++;
		for (int j = 0; j < S.size(); j++) cnt[(S.size() + j - i) % S.size()][S[i] - 'a'][S[j] - 'a']++;
	}
	int n = S.size(); long double ret = 0;
	for (int i = 0; i < 26; i++) {
		long double P1 = 1.0L*I[i] / n;
		long double P2 = 0;
		for (int j = 0; j < n; j++) {
			long double C = 0;
			for (int k = 0; k < 26; k++) { if (cnt[j][i][k] == 1) C += 1.0L; }
			C /= 1.0L*I[i];
			P2 = max(P2, C);
		}
		ret += P1*P2;
	}
	printf("%.12Lf\n", ret);
	return 0;
}