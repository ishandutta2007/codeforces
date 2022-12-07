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
const int N = 1111;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N];
set<int> pos[N];
int vst[N][N];
int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int, int> >  vec;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		vec.push_back(make_pair(a[i], i));
	}
	sort(vec.begin(), vec.end());
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(vec.begin(), vec.end(), make_pair(a[i], i)) - vec.begin() + 1;
	set<int> q;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		pos[a[i]].insert(i);
		for(int j = i + 1; j <= n; j++) {
			if(a[i] > a[j]) {
				cnt++;
				//printf("%d %d %d %d\n", i, j, a[i], a[j]);
				if(!vst[a[i]][a[j]]) {
					vst[a[i]][a[j]] = 1;
					if(a[i] == a[j] + 1) {
						q.insert(a[i]);
					}
				}else {
					//printf("-1\n");
					//exit(0);
				}
			}
		}
	}
	vector<pair<int, int > > ans;
	auto check = [&](int x) {
		bool ok = !pos[x].empty() && !pos[x - 1].empty() && *pos[x].begin() < *pos[x - 1].rbegin();
		if(ok && q.count(x) == 0) q.insert(x);
		else if(!ok && q.count(x) == 1) q.erase(x);
	};
	while(!q.empty()) {
		int v = *q.rbegin();
		int i = *pos[v].begin(), j = * pos[v - 1].rbegin();
		swap(a[i], a[j]);
		ans.pb(make_pair(i, j));
		pos[v].erase(i);
		pos[v - 1].erase(j);
		pos[v].insert(j);
		pos[v - 1].insert(i);
		check(v - 1);
		check(v);
		check(v + 1);
	}
//	cout << q.size() << ' ' << cnt << endl;
	if(ans.size() != cnt) {
		printf("-1\n");
		exit(0);
	}
	for(int i = 1; i < n; i++) assert(a[i] <= a[i + 1]);
	printf("%d\n", (int)ans.size());
	for(auto tmp : ans) {
		printf("%d %d\n", tmp.fi, tmp.se);
	}

}