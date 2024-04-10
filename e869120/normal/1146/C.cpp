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

int ask(vector<int>v1, vector<int>v2) {
	if (v1.size() == 0 || v2.size() == 0) return 0;

	cout << v1.size() << " " << v2.size();
	for (int i = 0; i < v1.size(); i++) cout << " " << v1[i];
	for (int i = 0; i < v2.size(); i++) cout << " " << v2[i];
	cout << endl;

	int G; cin >> G;
	return G;
}

int solve(int P) {
	int ret = 0;
	for (int i = 6; i >= 0; i--) {
		vector<int>R1, R2;
		for (int j = 0; j < P; j++) {
			if ((j / (1 << i)) % 2 == 0) R1.push_back(j + 1);
			if ((j / (1 << i)) % 2 == 1) R2.push_back(j + 1);
		}
		int J = ask(R1, R2);
		ret = max(ret, J);
	}
	return ret;
}

int T, N;

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		int G = solve(N);
		cout << "-1 " << G << endl;
	}
	return 0;
}