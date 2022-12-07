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
const int N = 100033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int dep[N], vst[N];
set<pair<int, int> > s[N];
vector<int> e[N];
bool ans[N];
int anc[N], o[N];
int cur[N];
int ins[N];
bool dfs(int v) {
	//cout << v << endl;
	vst[v] = true;
	ins[v] = true;
	for(int y : e[v]) {
		if(!vst[y]) {
			dep[y] = dep[v] + 1;
			if(!dfs(y)) return false;
		}else {
			if(ins[y] == false || dep[y] > dep[v]) {
				return false;
			}
		}
	}
	ins[v] = false;
	return true;
}
int _ = 0;
void d1(int v) {
	vst[v] = true;
	cur[dep[v]] = v;
	for(int y : e[v]) {
		if(!vst[y]) {
			dep[y] = dep[v] + 1;
			d1(y);
			if(s[v].size() < s[y].size()) {
				swap(s[v], s[y]);
			}
			for(auto tmp : s[y]) {
				s[v].insert(tmp);
			}
			s[y].clear();
		}else {
			//printf("%d->%d(%d->%d)\n", v, y, dep[v], dep[y]);
			s[v].insert(make_pair(dep[y], ++_));
		}
	}
	while(!s[v].empty() && s[v].rbegin()->first >= dep[v]) {
		s[v].erase(*s[v].rbegin());
	}
	anc[v] = -1;
	if(s[v].size() >= 2) {
		ans[v] = false;
	}else if(s[v].size() == 1) {
		anc[v] = cur[s[v].begin()->first];
	}
	
}
void d2(int v) {
	vst[v] = true;
	if(anc[v] != -1) {
		ans[v] &= ans[anc[v]];
	}
	for(int y : e[v]) {
		if(!vst[y]) {
			dep[y] = dep[v] + 1;
			d2(y);
		}
	}
}
void run() {

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].pb(y);
	}
	for(int i = 1; i <= n; i++) {
		o[i] = i;
		swap(o[i], o[gene() % i + 1]);
	}
	int LIM = 100;
	for(int j = 1; j <= min(LIM, n); j++) {
		int v = o[j];
		fill(ins + 1, ins + 1 + n, false);
		fill(vst + 1, vst + 1 + n, false);
		
		dep[v] = 1;
		if(dfs(v)) {
			//printf("??\n");
			fill(vst + 1, vst + 1 + n, false);
			fill(ans + 1, ans + 1 + n, true);
			d1(v);
			fill(vst + 1, vst + 1 + n, false);
			d2(v);
			int cnt = 0;
			for(int i = 1; i <= n; i++) cnt += ans[i];
			//cout << cnt << endl;
			for(int i = 1; i <= n; i++) s[i].clear();
			if(cnt * 5 < n) {
				printf("-1\n");
				//for(int i = 1; i <= n; i++) e[i].clear();
				return;
			}else {
				for(int i = 1 ; i <= n; i++) {
					if(ans[i]) {
						cnt--;
						printf("%d%c", i, cnt ? ' ' : '\n');
					}
				}
				//for(int i = 1; i <= n; i++) e[i].clear();
				return;
			}
		}
	}
	printf("-1\n");
}
int main() {
	int t;
	scanf("%d", &t);
	for(int qq = 1; qq <= t; qq++) {
		run();
	for(int i = 1; i <= n; i++) e[i].clear();
	//cout << endl;
	}
}