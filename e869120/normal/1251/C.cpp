#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T; string S;

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> S;
		vector<char> V1, V2;
		for (int i = 0; i < S.size(); i++) {
			if ((S[i] - '0') % 2 == 0) V1.push_back(S[i]);
			else V2.push_back(S[i]);
		}
		int t1 = 0, t2 = 0; string V = "";
		while (t1 + t2 < S.size()) {
			if (t1 == V1.size()) { V += V2[t2]; t2++; }
			else if (t2 == V2.size()) { V += V1[t1]; t1++; }
			else if (V1[t1] < V2[t2]) { V += V1[t1]; t1++; }
			else { V += V2[t2]; t2++; }
		}
		cout << V << endl;
	}
	return 0;
}