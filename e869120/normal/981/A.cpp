#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S;

bool ispal(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != str[str.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	cin >> S;
	int maxn = 0;
	for (int i = 0; i < S.size(); i++) {
		for (int j = i + 1; j <= S.size(); j++) {
			string V = S.substr(i, j - i);
			if (ispal(V) == false) maxn = max(maxn, j - i);
		}
	}
	cout << maxn << endl;
	return 0;
}