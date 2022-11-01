#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

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
const int N = 100005;
int n, ans, num, tot, h[N], d[N], dd[N], e[N<<1], pre[N<<1];
bool vis[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	vis[u]=1;
	for(int i=h[u]; i; i=pre[i]) if(d[e[i]]==2 && !vis[e[i]]) dfs(e[i]);
}
int main() {
	read(n);
	for(int i=1; i<n; ++i){
		static int x, y;
		read(x), read(y);
		add(x, y), add(y, x), ++d[x], ++d[y];
	}
	for(int i=1; i<=n; ++i) if(d[i]==1) dfs(i);
	memcpy(dd, d, sizeof d);
	for(int i=1; i<=n; ++i) if(vis[i]) for(int j=h[i]; j; j=pre[j]) --d[e[j]];
	for(int i=1; i<=n; ++i) if(dd[i]==3 && d[i]==1) for(int j=h[i]; j; j=pre[j]) --d[e[j]];
	int mx=0;
	for(int i=1; i<=n; ++i) mx=max(mx, d[i]);
	return puts(mx<=2?"Yes":"No"), 0;
}