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
const int N = 500033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > e[N];
int deg[N], d[N], ans[N], mn[N][2], vst[N];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d",&x, &y, &z);
		if(x == y) continue;
		e[y].pb({x, z});
		deg[x]++;
	}
	for(int i = 1; i <= n; i++) {
		mn[i][0] = mn[i][1] = inf;
	}
	vector<int> q;
	q.pb(n);
	deg[n] = -1;
	memset(d, -1, sizeof(d));
	vst[n] = 1;
	d[n] = 0;
	ans[n] = 0;
	for(int op = 0; op < (int)q.size(); op++) {
		int v = q[op];
		for(auto [y, z] : e[v]) {
			mn[y][z] = min(mn[y][z], d[v]);
			if(!vst[y] && mn[y][0] != inf && mn[y][1] != inf) {
				d[y] = max(mn[y][0], mn[y][1]) + 1;
				//printf("d[%d] = %d\n", y, d[y]);
				vst[y] = 1;
				if(mn[y][0] > mn[y][1]) ans[y] = 0;
				else ans[y] = 1;
				q.pb(y);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!vst[i]) {
			if(mn[i][0] > mn[i][1]) ans[i] = 0;
			else ans[i] = 1;
		}
	}
	printf("%d\n", d[1]);
	for(int i = 1; i <= n; i++) putchar(ans[i] + '0');
	putchar('\n');
}