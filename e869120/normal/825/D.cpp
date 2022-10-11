#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
using namespace std;
string S, T; long long a[26], b[26], c[26], t;
int main() {
	cin >> S >> T;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '?')t++; else a[S[i] - 'a']++;
	}
	for (int i = 0; i < T.size(); i++)b[T[i] - 'a']++;
	for (int i = 1; i <= 1000002; i++) {
		long long I = 0;
		for (int j = 0; j < 26; j++) {
			I += max(0LL, 1LL * b[j] * i - a[j]);
		}
		if (I > t) {
			for (int j = 0; j < 26; j++)c[j] = b[j] * (i - 1) - a[j];
			for (int j = 0; j < S.size(); j++) {
				if (S[j] == '?') {
					for (int k = 0; k < 26; k++) {
						if (c[k] >= 1) { S[j] = ('a' + k); c[k]--; break; }
					}
					if (S[j] == '?')S[j] = 'a';
				}
			}
			cout << S << endl;
			break;
		}
	}
	return 0;
}