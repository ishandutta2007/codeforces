#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int N = 5004;
const int MOD = 1e9 + 7;

int n;
char seq[N];
int ways[N][N];
int diff[N][N];

// 0 not detect
// positive position
// -1 the same

int get(int i, int j) {
	if (diff[i][j] != 0) {
		return diff[i][j];
	}
	if (i > n || j > n) {
		return diff[i][j] = -1;
	}
	if (seq[i] != seq[j]) {
		return diff[i][j] = i;
	} else {
		return diff[i][j] = get(i + 1, j + 1);
	}
}

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int main() {
	cin >> n;
	scanf("%s", seq + 1);
	for (int i = 1; i <= n; i++) {
		ways[i][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (seq[i] == '0') {
			continue;
		}
		int total = 0;
		for (int j = 1; i + j - 1 <= n; j++) {
			ways[i + j - 1][j] = total;
			if (i - j >= 1) {
				int pos = get(i - j, i);
				if (pos > 0 && pos < i) {
					int delta = pos - (i - j);
					if (seq[pos] < seq[i + delta]) {
						add(ways[i + j - 1][j], ways[i - 1][j]);
					}
				}
			}
			add(total, ways[i - 1][j]);
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		add(answer, ways[n][i]);
	}
	cout << answer << endl;
}