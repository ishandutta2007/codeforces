#include <iostream>
#include <vector>
using namespace std;

int M, N, L[100009], R[100009], A[100009];

int main() {
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		cin >> L[i] >> R[i];
		for (int j = L[i]; j <= R[i]; j++) A[j]++;
	}
	vector<int>vec;
	for (int i = 1; i <= N; i++) { if (A[i] == 0) vec.push_back(i); }
	cout << vec.size() << endl;
	if (vec.size() >= 1) {
		for (int i = 0; i < vec.size(); i++) {
			if (i) cout << " ";
			cout << vec[i];
		}
		cout << endl;
	}
	return 0;
}