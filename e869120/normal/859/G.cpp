#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[1 << 18];
vector<int>vec;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { char c; cin >> c; A[i] = (c - '0'); }

	int cx = N;
	for (int i = 2; i <= N; i++) {
		if (cx%i == 0) vec.push_back(i);
		while (cx%i == 0) cx /= i;
	}

	for (int t = 0; t < vec.size(); t++) {
		vector<pair<int, int>>vec3;
		int s = 1, cx = N; while (cx%vec[t] == 0) { cx /= vec[t]; s *= vec[t]; }
		for (int i = 0; i < N; i++) vec3.push_back(make_pair(i % s, i));
		sort(vec3.begin(), vec3.end());

		vector<int>vec2; for (int i = 0; i < (N / vec[t]); i++) vec2.push_back(vec3[i].second);

		for (int j : vec2) {
			int BASE = A[j];
			for (int k = 0; k < N; k += (N / vec[t])) {
				A[(j + k) % N] -= BASE;
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < N; i++) { if (A[i] != 0) flag = true; }
	if (flag == false) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}