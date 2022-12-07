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
vector<int> e[N];
int dis[N];
void bfs(int v) {
	static vector<int> q;
	q.clear();
	q.pb(v);
	fill(dis + 1, dis + 1 + n, inf);
	dis[v] = 0;
	for(int op = 0; op < (int)q.size(); op++) {
		int v = q[op];
		for(int y : e[v]) {
			if(dis[y] > dis[v]) {
				dis[y] = dis[v] + 1;
				q.pb(y);
			}
		}
	}
	return;
}
bool calc() {
	int a, b, da, db;
	scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
	for(int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
		e[y].pb(x);
	}
	bfs(a);
	if(dis[b] <= da) {
		return true;
	}
	if(db <= da * 2) return true;
	int mx = a;
	for(int i = 1; i <= n; i++) {
	//	cout << i << ' ' << dis[i] << endl;
		if(dis[i] >= dis[mx]) mx = i;
	}
	//cout << mx << endl;
	bfs(mx);
	mx = *max_element(dis + 1, dis + n + 1);
	//cout << mx << endl;
	if(mx <= da * 2) return true;
	return false;
}
int main() {
	int t;
	scanf("%d", &t);
	for(int qq = 1; qq <= t; qq++) {
		printf("%s\n", calc() ? "Alice" : "Bob");
		
		for(int i = 1; i <= n; i++) e[i].clear();
	}
}