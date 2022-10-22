/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 4, M = 13, K = 32;
int a1[N][M][K];
int tt[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int32_t main() {
	string s;
	cin >> s;
	int n = s.size();
	int mx = 0;
	for (int i = 0; i <= n - 10; i++) {
		string t;
		for (int j = i; j < i + 10; j++) {
			t += s[j];
		}
		if (t[2] != '-' || t[5] != '-') {
			continue;
		}
		if (!isdigit(t[0]) || !isdigit(t[1]) || !isdigit(t[3]) || !isdigit(t[4]) || !isdigit(t[6]) || !isdigit(t[7]) || !isdigit(t[8]) || !isdigit(t[9])) {
			continue;
		}
		string a, b, c;
		a += t[0];
		a += t[1];
		b += t[3];
		b += t[4];
		c += t[6];
		c += t[7];
		c += t[8];
		c += t[9];
		int aa = stoi(a), bb = stoi(b), cc = stoi(c);
		if (cc < 2013 || cc > 2015 || bb < 1 || bb > 12 || aa < 1 || aa > tt[bb]) {
			continue;
		}
		a1[cc - 2013][bb][aa]++;
		mx = max(mx, a1[cc - 2013][bb][aa]);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < K; k++) {
				if (a1[i][j][k] == mx) {
					if (k < 10)
						cout << 0;
					cout << k << '-';
					if (j < 10) 
						cout << 0;
					cout << j << '-' << i + 2013 << '\n';
				}
			}
		}
	}
}