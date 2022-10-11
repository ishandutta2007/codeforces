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

int N, A[1 << 19];
long long ret = 0;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for (int i = 0; i < 26; i++) {
		vector<int> vec;
		for (int j = 1; j <= N; j++) vec.push_back(A[j] % (2 << i));
		sort(vec.begin(), vec.end());

		int c1 = 0, c2 = 0, c3 = 0; long long sum = 0;
		for (int j = vec.size() - 1; j >= 0; j--) {
			while (c1 < vec.size() && vec[j] + vec[c1] < (1 << i)) c1++;
			while (c2 < vec.size() && vec[j] + vec[c2] < (2 << i)) c2++;
			while (c3 < vec.size() && vec[j] + vec[c3] < (3 << i)) c3++;
			sum += 1LL * (max(j + 1, c2) - max(j + 1, c1));
			sum += 1LL * (max(j + 1, (int)vec.size()) - max(j + 1, c3));
		}
		if (sum % 2 == 1) ret += (1LL << i);
	}
	cout << ret << endl;
	return 0;
}