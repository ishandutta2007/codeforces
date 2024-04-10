#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

string S; int cnt = 0;

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'a') cnt++;
	}
	cout << min(cnt * 2 - 1, (int)S.size()) << endl;
	return 0;
}