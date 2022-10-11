#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = 1100000;

int n; char c[MAX_N + 9]; string S[100009];
vector<int>vec[MAX_N + 9][5]; int id[MAX_N + 9][5];

int p[1000009][4];

void solve() {
	int V1 = 0, V2 = 0;
	for (int i = 0; i <= MAX_N; i++) {
		int sum = 0;
		for (int j = 0; j < 5; j++) {
			V1 += (vec[i][j].size() / 2);
			sum += vec[i][j].size();
		}
		V2 += (sum / 2);
	}

	int maxn = min(V1, V2 / 2);
	int cnt1 = 0;
	for (int i = 0; i <= MAX_N; i++) {
		for (int j = 0; j < 5; j++) {
			while (id[i][j] + 2 <= (int)vec[i][j].size()) {
				p[cnt1][1] = vec[i][j][id[i][j]];
				p[cnt1][3] = vec[i][j][id[i][j] + 1];
				id[i][j] += 2;
				cnt1++;
				if (cnt1 == maxn) break;
			}
			if (cnt1 == maxn) break;
		}
		if (cnt1 == maxn) break;
	}

	cnt1 = 0;
	for (int i = 0; i <= MAX_N; i++) {
		vector<int>vec2;
		for (int j = 0; j < 5; j++) {
			for (int k = id[i][j]; k < vec[i][j].size(); k++) vec2.push_back(vec[i][j][k]);
		}
		for (int j = 0; j < (int)vec2.size() - 1; j += 2) {
			p[cnt1][0] = vec2[j];
			p[cnt1][2] = vec2[j + 1];
			cnt1++;
			if (cnt1 == maxn) break;
		}
		if (cnt1 == maxn) break;
	}

	cout << maxn << endl;
	for (int i = 0; i < cnt1; i++) {
		cout << S[p[i][0]] << " " << S[p[i][1]] << endl;
		cout << S[p[i][2]] << " " << S[p[i][3]] << endl;
	}
}

int main() {
	// Input
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &c);
		string str = "";
		for (int j = 0; j <= MAX_N; j++) {
			if (c[j] == 0) break;
			str += (char)(c[j]);
			c[j] = 0;
		}
		S[i] = str;

		int lastvow = 0, vow = 0;
		for (int j = 0; j < S[i].size(); j++) {
			int root = -1;
			if (S[i][j] == 'a') root = 0;
			if (S[i][j] == 'e') root = 1;
			if (S[i][j] == 'i') root = 2;
			if (S[i][j] == 'o') root = 3;
			if (S[i][j] == 'u') root = 4;
			if (root != -1) {
				vow++;
				lastvow = root;
			}
		}
		vec[vow][lastvow].push_back(i);
	}

	// calculation
	solve();
	return 0;
}