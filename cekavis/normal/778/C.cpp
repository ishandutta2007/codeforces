#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>

using namespace std;
#define ll long long
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
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
const  int N = 300005;
int n, ass, cnt, tot, ans[N], siz[N], ch[N<<1][26];
int Merge(int x, int y){
	int z=++cnt;
	++tot;
	rep(i, 0, 25) if(!ch[x][i] || !ch[y][i]) ch[z][i]=ch[x][i]|ch[y][i]; else ch[z][i]=Merge(ch[x][i], ch[y][i]);
	return z;
}
void dfs(int u, int dep=1){
	siz[u]=1;
	int root=0; cnt=n;
	rep(i, 0, 25) if(ch[u][i]) dfs(ch[u][i], dep+1);
	rep(i, 0, 25) if(ch[u][i]) tot=0, root=Merge(root, ch[u][i]), ans[dep]+=tot;
}
int main() {
	read(n);
	rep(i, 2, n){
		static int x, y;
		static char z;
		read(x), read(y);
		while(isspace(z=read()));
		ch[x][z-'a']=y;
	}
	dfs(1);
	ass=1;
	rep(i, 2, n) ass=(ans[i]>ans[ass]?i:ass);
	return printf("%d\n%d", n-ans[ass], ass), 0;
}