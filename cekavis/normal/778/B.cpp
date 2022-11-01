#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<string>
#include<map>

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
const int N = 5005, M = 1005;
int n, m, x[N], y[N];
bool f[N];
char ans1[M], ans2[M], opt[N], s[N][M];
map<string,int> Name;
int main() {
	read(n), read(m);
	rep(i, 1, n){
		string na="";
		char tmp;
		while(isspace(tmp=read()));
		na=tmp;
		while(!isspace(tmp=read())) na+=tmp;
		Name[na]=i;
		read(), read(), read();
		if(isdigit(tmp=read())){
			s[i][1]=tmp;
			rep(j, 2, m) s[i][j]=read();
		}
		else{
			if(tmp!='?'){
				na=tmp;
				while(!isspace(tmp=read())) na+=tmp;
				x[i]=Name[na];
			}
			else tmp=read();
			opt[i]=read(), read(), read();
			if(opt[i]!='O') read();
			tmp=read();
			if(tmp!='?'){
				na=tmp;
				while(!isspace(tmp=read())) na+=tmp;
				y[i]=Name[na];
			}
		}
	}
	rep(i, 1, m){
		int cnt1=0, cnt0=0;
		f[0]=1;
		rep(j, 1, n) if(opt[j]){
			if(opt[j]=='O') f[j]=f[x[j]]|f[y[j]];
			else if(opt[j]=='X') f[j]=f[x[j]]^f[y[j]];
			else f[j]=f[x[j]]&f[y[j]];
			cnt1+=f[j];
		}
		else f[j]=s[j][i]-'0';
		f[0]=0;
		rep(j, 1, n) if(opt[j]){
			if(opt[j]=='O') f[j]=f[x[j]]|f[y[j]];
			else if(opt[j]=='X') f[j]=f[x[j]]^f[y[j]];
			else f[j]=f[x[j]]&f[y[j]];
			cnt0+=f[j];
		}
		else f[j]=s[j][i]-'0';
		ans1[i]='0'+(cnt1<cnt0);
		ans2[i]='0'+(cnt1>cnt0);
		// printf("%d %d\n", cnt1, cnt0);
	}
	rep(i, 1, m) print(ans1[i]);
	print('\n');
	rep(i, 1, m) print(ans2[i]);
	return flush(), 0;
}