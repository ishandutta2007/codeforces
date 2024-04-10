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

bool solve(string S) {
	int cnt = 0;
	for (int i = 0; i < S.size(); i++) {
		cnt += (S[i] - '0');
	}
	if (cnt % 3 != 0) return false;

	int a[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < S.size(); i++) a[S[i] - '0']++;

	if (a[0] >= 1 && a[0] + a[2] + a[4] + a[6] + a[8] >= 2) return true;
	return false;
}

int main() {
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		string T; cin >> T;
		if (solve(T) == true) cout << "red" << endl;
		else cout << "cyan" << endl;
	}
	return 0;
}