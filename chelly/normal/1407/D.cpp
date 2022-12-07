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
const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], dp[N];
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	dp[1] = 0;
	vector<int> mx, mn;
	mx.pb(1);
	mn.pb(1);
	for(int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		if(a[i - 1] == a[i]) {
			mn.back() = i;
			mx.back() = i;
			continue;
		}
		if(a[i - 1] < a[i]) {
			while(!mx.empty() && a[mx.back()] < a[i]) {
				dp[i] = min(dp[i], dp[mx.back()] + 1);
				mx.pop_back();
			}
			if(!mx.empty()) {
				dp[i] = min(dp[i], dp[mx.back()] + 1);
				if(a[mx.back()] == a[i]) mx.pop_back();
			}
		}else {
			while(!mn.empty() && a[mn.back()] > a[i]) {
				dp[i] = min(dp[i], dp[mn.back()] + 1);
				mn.pop_back();
			}
			if(!mn.empty()) {
				dp[i] = min(dp[i], dp[mn.back()] + 1);
				if(a[mn.back()] == a[i]) mn.pop_back();
			}
		}
		mn.pb(i);
		mx.pb(i);
	}
	cout << dp[n] << endl;
}