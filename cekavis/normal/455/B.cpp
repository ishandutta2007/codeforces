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
const int N = 100005;
int n, k, cnt, ch[N][26];
bool f[N], g[N];
inline void ins(int &p, int c){ p=(ch[p][c]?ch[p][c]:ch[p][c]=++cnt);}
void dfs(int u){
	bool flag=0;
	rep(i, 0, 25) if(ch[u][i]) dfs(ch[u][i]), f[u]|=!f[ch[u][i]], g[u]|=!g[ch[u][i]], flag=1;
	g[u]|=!flag;
}
int main() {
	read(n), read(k), cnt=1;
	while(n--){
		static char ch;
		while(isspace(ch=read()));
		int p=1;
		ins(p, ch-'a');
		while(islower(ch=read())) ins(p, ch-'a');
	}
	dfs(1);
	if(f[1]) if(g[1]) puts("First");
	else puts(k&1?"First":"Second");
	else puts("Second");
	return 0;
}