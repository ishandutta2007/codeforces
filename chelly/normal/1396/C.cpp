#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
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

inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
	fwrite(buf, 1, _bl, stdout);
	_bl = 0;
}
__inline void _putchar(char c) {
	if(_bl == _B) flush();
	buf[_bl++] = c;
}
inline void print(LL x, char c) {
	static char tmp[20];
	int l = 0;
	if(!x) tmp[l++] = '0';
	else {
		while(x) {
			tmp[l++] = x % 10 + '0';
			x /= 10;
		}
	}
	for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
	_putchar(c);
}
struct P {
	D x, y;
};
const int N = 1000033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
LL a[N], dp[N][2];
int main() {
	int n;
	scanf("%d", &n);
	LL r1, r2, r3, d;
	scanf("%I64d%I64d%I64d%I64d", &r1, &r2, &r3, &d);
	for(int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++) {
		//cout << a[i] << endl;
		//cout << dp[i - 1][0] << ' ' << dp[i - 1][1] << r1 << ' ' << r2 << ' ' << r3 << endl;
		dp[i][0] = min(dp[i][0], dp[i - 1][0] + r1 * a[i] + r3);
		dp[i][0] = min(dp[i][0], dp[i - 1][1] + min(r2 + r1, r1 * (a[i] + 2)) + 2 * d);
		dp[i][1] = min(dp[i][1], dp[i - 1][0] + min(r2 + r1, r1 * (a[i] + 2)));
		dp[i][0] = min(dp[i][0], dp[i - 1][0] + min(r2 + r1, r1 * (a[i] + 2)) + 2 * d);
	}
	dp[n][0] = min(dp[n][0], dp[n - 1][1] + r1 * a[n] + r3 + d);
	cout << dp[n][0] + d * (n - 1) << endl;
}