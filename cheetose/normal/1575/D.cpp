#include<bits/stdc++.h>
using namespace std;
char S[22],Y[22];
int n;
int get_res() {
	int i, j;

	if (Y[0] == '0')return 0;
	int res;
	if (Y[0] == '_')res = 9;
	else res = 1;
	for (i = 1; i < n - 2; i++) {
		if (Y[i] == '_')res *= 10;
	}
	return res;
}

int main() {
	scanf("%s", S);
	n = strlen(S);
	int i, j;
	int ans;
	if (n == 1) {
		ans = 0;
		if (S[0] == '0')ans = 1;
		if (S[0] == 'X')ans = 1;
		if (S[0] == '_')ans = 1;
		printf("%d\n", ans);
		return 0;
	}
	if (n == 2) {
		int ans = 0;
		if (S[0] == '0')ans = 0;
		if (S[n - 2] == '2') {
			if (S[n - 1] == '0')ans = 0;
			if (S[n - 1] == '5')ans = 1;
			if (S[n - 1] == 'X')ans = 1;
			if (S[n - 1] == '_')ans = 1;
		}
		if (S[n - 2] == '5') {
			if (S[n - 1] == '0')ans = 1;
			if (S[n - 1] == '5')ans = 0;
			if (S[n - 1] == 'X')ans = 1;
			if (S[n - 1] == '_')ans = 1;
		}
		if (S[n - 2] == '7') {
			if (S[n - 1] == '0')ans = 0;
			if (S[n - 1] == '5')ans = 1;
			if (S[n - 1] == 'X')ans = 1;
			if (S[n - 1] == '_')ans = 1;
		}
		if (S[n - 2] == 'X') {
			if (S[n - 1] == '0')ans = 1;
			if (S[n - 1] == '5')ans = 2;
			if (S[n - 1] == 'X')ans = 0;
			if (S[n - 1] == '_')ans = 3;
		}
		if (S[n - 2] == '_') {
			if (S[n - 1] == '0')ans = 1;
			if (S[n - 1] == '5')ans = 2;
			if (S[n - 1] == 'X')ans = 3;
			if (S[n - 1] == '_')ans = 3;
		}
		printf("%d\n", ans);
		return 0;
	}
	ans = 0;
	int is_x = 0;
	for (i = 0; i < n; i++) {
		if (S[i] == 'X')is_x = 1;
	}
	for (int x = 0; x <= is_x * 9; x++) {
		for (int i = 0; i < n; i++) {
			if (S[i] == 'X')Y[i] = x + '0';
			else Y[i] = S[i];
		}
		if (Y[n - 2] == '0') {
			if (Y[n - 1] == '0')ans += get_res();
			if (Y[n - 1] == '_')ans += get_res();
		}
		if (Y[n - 2] == '2') {
			if (Y[n - 1] == '5')ans += get_res();
			if (Y[n - 1] == '_')ans += get_res();
		}
		if (Y[n - 2] == '5') {
			if (Y[n - 1] == '0')ans += get_res();
			if (Y[n - 1] == '_')ans += get_res();
		}
		if (Y[n - 2] == '7') {
			if (Y[n - 1] == '5')ans += get_res();
			if (Y[n - 1] == '_')ans += get_res();
		}
		if (Y[n - 2] == '_') {
			if (Y[n - 1] == '0')ans += 2 * get_res();
			if (Y[n - 1] == '5')ans += 2 * get_res();
			if (Y[n - 1] == '_')ans += 4 * get_res();
		}
	}
	printf("%d\n", ans);

	return 0;
}