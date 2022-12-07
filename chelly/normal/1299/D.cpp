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

inline int fastpo(int x, int n, int mod) {
	int res(1);
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

const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
typedef unsigned int U;
int go[555][555], dirty[555][555];
int dp[100011][444];
void add(int & a, int b) {
	if((a += b) >= mod) {
		a -= mod;
	}
}
int par[N], pv[N], nv[N], near1[N], dep[N], vst[N], fa[N], de[N];
vector<pair<int, int> > e[N];
int main() {
	map<U, int> st;
	vector<U> q;
	q.push_back(1);
	st[0] = 0;
	for(int op = 0; op < (int)q.size(); op++) {
		U v = q[op];
//		cout << v << endl;
		for(int y = 0; y < 32; y++) {
			if(v >> y & 1u) {
				continue;	
			}
			U u = v;
			for(int z = 0; z < 32; z++) {
				if((v >> z & 1u)) {
					u |= 1u << (z ^ y); 
				}
			}
			if(st.count(u) == 0) {
				q.push_back(u);
				st[u] = q.size() - 1;
			}
		}
	}
//printf("%d\n", q.size());
	for(int i = 0; i < (int)q.size(); i++) {
		for(int j = 0; j < (int)q.size(); j++) {
			U x = q[i] | q[j];
			go[i][j] = -1;
			for(int k = 0; k < (int)q.size(); k++) {
				if((q[k] & x) != x) continue;
				if(go[i][j] == -1 || go[i][j] != -1 && q[k] < q[go[i][j]]) {
					go[i][j] = k;
				}
			}
			if(__builtin_popcount(q[i]) * __builtin_popcount(q[j]) != __builtin_popcount(q[go[i][j]])) {
				dirty[i][j] = 1;
			}
		}
	}
//	return 0;
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		e[x].push_back({y, z});
		e[y].push_back({x, z});
	}
	vst[1] = true;
	for(auto tmp : e[1]) {
		int y = tmp.fi;
		near1[y] = true;
		nv[y] = tmp.se;
		for(auto t1 : e[y]) {
			int z = t1.fi;
			if(near1[z]) {
				par[y] = z;
				par[z] = y;
				pv[y] = t1.se;
				pv[z] = t1.se;
			}
		}
	}
	
	vector<pair<U, int> > vec, tri;
	vector<int> haspar;
	for(auto tmp : e[1]) {
		int y = tmp.fi;
		if(vst[y]) continue;
		static vector<int> q;
		q.clear();
		q.push_back(y);
		dep[y] = 0;
		vst[y] = true;
		int d = 0;
		unsigned int sp = 0;
		for(int op = 0; op < (int)q.size(); op++) {
			int v = q[op];
			for(auto tmp : e[v]) {
				int u = tmp.fi, z = tmp.se;
				if(!vst[u]) {
					vst[u] = true;
					//printf("%d-> %d\n", v, u);
					dep[u] = dep[v] ^ z;
					fa[u] = v;
					q.push_back(u);
				}else {
					if(u == fa[v] || u == 1 || u > v) continue;
					//printf("%d %d %d %d\n", v, u, sp, dep[v] ^ dep[u] ^ z);
					d |= dirty[sp][dep[v] ^ dep[u] ^ z];
					if((dep[v] ^ dep[u] ^ z) == 0) {
						d = 1;
					}
					sp = go[sp][(dep[v] ^ dep[u] ^ z)];
				}
			}
		}
		vec.push_back({sp, d});
		haspar.push_back(par[y]);
		if((nv[y] ^ pv[y] ^ nv[par[y]]) == 0) d = 1;
		tri.push_back({go[sp][(nv[y] ^ pv[y] ^ nv[par[y]])], d | dirty[sp][(nv[y] ^ pv[y] ^ nv[par[y]])]});
		//printf("%u %d %d %u %d\n", vec.back().fi, vec.back().se, haspar.back(), tri.back().fi, tri.back().se);
	}
	dp[0][0] = 1;
	for(int i = 0; i < (int)vec.size(); i++) {
		for(int j = 0; j < (int)q.size(); j++) {
			if(haspar[i]) {
				if(tri[i].se == 0 && !dirty[j][tri[i].fi])
					add(dp[i + 1][go[j][tri[i].fi]], dp[i][j]);
				if(vec[i].se == 0 && !dirty[j][vec[i].fi])
					add(dp[i + 1][go[j][vec[i].fi]], 2 * dp[i][j] % mod);
				add(dp[i + 1][j], dp[i][j]);
			}else {
			//	if(i == 0 && j == 0) {
				//	printf("%d %d %d\n", vec[i].se, vec[i].fi, dirty[j][vec[i].fi]);
			//	}
				if(vec[i].se == 0 && !dirty[j][vec[i].fi])
					add(dp[i + 1][go[j][vec[i].fi]], dp[i][j]);
				add(dp[i + 1][j], dp[i][j]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < (int)q.size(); i++) {
		add(ans, dp[vec.size()][i]);
	}
	cout << ans << endl;
}