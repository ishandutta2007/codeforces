#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int MAXN = 200000;
const long long mod = 1000000007;

char str[MAXN];
int k;
long long ans = 0, base = 0;

long long poww(long long a, long long b) {
	if (b == 1)
		return a % mod;
	if (b == 0)
		return 1;
	long long t = poww(a, b / 2);
	t = t * t % mod;
	if (b % 2 == 1)
		t = t * a % mod;
	return t;
}

int main()
{
	gets(str + 1); int n = strlen(str + 1);
	scanf("%d", &k);
	for(int i = 1; i <= n; i++)
		if ((str[i] - '0') % 5 == 0)
			base = (base + poww(2, (i - 1))) % mod;
	ans = poww(2, n);
	ans = (poww(ans, k) - 1 + mod) % mod * poww(ans - 1, mod - 2) % mod;
	cout << ans * base % mod << endl;
	return 0;
}