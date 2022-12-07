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
const int N = 1511;
const int LOG = 20;
const int mod = 998244353;
const int inf = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int rela[N], siz[N], m[N], dp[N][N], tmp[N];
int getr(int x) {
	int p = x;
	while(p != rela[p]) p = rela[p];
	int p1 = p; p = x;
	while(p != rela[p]) {
		int p2 = rela[p];
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, pair<int, int> > >v;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if(i < j) {
				v.pb(make_pair(x, make_pair(i, j)));
			}
		}
	}
	sort(all(v));
	for(int i = 1; i <= n; i++) {
		rela[i] = i;
		siz[i] = 1;
		m[i] = 0;
		dp[i][1] = 1;
	}
	for(int i = 0; i < (int)v.size(); i++) {
		int z = v[i].fi;
		int x = v[i].se.fi, y = v[i].se.se;
		//printf("%d %d\n", x, y);
		x = getr(x);
		y = getr(y);
		if(x == y) {
			m[x]++;
			dp[x][1] = m[x] == siz[x] * (siz[x] - 1) / 2;
		}else {
			fill(tmp, tmp + siz[x] + siz[y] + 1, 0);
			for(int j = 1; j <= siz[x]; j++) {
				for(int k = 1; k <= siz[y]; k++) {
					//cout << j << ' ' << k << ' ' << dp[x][i] * dp[y][j] << endl;
					tmp[j + k] = (tmp[j + k] + (LL)dp[x][j] * dp[y][k]) % mod;
				}
			}
			for(int j = 2; j <= siz[x] + siz[y]; j++) {
				dp[x][j] = tmp[j];
			}
			siz[x] += siz[y];
			m[x] += m[y] + 1;
			rela[y] = x;
			dp[x][1] = m[x] == siz[x] * (siz[x] - 1) / 2;
		}
		//for(int i = 1; i <= siz[x]; i++) printf("[%d]", dp[x][i]);
		//printf("\n");
	}
	int x = getr(1);
	for(int i = 1; i <= n; i++) {
		printf("%d%c", dp[x][i], i == n ? '\n' : ' ');
	}
}