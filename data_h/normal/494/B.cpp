#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 111111;
const int MOD = 1e9 + 7;

char s[N], t[N];

#define next NEXT

int n, m, sum[N], sum2[N];
int next[N], match[N], f[N];

void add(int &a, int b) {
	if ((a += b) >= MOD) {
		a -= MOD;
	}
}

int main() {
	scanf("%s", s); n = strlen(s);
	scanf("%s", t); m = strlen(t);

	next[0] = -1;
	for(int i = 1; i < m; i++) {
		int j = next[i - 1];
		while (j >= 0 && t[j + 1] != t[i]) {
			j = next[j];
		}
		if (t[i] != t[j + 1]) {
			next[i] = -1;
		} else {
			next[i] = j + 1;
		}
	}
	t[m] = '#';

	/*cout << t << endl;
	for(int i = 0; i < m; i++) {
		cout << next[i] << " ";
	}
	cout << endl;
	*/
	int answer = 0, last = -1;
	for(int i = 0, j = 0; i < n; i++) {
		while(j > 0 && t[j] != s[i]) {
			j = next[j - 1] + 1;
		}
		if (t[j] == s[i]) {
			j++;
		}
		//cout << j << endl;
		if (j == m) {
			f[i] = ((i - m >= 0 ? sum2[i - m] : 0) + i - m + 2) % MOD;
		} else {
			f[i] = (i > 0) ? f[i - 1] : 0;
		}
		if (i) {
			sum2[i] = sum2[i - 1];
			sum[i] = sum[i - 1];
		}
		add(sum[i], f[i]);
		add(sum2[i], sum[i]);
	}

	cout << sum[n - 1] << endl;
	return 0;
}