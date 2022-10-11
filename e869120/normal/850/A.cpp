#include <iostream>
#include <vector>
using namespace std;

int N, A[1009][5];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) cin >> A[i][j];
	}

	if (N > 243) {
		cout << "0" << endl;
		return 0;
	}

	vector<int>ans;
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int L = 0;
				for (int l = 0; l < 5; l++) L += (A[j][l] - A[i][l]) * (A[k][l] - A[i][l]);
				if (L > 0) flag = true;
			}
		}
		if (flag == false) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << endl;
	return 0;
}