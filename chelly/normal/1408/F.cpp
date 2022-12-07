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
const int N = 111;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], f[N][N];
int main() {
	int n;
	scanf("%d", &n);
	if(n <= 2) {
		printf("0\n");
		return 0;
	}
	vector<pair<int, int> > ans;
	int mx = 1;
	for(int len = 2; len <= n; len *= 2) {
		mx = len;
		for(int i = 1; i + len - 1 <= n; i += len) {
			for(int j = 0; j < len / 2; j++) {
				ans.pb({i + j, i + j + len / 2});
			}
		}
	}
	for(int len = 2; len <= n; len *= 2) {
		for(int i = 0; i < mx; i += len) {
			for(int j = 0; j < len / 2; j++) {
				ans.pb({n - i - j, n - i - j - len / 2});
			}
		}
	}
	printf("%d\n", (int)ans.size());
	for(int i = 0; i < (int)ans.size(); i++) {
		printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	if(false) {
		for(;;) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) f[i][j] = gene() % n + 1;
				a[i] = gene() % n + 1;
			}
			for(auto t : ans) {
				int tmp = f[a[t.fi]][a[t.se]];
				a[t.fi] = tmp; a[t.se] = tmp;
			}
			set<int> mp;
			for(int i = 1; i <= n; i++) {
				mp.insert(a[i]);
			}
			assert(mp.size() <= 2);
			//cout << *mp.begin() << ' ' << *mp.rbegin() << endl;
		}
	}
}