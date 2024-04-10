#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 111111;

char s[N];
int n, number[4];
long long maxV = 0, answer = 0;

long long power(int a, int n) {
	int ret = 1;
	for(int i = 1; i <= n; i++) {
		ret = 1LL * ret * a % MOD;
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) {
		if (s[i] == 'A') {
			number[0]++;
		} else if (s[i] == 'G') {
			number[1]++;
		} else if (s[i] == 'C') {
			number[2]++;
		} else {
			number[3]++;
		}
	}
	sort(number, number + 4);
	if (number[3] > number[2]) {
		puts("1");
	} else if (number[2] > number[1]) {
		cout << power(2, n) << endl;
	} else if (number[1] > number[0]) {
		cout << power(3, n) << endl;
	} else {
		cout << power(4, n) << endl;
	}
	return 0;
}