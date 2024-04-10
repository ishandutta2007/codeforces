#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<functional>
#include<queue>
using namespace std;
#pragma warning(disable:4996)
string S; int p[2000], r[26][2000], n, q;
int main() {
	cin >> n >> S;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j <= S.size(); j++)p[j] = 0;
		for (int j = 0; j < S.size(); j++) { if (S[j] == ('a' + i))p[j + 1] = 1; }
		for (int j = 1; j <= S.size(); j++)p[j] += p[j - 1];
		for (int j = 0; j <= S.size(); j++) {
			for (int k = j + 1; k <= S.size(); k++) {
				r[i][(k - j) - (p[k] - p[j])] = max(r[i][(k - j) - (p[k] - p[j])], k - j);
			}
		}
		for (int j = 1; j <= S.size(); j++)r[i][j] = max(r[i][j], r[i][j - 1]);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		char c; int p;
		scanf("%d", &p); cin >> c;
		printf("%d\n", r[c - 'a'][p]);
	}
	return 0;
}