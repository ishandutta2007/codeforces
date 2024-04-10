#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<queue>

using namespace std;
#define ll long long
#define travel(i,x) for(int i=h[x];i;i=pre[i])

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
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh = obuf;
inline void print(char c) {
	if (ooh == obuf + OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh = obuf;
	*ooh++ = c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x == 0) print('0');
	else {
		if (x < 0) print('-'), x = -x;
		for (cnt = 0; x; x /= 10) buf[++cnt] = x % 10 + 48;
		while (cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }
const int N = 100005;
int n, m, k, num, cnt, h[N], belong[N], f[N], e[N<<1], pre[N<<1], w[N<<1];
ll ans, dis[N];
bool vis[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
struct edge{
	int x, y;
	ll z;
	inline bool operator <(const edge &rhs)const{ return z<rhs.z;}
} a[N];
inline void add(int x, int y, int z){ e[++num]=y, w[num]=z, pre[num]=h[x], h[x]=num;}
inline int find(int x){ return f[x]==x?x:f[x]=find(f[x]);}
inline void dij(){
	read(k);
	int u;
	for(int i=1; i<=n; ++i) dis[i]=1e18;
	for(int i=1; i<=k; ++i) read(u), q.push(make_pair(dis[u]=0, u)), belong[u]=u;
	pair<ll,int> tmp;
	while(!q.empty()) if(!vis[u=(tmp=q.top(), q.pop(), tmp.second)]){
		travel(i, u) if(dis[e[i]]>dis[u]+w[i]) belong[e[i]]=belong[u], q.push(make_pair(dis[e[i]]=dis[u]+w[i], e[i]));
		vis[u]=1;
	}
}
int main() {
	read(n), read(m);
	for(int i=1; i<=m; ++i){
		read(a[i].x), read(a[i].y), read(a[i].z);
		add(a[i].x, a[i].y, a[i].z), add(a[i].y, a[i].x, a[i].z);
	}
	dij();
	for(int i=1; i<=m; ++i) if(belong[a[i].x]!=belong[a[i].y]) a[++cnt].z=a[i].z+dis[a[i].x]+dis[a[i].y], a[cnt].x=belong[a[i].x], a[cnt].y=belong[a[i].y];
	sort(a+1, a+cnt+1);
	for(int i=1; i<=n; ++i) f[i]=i;
	for(int i=1; i<=cnt; ++i) if(find(a[i].x)!=find(a[i].y)){
		f[f[a[i].x]]=f[a[i].y];
		ans+=a[i].z;
	}
	return printf("%lld", ans+dis[1]), 0;
}