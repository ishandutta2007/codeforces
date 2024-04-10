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
#include<cmath>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
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
const int N = 101;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int deg[N][N][26];
int cnt[N][N][26], sta[N][N][26];
vector<pair<int, int> > adj[N];
vector<int> go[N][N][26];
vector<int> q;
inline int code(int x, int y, int z) {
	return x * 26 * 101 + y * 26 + z;
}
inline void decode(int & x, int & y, int & z, int c) {
	z = c % 26;
	c /= 26;
	y = c % 101;
	c /= 101;
	x = c;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i(1); i <= m; i++) {
		int x, y, c;
		static char st[11];
		scanf("%d%d%s", &x, &y, st);
		c = st[0];
		adj[x].push_back({y, c - 'a'});
	}
	vector<int> q;
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= n; j++) {
			for(int k(0); k < 26; k++) {
				for(auto l : adj[i]) {
					int y = l.fi, c = l.se;
					if(c >= k) {
						go[j][y][c].pb(code(i, j, k));
						deg[i][j][k]++;
					}
				}
				if(deg[i][j][k] == 0) {
					//printf("%d %d %d\n", i, j, k);
					q.push_back(code(i, j, k));
					sta[i][j][k] = 0;
				}
			}
		}
	}
	for(int op(0); op < (int)q.size(); op++) {
		int i, j, k;
		decode(i, j, k, q[op]);
		for(int s : go[i][j][k]) {
			int x, y, l;
			decode(x, y, l, s);
			cnt[x][y][l] += sta[i][j][k] == 0;
			deg[x][y][l]--;
			if(0 == deg[x][y][l]) {
				sta[x][y][l] = cnt[x][y][l] ? 1 : 0;
				q.push_back(code(x, y, l));
			}
		}
	}
	for(int i(1); i <= n; i++) {
		for(int j(1); j <= n; j++) {
			printf("%c", sta[i][j][0] ? 'A' : 'B');
		}
		printf("\n");
	}
}