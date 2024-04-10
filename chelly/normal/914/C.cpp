#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef complex<double> Complex;
#define fi first
#define se second
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
const int N = 1011;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int dp[N][2][N];
int a[N], num[N];
int main() {
	string st;
	cin >> st;
	int k;
	k = getInt();
	int l(st.size());
	for(int i(1); i <= l; i++) a[i] = st[i - 1] - '0';
	dp[0][1][0] = 1;
	for(int i(1); i <= l; i++) {
		for(int j(0); j <= i; j++) {
			dp[i][1][j + a[i]] = (dp[i][1][j + a[i]] + dp[i - 1][1][j]) % mod;
			dp[i][0][j + 0] = (dp[i][0][j + 0] + dp[i - 1][0][j]) % mod;
			dp[i][0][j + 1] = (dp[i][0][j + 1] + dp[i - 1][0][j]) % mod;
			if(a[i]) dp[i][0][j + 0] = (dp[i][0][j + 0] + dp[i - 1][1][j]) % mod;
		}
	}
	num[1] = 0;
	for(int i(2); i <= 1000; i++) {
		num[i] = num[__builtin_popcount(i)] + 1;
	}
	if(k == 0) {
		printf("1\n");
		return 0;
	}
	int ans = 0;
	for(int i(1); i <= l; i++) {
		if(num[i] == k - 1) ans = (ans + (LL)dp[l][0][i] + dp[l][1][i]) % mod;
	}
	if(k == 1) {
		ans = (ans - 1 + mod) % mod;
	}
	cout << ans << endl;
}