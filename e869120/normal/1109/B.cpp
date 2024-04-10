#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S;

bool ispalindrome(string V) {
	for (int i = 0; i < V.size(); i++) {
		if (V[i] != V[V.size() - 1 - i]) return false;
	}
	return true;
}

bool check(string S) {
	int b[26]; for (int i = 0; i < 26; i++) b[i] = 0;
	for (int i = 0; i < S.size(); i++) b[S[i] - 'a']++;
	sort(b, b + 26);
	if (b[24] + b[25] == S.size() && b[24] <= 1) return false;
	return true;
}

int main() {
	cin >> S;
	if (check(S) == false) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i = 1; i < S.size(); i++) {
		string T = S.substr(i, S.size() - i) + S.substr(0, i);
		if (S != T && ispalindrome(T) == true) {
			cout << "1" << endl;
			return 0;
		}
	}
	cout << "2" << endl;
	return 0;
}