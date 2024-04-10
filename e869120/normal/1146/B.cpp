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
	for (int i = 0; i <= 100000; i++) {
		int L1 = i, L2 = i - cnt;
		if (L1 + L2 == S.size() && L1 >= 0 && L2 >= 0) {
			string V = S.substr(0, L1), W;
			for (int j = 0; j < V.size(); j++) {
				if (V[j] != 'a') W += V[j];
			}
			V += W;
			if (V == S) {
				cout << S.substr(0, L1) << endl;
				return 0;
			}
		}
	}
	cout << ":(" << endl;
	return 0;
}