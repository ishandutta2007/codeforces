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
const int N = 200005;
int n, q, top, ans[N], p[N], l[N], stk[N], mx[N], s[N];
struct query{
	int x, y, id;
	inline bool operator <(const query &rhs)const{ return x<rhs.x;}
} f[N];
int main() {
	read(n);
	rep(i, 1, n) read(p[i]), read(l[i]);
	read(q);
	rep(i, 1, q) read(f[i].x), read(f[i].y), f[i].id=i;
	sort(f+1, f+q+1);
	int j=q;
	for(int i=n-1; i; --i){
		if(l[i]+p[i]<p[i+1]) stk[++top]=i, mx[top]=l[i]+p[i], s[top]=s[top-1]+p[i+1]-mx[top];
		else{
			if(top && l[i]+p[i]>mx[top]) mx[top]=l[i]+p[i], s[top]=s[top-1]+p[stk[top]+1]-mx[top];
			// printf(":::%d %d\n", mx[top], p[stk[top]+1]);
			while(top && mx[top]>=p[stk[top]+1])
				if(--top) if(mx[top+1]>mx[top]) mx[top]=mx[top+1], s[top]=s[top-1]+p[stk[top]+1]-mx[top];
		}
		// printf(">>>%d %d %d %d %d\n", i, top, s[top-1], stk[1], stk[2]);
		while(f[j].x==i){
			int L=1, R=top, ass=top+1;
			while(L<=R){
				int mid=L+R>>1;
				if(stk[mid]<f[j].y) ass=mid, R=mid-1; else L=mid+1;
			}
			if(ass<=top) ans[f[j].id]=s[top]-s[ass-1];
			--j;
		}
	}
	rep(i, 1, q) print(ans[i]), print('\n');
	return flush(), 0;
}