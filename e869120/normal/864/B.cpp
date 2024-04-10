#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<functional>
using namespace std;
int maxn = 0, s = -1, n; string S;
int solve(string T) {
	bool u[26]; for (int j = 0; j < 26; j++)u[j] = false;
	for (int j = 0; j < T.size(); j++)u[T[j] - 'a'] = true;
	int cnt = 0;
	for (int j = 0; j < 26; j++) { if (u[j] == true)cnt++; }
	return cnt;
}
int main() {
	cin >> n >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] <= 'Z')s = i;
		else maxn = max(maxn, solve(S.substr(s + 1, (i + 1) - (s + 1))));
	}
	cout << maxn << endl;
	return 0;
}