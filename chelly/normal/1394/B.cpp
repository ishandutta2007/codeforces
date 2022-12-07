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
int n, m, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cd(int a, int b) {
	return a * (a - 1) / 2 + b - 1;
}
LL ban[99];
int ans = 0;
map<int, int> mp[N];
vector<pair<int, int> > e[N];
void dfs(int i, LL msk) {
	if(i == k + 1) {
		ans++;
		return;
	}
	int bg = cd(i, 1);
	int ed = cd(i, i);
	for(int j = bg; j <= ed; j++) {
		if(((msk >> j) & 1) == 0) {
			dfs(i + 1, msk | ban[j]);
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		e[x].pb({z, y});
	}

	for(int i = 1; i <= n; i++) {
		sort(all(e[i]));
		int _ = 1;
		for(auto tmp : e[i]) {
			int y = tmp.se;
			int z = tmp.fi;
		//	printf("%d %d %d %d %d\n", i, y, e[i].size(), _,cd(e[i].size(), _)); 
			mp[y][cd(e[i].size(), _)]++;
			_++;
		}
	}
	LL msk = 0;
	for(int i = 1; i <= n; i++) {
		for(auto tmp : mp[i]) {
			//printf("%d %d\n", tmp.fi, tmp.se);
			if(tmp.second >= 2) {
				msk |= 1ll << tmp.fi;
			}
			for(auto t1 : mp[i]) {
				if(tmp.fi != t1.fi) {
					ban[tmp.fi] |= 1ll << t1.fi;
					ban[t1.fi] |= 1ll << tmp.fi;
				}
			}
		}
	}
	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= i; j++) {
			for(int k = 1; k <= i; k++) {
				if(j != k) {
					ban[cd(i, j)] |= 1ll << cd(i, k);
				}
			}
		}
	}
	dfs(1, msk);
	cout << ans << endl;

}