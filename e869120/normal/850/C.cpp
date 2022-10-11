#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map<vector<int>, int> Map;

int grundy(vector<int>vec) {
	if (Map[vec] >= 1) return Map[vec] - 1;

	bool flag = false; vector<int>I(33, 0);
	for (int i = 31; i >= 1; i--) {
		if (vec[i] >= 1) flag = true;
		if (flag == false) continue;

		vector<int>vec2(32, 0);
		for (int j = 0; j < 32; j++) {
			if (vec[j] == 0) continue;
			if (j < i) vec2[j] = 1;
			else vec2[j - i] = 1;
		}
		int Z = grundy(vec2);
		I[Z] = 1;
	}
	for (int i = 0; i <= 32; i++) {
		if (I[i] == 0) { Map[vec] = i + 1; return i; }
	}
	return 31;
}

long long N, A[109];
vector<long long>E;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i]; int cx = A[i];
		for (int j = 2; j*j <= cx; j++) {
			if (cx % j == 0) { E.push_back(j); while (cx%j == 0) cx /= j; }
		}
		if (cx >= 2) E.push_back(cx);
	}
	sort(E.begin(), E.end());
	E.erase(unique(E.begin(), E.end()), E.end());

	int S = 0;
	for (int i = 0; i < E.size(); i++) {
		vector<int>vec(32, 0);
		for (int j = 0; j < N; j++) {
			int cnt = 0, cx = A[j];
			while (cx%E[i] == 0) { cx /= E[i]; cnt++; }
			vec[cnt] = 1;
		}
		int K = grundy(vec);
		S ^= K;
	}
	if (S >= 1) cout << "Mojtaba" << endl;
	else cout << "Arpa" << endl;
	return 0;
}