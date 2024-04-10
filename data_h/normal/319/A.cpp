#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 200;
const long long mod = 1000000007;

char str[MAXN];
long long pow[MAXN];
int n;

int main()
{
	gets(str + 1);
	pow[0] = 1;
	n = strlen(str + 1);
	for(int i = 1; i <= n; i++)
		pow[i] = pow[i - 1] * 2 % mod;
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		if (str[i] == '1') {
			ans += (pow[i - 1] * pow[n - i] % mod * pow[n - i]) % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}