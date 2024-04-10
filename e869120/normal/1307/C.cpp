#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

string S;
long long ret[26][26], cnt[26], maxn = 0;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		for (int j = 0; j < 26; j++) {
			ret[j][S[i] - 'a'] += cnt[j];
		}
		cnt[S[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) maxn = max(maxn, ret[i][j]);
	}
	for (int i = 0; i < 26; i++) maxn = max(maxn, cnt[i]);
	cout << maxn << endl;
	return 0;
}