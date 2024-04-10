#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

string S; int n;

int main() {
	cin >> n >> S;
	for (int i = 0; i < (int)S.size() - 1; i++) {
		if (S[i] != S[i + 1]) {
			cout << "YES" << endl;
			cout << S.substr(i, 2) << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}