#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string S;
bool ispal(string T) {
	for (int i = 0; i < T.size(); i++) {
		if (T[i] != T[T.size() - 1 - i])return false;
	}
	return true;
}
int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < 26; j++) {
			char c = 'a' + j; string U = S;
			if (U[i] == c)continue; U[i] = c;
			if (ispal(U) == true) { cout << "YES" << endl; return 0; }
		}
	}
	cout << "NO" << endl;
	return 0;
}