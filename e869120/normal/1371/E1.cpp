#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, P, A[1 << 18];
long long BASE;
long long R[1 << 18];
bool used[1 << 18];

void init() {
	BASE = 0;
	for (int i = 0; i < 200; i++) A[i] = 0;
	for (int i = 0; i < 200; i++) R[i] = 0;
	for (int i = 0; i < 200; i++) used[i] = false;
}

vector<long long> checker(vector<long long> val) {
	init();
	for (int i = 0; i < N; i++) A[i] = val[i];
	sort(A, A + N);

	vector<long long> ans;
	for (int i = 1; i <= 2000; i++) {
		bool flag = false;
		for (int j = 0; j < N; j++) {
			int pos1 = lower_bound(A, A + N, 1LL * (i + j) + 1LL) - A;
			int num = pos1 - j;
			if (num <= 0 || num >= P) { flag = true; break; }
		}
		if (flag == false) ans.push_back(1LL * i);
	}
	return ans;
}

vector<long long> solve(vector<long long> val) {
	init();
	for (int i = 0; i < N; i++) A[i] = val[i];
	sort(A, A + N);
	BASE = A[N - 1] - N;
	for (int i = 0; i < N; i++) BASE = max(BASE, A[i] - 1LL * i);

	for (int i = 0; i <= (A[N - 1] - BASE); i++) {
		int pos1 = lower_bound(A, A + N, BASE + 1LL * i + 1LL) - A;
		R[i] = pos1;
	}
	for (int i = 0; i <= (A[N - 1] - BASE); i++) {
		int ret = i - (R[i] % P); if (ret < 0 || R[i] < P) continue;
		used[ret] = true;
	}
	for (int i = 0; i < (1 << 18) - P; i++) {
		if (used[i + P] == true) used[i] = true;
	}

	// 
	long long maxV = A[N - 1] - N + P; vector<long long> E;
	for (int i = 0; i <= (maxV - BASE); i++) {
		if (used[i] == false) E.push_back(BASE + i);
	}
	return E;
}

int main() {
	cin >> N >> P; vector<long long> s(N, 0);
	for (int i = 0; i < N; i++) cin >> s[i];

	vector<long long> t = checker(s);
	cout << t.size() << endl;
	for (int i = 0; i < t.size(); i++) {
		if (i) cout << " "; cout << t[i];
	}
	cout << endl;
	return 0;
}