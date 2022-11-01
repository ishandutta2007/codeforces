#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int N = 111111;
const int MOD = 1e9 + 7;

int length[10], answer[10];
char s[N];
int n;
string opt[N];
char buf[N];

int power(long long a, long long b) {
	if (b == 0) {
		return 1 % MOD;
	}
	int temp = power(a, b >> 1);
	if (b & 1) {
		return 1LL * temp * temp % MOD * (a % MOD) % MOD;
	} else {
		return 1LL * temp * temp % MOD;
	}
}

int main() {
	scanf("%s", s + 1);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", buf);
		opt[i] = buf;
	}	
	
	for(int i = 0; i < 10; i++) {
		length[i] = 1;
		answer[i] = i % MOD;
	}
	
	for(int i = n; i >= 1; i--) {
		int s = opt[i][0] - '0';
		long long l = 0, res = 0;
		for(int j = (int)opt[i].size() - 1; j > 2; j--) {
			int t = opt[i][j] - '0';
			res += 1LL * answer[t] * power(10, l);
			l += length[t];
			l %= (MOD - 1);
			res %= MOD;
		}
		length[s] = l;
		answer[s] = res;
	}
	int len = strlen(s + 1);
	long long result = 0, tot = 0;
	for(int i = len; i >= 1; i--) {
		int x = s[i] - '0';
		result += 1LL * answer[x] * power(10, tot);
		result %= MOD;
		tot += length[x];
		tot %= MOD - 1;
	}
	cout << result << endl;
	return 0;
}