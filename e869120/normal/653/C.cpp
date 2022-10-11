#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
#pragma warning(disable:4996)
int n, t[180000]; vector<int>D; map<int, int>M[180000];
int main() {
	cin >> n; for (int i = 0; i < n; i++)scanf("%d", &t[i]);
	for (int i = 0; i < n - 1; i++) {
		if (t[i] >= t[i + 1] && i % 2 == 0) { D.push_back(i); D.push_back(i - 1); D.push_back(i + 1); }
		if (t[i] <= t[i + 1] && i % 2 == 1) { D.push_back(i); D.push_back(i + 1); D.push_back(i - 1); }
	}
	vector<int>E; for (int i = 0; i < D.size(); i++) { if (D[i] >= 0 && D[i] < n)E.push_back(D[i]); }
	D = E;
	if (D.size() > 12) { cout << "0" << endl; return 0; }
	int cnt = 0;
	for (int i = 0; i < D.size(); i++) {
		for (int j = 0; j < n; j++) {
			int a = D[i], b = j; if (a > b)swap(a, b);
			if (M[a][b] == 1)continue;
			if (D[i] == j)continue;

			swap(t[D[i]], t[j]); M[a][b] = 1;
			vector<int>R;
			R.push_back(D[i]);
			R.push_back(j); R.push_back(j + 1); R.push_back(j - 1);
			for (int k = 0; k < D.size(); k++) { R.push_back(D[k]); }
			sort(R.begin(), R.end());

			vector<int>S;
			for (int k = 0; k < R.size(); k++) { if (R[k] >= 0 && R[k] < n - 1)S.push_back(R[k]); }

			bool OK = true;
			for (int k = 0; k < S.size(); k++) {
				if (S[k] % 2 == 0 && t[S[k]] >= t[S[k] + 1])OK = false;
				if (S[k] % 2 == 1 && t[S[k]] <= t[S[k] + 1])OK = false;
			}
			swap(t[D[i]], t[j]);
			if (OK == true)cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}