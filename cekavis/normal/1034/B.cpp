#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s == t ? t = (s = buf) + fread(buf, 1, IN_LEN, stdin), (s == t ? -1 : *s++) : *s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig = false, c = read(); !isdigit(c); c = read()) {
		if (c == '-') iosig = true;
		if (c == -1) return;
	}
	for (x = 0; isdigit(c); c = read()) x = ((x + (x << 2)) << 1) + (c ^ '0');
	if (iosig) x = -x;
}
const int N = 38, M = 36*36+5;
int n, m, cnt, ans, id[N][N], mat[M];
bool vis[M];
vector<int> e[M];
inline void add(int x, int y){ e[x].push_back(y), e[y].push_back(x);}
bool match(int u){
	for(int i:e[u]) if(!vis[i]){
		vis[i]=1;
		if(!mat[i] || match(mat[i])) return mat[i]=u, 1;
	}
	return 0;
}
int main() {
	read(n), read(m);
	if(n>m) swap(n, m);
	if(m<=36){
		// printf(">>%d %d\n", n, m);
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) id[i][j]=++cnt;
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j){
			if(i+3<=n) add(id[i][j], id[i+3][j]);
			if(i+2<=n && j+1<=m) add(id[i][j], id[i+2][j+1]);
			if(i+1<=n && j+2<=m) add(id[i][j], id[i+1][j+2]);
			if(j+3<=m) add(id[i][j], id[i][j+3]);
			if(i-1>0 && j+2<=m) add(id[i][j], id[i-1][j+2]);
			if(i-2>0 && j+1<=m) add(id[i][j], id[i-2][j+1]);
		}
		for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) if((i+j)&1){
			memset(vis, 0, sizeof vis);
			ans+=match(id[i][j])*2;
		}
		printf("%d", ans);
	}
	else{
		if(n==1) printf("%d", m-m%6+(m%6>3)*(m%6-3)*2);
		else printf("%lld", (ll)n*m-(n&m&1));
	}
	return 0;
}