#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable: 4996)

int n, c[10009]; string S;

int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) { c[S[i] - 'a']++; }

	bool flag = false;
	for (int i = 0; i < 26; i++) { if (c[i] >= 2) flag = true; }
	if (n == 1) flag = true;

	if (flag == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}