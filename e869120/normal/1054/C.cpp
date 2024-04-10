#include <iostream>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, L[1009], R[1009], A[1009];

void adds(int pos) {
	for (int i = 1; i < pos; i++) { if (A[i] == 0) R[i]--; }
	for (int i = pos + 1; i <= N; i++) { if (A[i] == 0) L[i]--; }
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> L[i];
	for (int i = 1; i <= N; i++) cin >> R[i];

	for (int i = 1; i <= N; i++) {
		vector<int>vec;
		for (int j = 1; j <= N; j++) {
			if (A[j] == 0 && L[j] == 0 && R[j] == 0) { A[j] = i; vec.push_back(j); }
		}
		for (int j = 0; j < vec.size(); j++) adds(vec[j]);
		if (vec.size() == 0) break;
	}

	bool flag = true;
	for (int i = 1; i <= N; i++) { if (A[i] == 0) flag = false; }

	if (flag == false) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		for (int i = 1; i <= N; i++) { if (i >= 2) cout << " "; cout << (N + 1) - A[i]; } cout << endl;
	}
	return 0;
}