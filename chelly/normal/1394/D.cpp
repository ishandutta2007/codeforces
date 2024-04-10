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
int t[N], h[N];
int fa[N];
vector<int> e[N];
LL dp[N][2];
int main() {
	int n;
	n = getInt();
	for(int i = 1; i <= n; i++) {
		t[i] = getInt();
	}
	for(int i = 1; i <= n; i++) {
		h[i] = getInt();
	}
	for(int i = 1; i < n; i++) {
		int x, y;
		x = getInt();
		y = getInt();
		e[x].pb(y);
		e[y].pb(x);
	}
	vector<int> q;
	q.pb(1);
	fa[1] = 0;
	for(int op = 0; op < (int)q.size(); op++) {
		int v = q[op];
		for(int y: e[v]) {
			if(y != fa[v]) {
				fa[y] = v;
				q.pb(y);
			}
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	for(int i = n - 1; i >= 0; i--) {
		int v = q[i];
		static vector<LL> a[3];
		a[0].clear();
		a[1].clear();
		a[2].clear();
		LL sum = 0;
		LL cnt[3] = {0, 0, 0};
		for(int y : e[v]) {
			if(y == fa[v]) continue;
			if(h[y] > h[v]) {
				a[0].pb(dp[y][0]);
				cnt[0] += dp[y][0];
			}else if(h[y] < h[v]) {
				a[2].pb(dp[y][1]);
				cnt[2] += dp[y][1];
			}else {
				a[1].pb(dp[y][1] - dp[y][0]);
				cnt[1] += dp[y][0];
			}
		}
		sort(all(a[1]));
		sort(all(a[0]));
		sort(all(a[2]));
		vector<LL> s = a[1];
		for(int j = 1; j < (int)s.size(); j++) {
			s[j] += s[j - 1];
		}
		for(int j = a[0].size(); j <= a[0].size() + a[1].size(); j++) {
			LL tmp = cnt[0] + cnt[1] + cnt[2];
			//cout << "!!!" << endl;
			tmp += a[1].size() + a[0].size() >= j + 1?  s[a[1].size() - j + a[0].size() - 1] : 0;
			//cout << "!!!" << endl;
			tmp += (LL)max((unsigned)j, a[0].size() + a[1].size() + a[2].size() - j) * t[v];
			if(v == 1) {
				dp[v][0] = min(dp[v][0], tmp);
			}else {
				if(h[v] >= h[fa[v]]) {
					if(j > a[0].size() + a[1].size() + a[2].size() - j) {
						dp[v][0] = min(dp[v][0], tmp);
					}else {
						dp[v][0] = min(dp[v][0], tmp + t[v]);
					}
				}
				if(h[v] <= h[fa[v]]) {
					if(j >= a[0].size() + a[1].size() + a[2].size() - j) {
						dp[v][1] = min(dp[v][1], tmp + t[v]);
					}else {
						dp[v][1] = min(dp[v][1], tmp);
					}
				}
				
			}
		}
	}
	cout << dp[1][0] << endl;
}