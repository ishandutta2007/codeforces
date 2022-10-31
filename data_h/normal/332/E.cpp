#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1100000;

char str1[MAXN], str2[MAXN];
int n, k, len1, len2;
string ans = "";


int ok(int pos1, int pos2, int per1, int per2) {
	for(; pos2 <= len2; pos2 += per2, pos1 += per1) {
		if (pos1 > len1)
			return 0;
		if (str1[pos1] != str2[pos2])
			return 0;
	}
	if (pos1 <= len1)
		return 0;
	return 1;
}

void Solve(int per) {
	
	string tmp;
	for (int i = 1; i <= n; i++)
		tmp += '0';
	int j = per;
	for(int i = n; i >= 1; i--) {
		if (j && str1[i] == str2[j] && ok(i, j, n, per)) {
			tmp[i - 1] = '1';
			j--;
		}
	}
	if (j)
		return;
	if (ans == "" || tmp < ans)
		ans = tmp;
}

int main() {
	gets(str1 + 1); len1 = strlen(str1 + 1);
	gets(str2 + 1); len2 = strlen(str2 + 1);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		Solve(i);
	}
	if (ans == "") {
		puts("0");
	} else {
		cout << ans << endl;
	}
	
	return 0;
}