#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S; bool used[26]; int n, k, R = 27;

bool increment(int pos) {
	for (int i = S[pos] - 'a' + 1; i < 26; i++) {
		if (used[i] == true) {
			S[pos] = ('a' + i); return true;
		}
	}
	S[pos] = ('a' + R);
	return false;
}

int main() {
	cin >> n >> k >> S;
	for (int i = 0; i < S.size(); i++) { used[S[i] - 'a'] = true; R = min(R, (int)S[i] - 'a'); }
	if (k < n) {
		for (int i = k; i < n; i++) S[i] = 'z';
	}
	if (k > n) {
		for (int i = 0; i < k - n; i++) S += ('a' + R);
		cout << S << endl;
		return 0;
	}
	for (int i = S.size() - 1; i >= 0; i--) {
		bool P = increment(i);
		if (P == true) break;
	}
	cout << S.substr(0, k) << endl;
	return 0;
}