#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int B = 18;

int N, A[1 << 18], minx = 0;
vector<int>E[22], L = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

vector<int> solve(int pos) {
	int bit[20]; for (int i = 0; i < 20; i++) { if ((-pos / (1 << i)) % 2 == 1) bit[i] = 1; else bit[i] = 0; }

	for (int i = 0; i < 20; i++) {
		int G = pos % (2 << i);
		int pos1 = lower_bound(E[i].begin(), E[i].end(), G + (1 << i)) - E[i].begin();
		int pos2 = lower_bound(E[i].begin(), E[i].end(), G + (2 << i)) - E[i].begin();
		if (pos2 - pos1 >= 1) bit[i] = 1;
	}

	vector<int> J;
	for (int i = 0; i < 20; i++) {
		if ((-pos / (1 << i)) % 2 == 1) J.push_back(-(1 << i));
		else if (bit[i] == 1) J.push_back((1 << i));
	}
	return J;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]); minx = min(minx, A[i]);
		for (int j = 0; j < 20; j++) E[j].push_back((A[i] + 2097152) % (2 << j));
	}
	for (int i = 0; i < 20; i++) {
		sort(E[i].begin(), E[i].end());
		for (int j = 0; j < N; j++) E[i].push_back(E[i][j] + (2 << i));
	}

	for (int i = -(1 << B) + 1; i <= minx; i++) {
		vector<int>J = solve(i);
		if (L.size() > J.size()) { L = J; }
	}
	cout << L.size() << endl;
	for (int i = 0; i < L.size(); i++) { if (i) cout << " "; cout << L[i]; } cout << endl;
	return 0;
}