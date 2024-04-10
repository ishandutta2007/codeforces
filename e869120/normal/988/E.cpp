#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S; long long n;

int main() {
	cin >> n; S = to_string(n); if (n % 25 == 0) { cout << "0" << endl; return 0; } int ret = 1000000;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < S.size(); j++) {
			if (i == j) continue;
			int G = (S[i] - '0') * 10 + (S[j] - '0');
			if (G % 25 != 0) continue;

			string T = "";
			for (int k = 0; k < S.size(); k++) { if (k != i && k != j) T += S[k]; }
			int sum = 1000000;
			for (int k = 0; k < T.size(); k++) { if (T[k] >= '1') { sum = k; break; } }
			if (T.size() == 0 && G % 2 == 1) sum = 0;
			sum += (S.size() - i) + (S.size() - j) - 3; if (i > j) sum++;
			ret = min(ret, sum);
		}
	}
	if (ret == 1000000) ret = -1;
	cout << ret << endl;
	return 0;
}