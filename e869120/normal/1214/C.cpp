#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S; int n;

bool calc(string F) {
	int dep = 0;
	for (int i = 0; i < F.size(); i++) {
		if (F[i] == '(') dep++;
		else dep--;
		if (dep < 0) return false;
	}
	if (dep != 0) return false;
	return true;
}

int main() {
	cin >> n >> S;

	int dep = 0;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') dep++;
		else dep--;
	}
	if (dep != 0) {
		cout << "No" << endl;
		return 0;
	}

	string S1 = ""; bool flag = false;
	for (int i = 0; i < S.size(); i++) {
		if (flag == false && S[i] == ')') { flag = true; continue; }
		S1 += S[i];
	}
	S1 += ')';

	string S2 = ""; flag = false;
	for (int i = S.size() - 1; i >= 0; i--) {
		if (flag == false && S[i] == '(') { flag = true; continue; }
		S2 += S[i];
	}
	S2 += '(';
	reverse(S2.begin(), S2.end());

	if (calc(S) == true || calc(S1) == true || calc(S2) == true) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}