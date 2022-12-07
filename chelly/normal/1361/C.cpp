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
const int N = 2048599;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> ans;
vector<pair<int, int>> e[N];
int a[N], b[N], rela[N], deg[N], siz[N], vst[N];
int getr(int x) {
	int p;
	for(p = x; p != rela[p]; p = rela[p]);
	int p1 = p;
	p = x;
	while(p != rela[p]) {
		int p2 = rela[p];
		rela[p] = p1;
		p = p2;
	}
	return p1;
}
int cur[N];
void dfs(int v) {
	for( ; cur[v] < (int)e[v].size(); cur[v]++) {
		int y = e[v][cur[v]].fi, i = e[v][cur[v]].se;
		if(vst[(i + 1) / 2]) continue;
		vst[(i + 1) / 2] = true;
		dfs(y);
		ans.pb(i);
		ans.pb(i % 2 == 0 ? i - 1 : i + 1);
	}
}
int main() {
	int n;
	scanf("%d", &n);
// = 1000000;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i], &b[i]);
//a[i] = gene() % (1 << 20);
//b[i] = gene() % (1 << 20);
	}
	for(int i = 20; i >= 0; i--) {
		if(i == 0) {
			printf("0\n");
			for(int i = 1; i <= n * 2; i++) printf("%d%c", i, i == n * 2 ? '\n' : ' ');
			return 0;
		}
		int msk = (1 << i) - 1;
		for(int j = 0; j <= msk; j++) {
			rela[j] = j;
			siz[j] = 0;
			deg[j] = 0;
		}
		//cout << i << endl;
		for(int j = 1; j <= n; j++) {
			deg[a[j] & msk]++;
			deg[b[j] & msk]++;
			int x = getr(a[j] & msk), y = getr(b[j] & msk);
			if(x != y) {
				rela[x] = y;
				siz[y] += siz[x];
			}
			siz[y]++;
		}
		//cout << i << endl;
		bool flag = true;
		int cnt = 0, bg = 0;
		for(int j = 0; j < (1 << i); j++) {
			if(deg[j] % 2 == 1) {
				flag = false;
			}
			if(rela[j] == j && siz[j] != 0) {
				cnt++;
				bg = j;
			}
		}
		//cout << flag << ' ' << cnt << endl;
		if(flag && cnt == 1) {
			for(int j = 1; j <= n; j++) {
				e[a[j] & msk].pb(make_pair(b[j] & msk, j * 2));
				e[b[j] & msk].pb(make_pair(a[j] & msk, j * 2 - 1));
			}
			dfs(bg);
			printf("%d\n", i);
			for(int i = 0; i < 2 * n; i++) printf("%d%c", ans[i], i == n * 2 - 1 ? '\n' : ' ');
			return 0;
		}
	}
//acerr << clock() << endl;
}