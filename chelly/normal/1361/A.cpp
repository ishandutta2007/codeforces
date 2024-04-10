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
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
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
template<const LL mod> struct MI{
	LL a;
	MI operator + (const MI & b) {
		MI res{a + b.a};
		if(res.a >= mod) res.a -= mod;
		return res;
	}
	MI operator - (const MI & b) {
		MI res{a - b.a};
		if(res.a <= 0) res.a += mod;
		return res;
	}
	MI operator * (const MI & b) {
		return MI{a * b.a % mod};
	}
	MI operator / (const MI & b) {
		return MI{a * fastpo(b.a, mod - 2, mod) % mod};
	}
};
const int N = 500033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> e[N];
int o[N], c[N], vst[N];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].pb(y);
		e[y].pb(x);

	}
	for(int i =1; i <= n; i++) {
		cin >> c[i];
		o[i] = i;
	}
	sort(o + 1, o + 1 + n, [&](int a, int b) {return c[a] < c[b];});
	for(int i = 1; i <= n; i++) {
		set<int> s;
		int v = o[i];
		for(int y : e[v]) {
			if(vst[y]) {
				s.insert(c[y]);
			}
		}
		vst[v] = 1;
		int res = -1;
		for(int j = 1; ; j++) {
			if(s.count(j) == 0) {
				res = j;
				break;
			}
		}
		if(res != c[v]) {
			printf("-1\n");
			exit(0);
		}
	}
	for(int i = 1; i <= n; i++) printf("%d%c", o[i], i == n ? '\n' : ' ');

}