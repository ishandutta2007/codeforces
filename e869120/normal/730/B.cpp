#include<iostream>
#include<vector>
using namespace std;
int T, n;
int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n; vector<int>u, d;
		for (int j = 1; j <= n - 1; j += 2) {
			cout << "? " << j << " " << j + 1 << endl;
			char F; cin >> F;
			if (F == '<') { u.push_back(j + 1); d.push_back(j); }
			if (F == '>') { u.push_back(j); d.push_back(j + 1); }
			if (F == '=') { u.push_back(j); d.push_back(j); }
		}
		if (n % 2 == 1) { u.push_back(n); d.push_back(n); }
		while (u.size() > 1) {
			vector<int>A = u; u.clear();
			for (int j = 0; j < A.size() - 1; j += 2) {
				cout << "? " << A[j] << " " << A[j + 1] << endl;
				char F; cin >> F;
				if (F == '>') { u.push_back(A[j]); }
				if (F == '<') { u.push_back(A[j + 1]); }
				if (F == '=') { u.push_back(A[j]); }
			}
			if (A.size() % 2 == 1)u.push_back(A[A.size() - 1]);
		}
		while (d.size() > 1) {
			vector<int>A = d; d.clear();
			for (int j = 0; j < A.size() - 1; j += 2) {
				cout << "? " << A[j] << " " << A[j + 1] << endl;
				char F; cin >> F;
				if (F == '<') { d.push_back(A[j]); }
				if (F == '>') { d.push_back(A[j + 1]); }
				if (F == '=') { d.push_back(A[j]); }
			}
			if (A.size() % 2 == 1)d.push_back(A[A.size() - 1]);
		}
		cout << "! " << d[0] << " " << u[0] << endl;
	}
	return 0;
}