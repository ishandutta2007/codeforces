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
int a[N];
vector<int> b[N];
int ans[N];
int main() {
	int t;
	scanf("%d", &t);
	for(int qq = 1; qq <= t; qq++) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		map<int, int> mp;
		int xx = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			mp[a[i]]++;
		}
		for(int i = 1; i <= n + 1; i++) {
			if(!mp.count(i)) xx = i;
		}
		set<pair<int, int> > st;
		for(auto tmp : mp) {
			st.insert(make_pair(tmp.se, tmp.fi));
		}
		for(int i = 0; i < x; i++) {
			auto tmp = *st.rbegin();
			st.erase(tmp);
			tmp.first--;
			b[tmp.se].pb(tmp.se);
			if(tmp.first) 
				st.insert(tmp);
		}
		/*for(auto tmp : st) {
			printf("!%d %d\n", tmp.fi, tmp.se);
		}*/
		bool flag = false;
		for(int i = 0; i <= n - y; i++) {
			if(st.empty() || st.rbegin()->first <= (n - x - i) / 2) {
				vector<int> v;
				for(auto tmp : st) {
					for(int i = 0; i < tmp.fi; i++) {
						v.pb(tmp.se);
					}
				}
				//cout << v.size() << ' ' << n - x - i << endl;
				for(int j = 0; j < (n - x - i); j++) {
					if(j < n - y - i) {
						b[v[j]].pb(xx);
					}else
					b[v[j]].pb(v[(j + ((n - x - i)) / 2) % ((n - x - i))]);
				}
				for(int i = 1; i <= n; i++) {
					assert(b[a[i]].size());
					ans[i] = b[a[i]].back();
					b[a[i]].pop_back();
				}
				printf("YES\n");
				for(int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
				flag = true;
				break;
			}
			if(i == n - y) break;
			auto tmp = *st.rbegin();
			st.erase(tmp);
			tmp.first--;
			b[tmp.se].pb(xx);
			if(tmp.first) 
				st.insert(tmp);
		}
		if(!flag) printf("NO\n");
		for(int i = 1; i <= n + 1; i++) b[i].clear();
	}
}