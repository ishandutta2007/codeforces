#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], maxn, used1[2009][2009], used2[2009][2009];
vector<int>vec;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) { scanf("%d", &A[i]); vec.push_back(A[i]); }
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 1; i <= N; i++) A[i] = lower_bound(vec.begin(), vec.end(), A[i]) - vec.begin();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) used1[i][A[j]]++;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) used2[i][A[j]]++;
	}
	for (int i = 0; i <= N; i++) {
		int cl = i + 1, cr = N + 2, cm;
		for (int j = 0; j < 15; j++) {
			cm = (cl + cr) / 2;
			bool flag = false;
			for (int k = 0; k < vec.size(); k++) {
				int p = used1[i][k] + used2[cm][k];
				if (p >= 2) flag = true;
			}
			if (flag == false) {
				maxn = max(maxn, i + (N + 1 - cm)); cr = cm;
			}
			else { cl = cm; }
		}
	}
	cout << N - maxn << endl;
	return 0;
}