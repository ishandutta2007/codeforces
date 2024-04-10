#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> S; T = S;
		sort(T.begin(), T.end());
		T.erase(unique(T.begin(), T.end()), T.end());

		if (S.size() == T.size()) {
			bool flag = true;
			for (int j = 0; j < T.size() - 1; j++) { if (T[j] + 1 != T[j + 1]) flag = false; }
			if (flag == true) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}