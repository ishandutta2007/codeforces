#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
string S, V;

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> S; V = "";

		int cnt = 0;
		for (int j = 0; j < S.size(); j++) {
			cnt++;
			if (j + 1 == S.size() || S[j] != S[j + 1]) {
				if (cnt % 2 == 1) V += S[j];
				cnt = 0;
			}
		}
		sort(V.begin(), V.end());
		V.erase(unique(V.begin(), V.end()), V.end());
		cout << V << endl;
	}
	return 0;
}