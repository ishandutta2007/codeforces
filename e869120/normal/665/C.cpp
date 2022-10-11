#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
string S;
int main() {
	cin >> S; int cnt = 0;
	for (int i = 1; i < S.size(); i++) {
		if (S[i] == S[i - 1]) {
			char d = '-'; if (i != S.size() - 1)d = S[i + 1];
			for (int j = 0; j < 26; j++) {
				if (('a' + j) != S[i - 1] && ('a' + j) != d) { S[i] = ('a' + j); break; }
			}
		}
	}
	cout << S << endl;
	return 0;
}