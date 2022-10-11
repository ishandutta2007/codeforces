#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

string S;
int c[26][200009];

int main() {
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		c[S[i] - 'a'][i + 1] = 1;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= S.size(); j++) c[i][j] += c[i][j - 1];
	}

	int Q; scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int cl, cr; scanf("%d%d", &cl, &cr);
		
		int cnts = 0;
		for (int j = 0; j < 26; j++) {
			if (c[j][cl - 1] != c[j][cr]) cnts++;
		}
		if (cnts == 1) {
			if (cl == cr) printf("Yes\n");
			else printf("No\n");
		}
		if (cnts == 2) {
			if (S[cl - 1] != S[cr - 1]) printf("Yes\n");
			else printf("No\n");
		}
		if (cnts >= 3) {
			printf("Yes\n");
		}
	}
	return 0;
}