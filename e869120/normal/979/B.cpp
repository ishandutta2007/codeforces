#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n; string S[3];

int solve(string V) {
	int z[256];
	for (int i = 0; i < 256; i++) z[i] = 0;
	for (int i = 0; i < V.size(); i++) {
		z[V[i]]++;
	}
	int maxn = 0;
	for (int i = 0; i < 256; i++) {
		if (z[i] + n < V.size()) maxn = max(maxn, z[i] + n);
		else {
			int s = V.size(); if (z[i] + n == V.size() + 1 && n == 1) s--;
			maxn = max(maxn, s);
		}
	}
	return maxn;
}

int ret[3];

int main() {
	cin >> n >> S[0] >> S[1] >> S[2];
	int maxn = -1;
	for (int i = 0; i < 3; i++) {
		ret[i] = solve(S[i]);
		maxn = max(maxn, ret[i]);
	}
	vector<int>vec;
	for (int i = 0; i < 3; i++) { if (ret[i] == maxn) vec.push_back(i); }
	if (vec.size() >= 2) cout << "Draw" << endl;
	else if (vec[0] == 0) cout << "Kuro" << endl;
	else if (vec[0] == 1) cout << "Shiro" << endl;
	else cout << "Katie" << endl;
	return 0;
}